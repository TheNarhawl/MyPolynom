#include <iostream>
#include <vector>
#include <antlr4-runtime.h>
#include "myPolyParserGrammarLexer.h"
#include "myPolyParserGrammarParser.h"
#include "myVisitor.h"
#include "clocale"
#include <iomanip>

using namespace antlr4;

static bool runTest1() {
    MyVisitor visitor;
    std::string polynomial = "2*x^2 + 5*x + 10";
    double expected = 28; // 2*(2)^2 + 5*2 + 10 = 28

    antlr4::ANTLRInputStream input(polynomial);
    myPolyParserGrammarLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    myPolyParserGrammarParser parser(&tokens);
    visitor.visit(parser.polynomial());

    visitor.setVariableValue("x", 2);
    double result = visitor.evaluatePolynomial();
    visitor.printTerms();

    std::cout << "Test 1: " << polynomial << " (with x = 2):" << std::endl;
    if (result == expected) {
        std::cout << "\033[32m[PASS]\033[0m (Got: " << result << ")\n" << std::endl;
        return true;
    }
    std::cout << "\033[31m[FAIL]\033[0m (Got: " << result << ", Expected: " << expected << ")\n" << std::endl;
    return false;
}

static bool runTest2() {
    MyVisitor visitor;
    std::string polynomial = "(5*x^2 + 4*y^5) * z";
    double expected = 692;

    antlr4::ANTLRInputStream input(polynomial);
    myPolyParserGrammarLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    myPolyParserGrammarParser parser(&tokens);
    visitor.visit(parser.polynomial());

    visitor.setVariableValue("x", 3);
    visitor.setVariableValue("y", 2);
    visitor.setVariableValue("z", 4);
    double result = visitor.evaluatePolynomial();
    visitor.printTerms();

    std::cout << "Test 2: " << polynomial << " (with x = 3, y = 2, z = 4):" << std::endl;
    if (result == expected) {
        std::cout << "\033[32m[PASS]\033[0m (Got: " << result << ")\n" << std::endl;
        return true;
    }
    std::cout << "\033[31m[FAIL]\033[0m (Got: " << result << ", Expected: " << expected << ")\n" << std::endl;
    return false;
}

static bool runTest3() {
    MyVisitor visitor;
    std::string polynomial = "-3*a^3 + 2*b^2 - c + 7";
    double expected = -4;

    antlr4::ANTLRInputStream input(polynomial);
    myPolyParserGrammarLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    myPolyParserGrammarParser parser(&tokens);
    visitor.visit(parser.polynomial());

    visitor.setVariableValue("a", 2);
    visitor.setVariableValue("b", 3);
    visitor.setVariableValue("c", 5);
    double result = visitor.evaluatePolynomial();
    visitor.printTerms();

    std::cout << "Test 3: " << polynomial << " (with a = 2, b = 3, c = 5):" << std::endl;
    if (result == expected) {
        std::cout << "\033[32m[PASS]\033[0m (Got: " << result << ")\n" << std::endl;
        return true;
    }
    std::cout << "\033[31m[FAIL]\033[0m (Got: " << result << ", Expected: " << expected << ")\n" << std::endl;
    return false;
}

static bool runTest4() {
    MyVisitor visitor;
    std::string polynomial = "(2*x + 3*y) * (x - y)";
    double expected = 7;

    antlr4::ANTLRInputStream input(polynomial);
    myPolyParserGrammarLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    myPolyParserGrammarParser parser(&tokens);
    visitor.visit(parser.polynomial());

    visitor.setVariableValue("x", 2);
    visitor.setVariableValue("y", 1);
    double result = visitor.evaluatePolynomial();
    visitor.printTerms();

    std::cout << "Test 4: " << polynomial << " (with x = 2, y = 1):" << std::endl;
    if (result == expected) {
        std::cout << "\033[32m[PASS]\033[0m (Got: " << result << ")\n" << std::endl;
        return true;
    }
    std::cout << "\033[31m[FAIL]\033[0m (Got: " << result << ", Expected: " << expected << ")\n" << std::endl;
    return false;
}

