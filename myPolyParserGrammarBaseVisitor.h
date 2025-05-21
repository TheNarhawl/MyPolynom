
// Generated from C:/ANTLR/myPolyParserGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "myPolyParserGrammarVisitor.h"


/**
 * This class provides an empty implementation of myPolyParserGrammarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  myPolyParserGrammarBaseVisitor : public myPolyParserGrammarVisitor {
public:

  virtual std::any visitPolynomial(myPolyParserGrammarParser::PolynomialContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(myPolyParserGrammarParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(myPolyParserGrammarParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor(myPolyParserGrammarParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable(myPolyParserGrammarParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }


};

