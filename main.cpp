#include <iostream>
#include "clocale"
#include "myTests.h"
#include "httplib.h"
#include "nlohmann/json.hpp"

#include "antlr4-runtime.h"
#include "myPolyParserGrammarLexer.h"
#include "myPolyParserGrammarParser.h"
#include "MyVisitor.h"

using namespace httplib;
using json = nlohmann::json;

int main() {
    setlocale(LC_ALL, "Russiаn");
    runTests();

    Server svr;

    svr.set_pre_routing_handler([](const Request& req, Response& res) {
        res.set_header("Access-Control-Allow-Origin", "*");
        res.set_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
        res.set_header("Access-Control-Allow-Headers", "Content-Type");

        if (req.method == "OPTIONS") {
            res.status = 204;
            return Server::HandlerResponse::Handled;
        }

        return Server::HandlerResponse::Unhandled;
        });


    svr.Get("/ping", [](const Request&, Response& res) {
        json j = { {"status", "ok"}, {"message", "pong"} };
        res.set_content(j.dump(2), "application/json");
        });

    svr.Post("/evaluate", [](const Request& req, Response& res) {
        try {
            json req_json = json::parse(req.body);
            std::string poly = req_json.at("polynomial").get<std::string>();
            json variables = req_json.value("variables", json::object());

            antlr4::ANTLRInputStream input(poly);
            myPolyParserGrammarLexer lexer(&input);
            antlr4::CommonTokenStream tokens(&lexer);
            myPolyParserGrammarParser parser(&tokens);
            MyVisitor visitor;

            visitor.visit(parser.polynomial());

            for (auto& [var, val] : variables.items()) {
                visitor.setVariableValue(var, val.get<double>());
            }

            double result = visitor.evaluatePolynomial();
            auto terms = visitor.getCurrentPolynomial().getTerms();

            json terms_json = json::array();
            for (const auto& term : terms) {
                json term_json;
                term_json["coefficient"] = term.coefficient;

                json vars_json = json::object();
                for (const auto& [var, power] : term.variables) {
                    vars_json[var] = power;
                }
                term_json["variables"] = vars_json;
                term_json["string_repr"] = visitor.termToString(term);

                terms_json.push_back(term_json);
            }

            json parse_trace = json::array();
            for (const auto& node : visitor.parseTrace) {
                parse_trace.push_back(visitor.parseNodeToJson(node));
            }

            json response = {
                {"input", poly},
                {"terms", terms_json},
                {"result", result},
                {"parse_trace", parse_trace}
            };

            res.set_content(response.dump(4), "application/json");
        }
        catch (const std::exception& e) {
            json error = { {"error", e.what()} };
            res.status = 400;
            res.set_content(error.dump(2), "application/json");
        }
        });

    std::cout << "Server running at http://localhost:8080/ping\n";
    svr.listen("0.0.0.0", 8080);

    return 0;
}