static bool runTest5() {
    MyVisitor visitor;
    std::string polynomial = "(4*x^3 - 2*y + 6) / 2 + z^2";
    double expected = 32;

    antlr4::ANTLRInputStream input(polynomial);
    myPolyParserGrammarLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    myPolyParserGrammarParser parser(&tokens);
    visitor.visit(parser.polynomial());

    visitor.setVariableValue("x", 2);
    visitor.setVariableValue("y", 3);
    visitor.setVariableValue("z", 4);
    double result = visitor.evaluatePolynomial();
    visitor.printTerms();

    std::cout << "Test 5: " << polynomial << " (with x = 2, y = 3, z = 4):\n";
    if (result == expected) {
        std::cout << "\033[32m[PASS]\033[0m (Got: " << result << ")\n" << std::endl;
        return true;
    }
    else {
        std::cout << "\033[31m[FAIL]\033[0m (Got: " << result << ", Expected: " << expected << ")\n" << std::endl;
        return false;
    }
}

static bool runTest6() {
    MyVisitor visitor;
    std::string polynomial = "-2*x^4 + 3*y^3 - 5*z + 12";
    double expected = 19;

    antlr4::ANTLRInputStream input(polynomial);
    myPolyParserGrammarLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    myPolyParserGrammarParser parser(&tokens);
    visitor.visit(parser.polynomial());

    visitor.setVariableValue("x", 1);
    visitor.setVariableValue("y", 2);
    visitor.setVariableValue("z", 3);
    double result = visitor.evaluatePolynomial();
    visitor.printTerms();

    std::cout << "Test 6: " << polynomial << " (with x = 1, y = 2, z = 3):\n";
    if (result == expected) {
        std::cout << "\033[32m[PASS]\033[0m (Got: " << result << ")\n" << std::endl;
        return true;
    }
    else {
        std::cout << "\033[31m[FAIL]\033[0m (Got: " << result << ", Expected: " << expected << ")\n" << std::endl;
        return false;
    }
}

static bool runTest7() {
    MyVisitor visitor;
    std::string polynomial = "3*a^2 - 2*b + 4*c^3 - d^2 + 5*e - 6*f + g^4";
    double expected = 23;

    antlr4::ANTLRInputStream input(polynomial);
    myPolyParserGrammarLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    myPolyParserGrammarParser parser(&tokens);
    visitor.visit(parser.polynomial());

    visitor.setVariableValue("a", 2);
    visitor.setVariableValue("b", 3);
    visitor.setVariableValue("c", 1);
    visitor.setVariableValue("d", 4);
    visitor.setVariableValue("e", 5);
    visitor.setVariableValue("f", 2);
    visitor.setVariableValue("g", 2);
    double result = visitor.evaluatePolynomial();
    visitor.printTerms();

    std::cout << "Test 7: " << polynomial << " (with a = 2, b = 3, c = 1, d = 4, e = 5, f = 2, g = 2):\n";
    if (result == expected) {
        std::cout << "\033[32m[PASS]\033[0m (Got: " << result << ")\n" << std::endl;
        return true;
    }
    else {
        std::cout << "\033[31m[FAIL]\033[0m (Got: " << result << ", Expected: " << expected << ")\n" << std::endl;
        return false;
    }
}

static bool runTest8() {
    MyVisitor visitor;

    // a = 10
    visitor.setVariableValue("a", 10);

    // b = a^2 + 15
    std::string polyB = "a^2 + 15";

    antlr4::ANTLRInputStream inputB(polyB);
    myPolyParserGrammarLexer lexerB(&inputB);
    antlr4::CommonTokenStream tokensB(&lexerB);
    myPolyParserGrammarParser parserB(&tokensB);
    visitor.visit(parserB.polynomial());

    double bValue = visitor.evaluatePolynomial();
    visitor.printTerms();

    std::cout << "Computed b = " << bValue << std::endl;

    std::string polyC = "a * " + std::to_string(bValue) + " / 10";
    antlr4::ANTLRInputStream inputC(polyC);
    myPolyParserGrammarLexer lexerC(&inputC);
    antlr4::CommonTokenStream tokensC(&lexerC);
    myPolyParserGrammarParser parserC(&tokensC);
    visitor.visit(parserC.polynomial());

    double result = visitor.evaluatePolynomial();
    visitor.printTerms();

    std::cout << "Test 8: " << polyC << ":\n";
    if (result == (10 * bValue / 10)) {
        std::cout << "\033[32m[PASS]\033[0m (Got: " << result << ")\n" << std::endl;
        return true;
    }
    else {
        std::cout << "\033[31m[FAIL]\033[0m (Got: " << result << ", Expected: " << (10 * bValue / 10) << ")\n" << std::endl;
        return false;
    }
}

