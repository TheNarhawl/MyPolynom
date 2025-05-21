#pragma once
#include "antlr4-runtime.h"
#include "myPolyParserGrammarBaseVisitor.h"
#include "Polynomial.h"
#include <iostream>
#include <map>
#include <unordered_map>

#include "httplib.h"
#include "nlohmann/json.hpp"

using namespace httplib;
using json = nlohmann::json;

class MyVisitor : public myPolyParserGrammarBaseVisitor {
private:
    Polynomial currentPolynomial;
    double currentCoefficient = 1.0;
    bool isNegative = false;
    bool divideMode = false;
    Polynomial::Term currentTerm;
    std::unordered_map<std::string, double> variableValues;


public:
    struct ParseNode {
        std::string type;
        std::string text;
        std::vector<ParseNode> children;
    };

    std::vector<ParseNode> parseTrace;
    ParseNode currentNode;

    std::string termToString(const Polynomial::Term& term) const {
        std::stringstream ss;

        if (term.coefficient != 1.0 || term.variables.empty()) {
            if (term.coefficient == -1.0 && !term.variables.empty()) {
                ss << "-";
            }
            else {
                ss << term.coefficient;
            }
        }

        for (const auto& [var, power] : term.variables) {
            ss << "*" << var;
            if (power != 1.0) {
                ss << "^" << power;
            }
        }

        return ss.str();
    }

    const Polynomial& getCurrentPolynomial() const {
        return currentPolynomial;
    }

    void setVariableValue(const std::string& name, double value) {
        variableValues[name] = value;
    }

    std::any visitPolynomial(myPolyParserGrammarParser::PolynomialContext* ctx) override {
        ParseNode node;
        node.type = "polynomial";
        node.text = ctx->getText();

        std::cout << "[visitPolynomial] " << ctx->getText() << std::endl;
        currentPolynomial.clear();
        isNegative = false;
        divideMode = false;
        currentTerm = Polynomial::Term();

        auto result = visitChildren(ctx);

        parseTrace.push_back(node);
        return result;
    }

    std::any visitExpression(myPolyParserGrammarParser::ExpressionContext* ctx) override {
        ParseNode node;
        node.type = "expression";
        node.text = ctx->getText();

        std::cout << "[visitExpression] " << ctx->getText() << std::endl;

        for (size_t i = 0; i < ctx->children.size(); i++) {
            auto child = ctx->children[i];
            if (auto op = dynamic_cast<antlr4::tree::TerminalNode*>(child)) {
                if (op->getSymbol()->getType() == myPolyParserGrammarParser::MINUS) {
                    isNegative = !isNegative;
                }
                ParseNode opNode;
                opNode.type = "operator";
                opNode.text = op->getText();
                node.children.push_back(opNode);
            }
            else {
                visit(child);
            }
        }

        parseTrace.push_back(node);
        return nullptr;
    }

    std::any visitTerm(myPolyParserGrammarParser::TermContext* ctx) override {
        ParseNode node;
        node.type = "term";
        node.text = ctx->getText();

        std::cout << "[visitTerm] " << ctx->getText() << std::endl;

        double termCoeff = isNegative ? -1.0 : 1.0;
        isNegative = false;

        std::vector<std::pair<Polynomial, bool>> polynomials;
        auto factors = ctx->factor();

        for (size_t i = 0; i < factors.size(); ++i) {
            std::cout << "    [visitTerm] Processing factor: " << factors[i]->getText() << std::endl;

            ParseNode factorNode;
            factorNode.type = "factor_processing";
            factorNode.text = factors[i]->getText();
            node.children.push_back(factorNode);

            Polynomial factorPoly;
            if (factors[i]->expression()) {
                auto savedPoly = currentPolynomial;
                currentPolynomial = Polynomial();
                visit(factors[i]);
                factorPoly = currentPolynomial;
                currentPolynomial = savedPoly;
            }
            else if (factors[i]->NUMBER()) {
                double num = std::stod(factors[i]->NUMBER()->getText());
                Polynomial::Term numberTerm(num);
                factorPoly.addTerm(numberTerm);
            }
            else {
                currentTerm = Polynomial::Term();
                visit(factors[i]);
                factorPoly.addTerm(currentTerm);
            }

            bool isDiv = false;
            if (i > 0) {
                size_t opIndex = i - 1;
                if (opIndex < ctx->children.size()) {
                    auto opNode = ctx->children[2 * opIndex + 1];
                    std::string opText = opNode->getText();
                    isDiv = (opText == "/");
                }
            }
            polynomials.push_back({ factorPoly, isDiv });
        }

        if (termCoeff != 1.0) {
            Polynomial coeffPoly;
            coeffPoly.addTerm(Polynomial::Term(termCoeff));
            polynomials.insert(polynomials.begin(), { coeffPoly, false });
        }

        Polynomial result;
        result.addTerm(Polynomial::Term(1.0));

        for (const auto& [poly, isDiv] : polynomials) {
            if (isDiv) {
                result = result.divide(poly);
            }
            else {
                result = result.multiply(poly);
            }
        }

        for (const auto& term : result.getTerms()) {
            currentPolynomial.addTerm(term);
        }

        parseTrace.push_back(node);
        return nullptr;
    }

    std::any visitFactor(myPolyParserGrammarParser::FactorContext* ctx) override {
        ParseNode node;
        node.type = "factor";
        node.text = ctx->getText();

        std::cout << "[visitFactor] " << ctx->getText() << std::endl;

        if (ctx->MINUS()) {
            currentTerm.coefficient *= -1;
            ParseNode opNode;
            opNode.type = "operator";
            opNode.text = "-";
            node.children.push_back(opNode);
        }

        if (ctx->NUMBER()) {
            double num = std::stod(ctx->NUMBER()->getText());
            currentTerm.coefficient *= num;
            ParseNode numNode;
            numNode.type = "number";
            numNode.text = ctx->NUMBER()->getText();
            node.children.push_back(numNode);
        }

        parseTrace.push_back(node);
        return visitChildren(ctx);
    }

    std::any visitVariable(myPolyParserGrammarParser::VariableContext* ctx) override {
        ParseNode node;
        node.type = "variable";
        node.text = ctx->getText();

        std::string varName = ctx->VARIABLE()->getText();
        double exponent = 1.0;

        if (ctx->POWER()) {
            exponent = std::stod(ctx->NUMBER()->getText());
            ParseNode powerNode;
            powerNode.type = "power";
            powerNode.text = ctx->NUMBER()->getText();
            node.children.push_back(powerNode);
        }

        currentTerm.variables[varName] = exponent;

        parseTrace.push_back(node);
        return nullptr;
    }

    json parseNodeToJson(const ParseNode& node) const {
        json j;
        j["type"] = node.type;
        j["text"] = node.text;

        if (!node.children.empty()) {
            json children = json::array();
            for (const auto& child : node.children) {
                children.push_back(parseNodeToJson(child));
            }
            j["children"] = children;
        }

        return j;
    }

    void printTerms() {
        currentPolynomial.print();
    }

    double evaluatePolynomial() {
        return currentPolynomial.evaluate(variableValues);
    }

    std::vector<std::string> getTermStrings() const {
        std::vector<std::string> result;
        for (const auto& term : currentPolynomial.getTerms()) {
            result.push_back(termToString(term));
        }
        return result;
    }
};
