
// Generated from C:/ANTLR/myPolyParserGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "myPolyParserGrammarParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by myPolyParserGrammarParser.
 */
class  myPolyParserGrammarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by myPolyParserGrammarParser.
   */
    virtual std::any visitPolynomial(myPolyParserGrammarParser::PolynomialContext *context) = 0;

    virtual std::any visitExpression(myPolyParserGrammarParser::ExpressionContext *context) = 0;

    virtual std::any visitTerm(myPolyParserGrammarParser::TermContext *context) = 0;

    virtual std::any visitFactor(myPolyParserGrammarParser::FactorContext *context) = 0;

    virtual std::any visitVariable(myPolyParserGrammarParser::VariableContext *context) = 0;


};