static bool runTest9() {
    MyVisitor visitor;
    std::string polynomial = "((x + 1) * (y + 2)) + z";
    double expected = ((2 + 1) * (3 + 2)) + 4; // x = 2, y = 3, z = 4 → (3 * 5) + 4 = 15 + 4 = 19

    visitor.setVariableValue("x", 2);
    visitor.setVariableValue("y", 3);
    visitor.setVariableValue("z", 4);

    antlr4::ANTLRInputStream input(polynomial);
    myPolyParserGrammarLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    myPolyParserGrammarParser parser(&tokens);
    visitor.visit(parser.polynomial());

    double result = visitor.evaluatePolynomial();
    visitor.printTerms();

    std::cout << "Test 9: " << polynomial << " (x = 2, y = 3, z = 4):\n";
    if (std::abs(result - expected) < 1e-6) {
        std::cout << "\033[32m[PASS]\033[0m (Got: " << result << ")\n" << std::endl;
        return true;
    }
    else {
        std::cout << "\033[31m[FAIL]\033[0m (Got: " << result << ", Expected: " << expected << ")\n" << std::endl;
        return false;
    }
}

static bool runTest10() {
    MyVisitor visitor;

    std::string left = "3*a + 2*b";
    std::string right = "a*(3 + b)";

    visitor.setVariableValue("a", 2);
    visitor.setVariableValue("b", 5);

    antlr4::ANTLRInputStream inputLeft(left);
    myPolyParserGrammarLexer lexerLeft(&inputLeft);
    antlr4::CommonTokenStream tokensLeft(&lexerLeft);
    myPolyParserGrammarParser parserLeft(&tokensLeft);
    visitor.visit(parserLeft.polynomial());
    double leftVal = visitor.evaluatePolynomial();
    visitor.printTerms();

    antlr4::ANTLRInputStream inputRight(right);
    myPolyParserGrammarLexer lexerRight(&inputRight);
    antlr4::CommonTokenStream tokensRight(&lexerRight);
    myPolyParserGrammarParser parserRight(&tokensRight);
    visitor.visit(parserRight.polynomial());
    double rightVal = visitor.evaluatePolynomial();
    visitor.printTerms();

    std::cout << "Test 10: " << left << " == " << right << " (a=2, b=5):\n";
    if (std::abs(leftVal - rightVal) < 1e-6) {
        std::cout << "\033[32m[PASS]\033[0m (Got: " << leftVal << " == " << rightVal << ")\n" << std::endl;
        return true;
    }
    else {
        std::cout << "\033[31m[FAIL]\033[0m (Got: " << leftVal << " != " << rightVal << ")\n" << std::endl;
        return false;
    }
}

static bool runTest11() {
    MyVisitor visitor;
    std::string polynomial = "(x+y)*(x+y)*(x+y)";
    double expected = -8;

    antlr4::ANTLRInputStream input(polynomial);
    myPolyParserGrammarLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    myPolyParserGrammarParser parser(&tokens);
    visitor.visit(parser.polynomial());

    visitor.setVariableValue("x", 3);
    visitor.setVariableValue("y", -5);
    double result = visitor.evaluatePolynomial();
    visitor.printTerms();

    std::cout << "Test 11: " << polynomial << " (with x = 3, y = -5):\n";
    if (result == expected) {
        std::cout << "\033[32m[PASS]\033[0m (Got: " << result << ")\n" << std::endl;
        return true;
    }
    else {
        std::cout << "\033[31m[FAIL]\033[0m (Got: " << result << ", Expected: " << expected << ")\n" << std::endl;
        return false;
    }
}

static void runTests() {
    std::cout << "=== Running Polynomial Tests ===\n\n";
    std::vector<std::pair<std::string, bool>> results;
    results.emplace_back("Test 1", runTest1());
    results.emplace_back("Test 2", runTest2());
    results.emplace_back("Test 3", runTest3());
    /*results.emplace_back("Test 4", runTest4());
    results.emplace_back("Test 5", runTest5());
    results.emplace_back("Test 6", runTest6());
    results.emplace_back("Test 7", runTest7());
    results.emplace_back("Test 8", runTest8());
    results.emplace_back("Test 9", runTest9());
    results.emplace_back("Test 10", runTest10());
    results.emplace_back("Test 11", runTest11());*/

    std::cout << "=== Test Summary ===\n";
    for (const auto& [name, passed] : results) {
        std::cout << name << ": " << (passed ? "\033[32m[PASS]\033[0m" : "\033[31m[FAIL]\033[0m") << std::endl;
    }
}