
// Generated from C:/ANTLR/myPolyParserGrammar.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  myPolyParserGrammarLexer : public antlr4::Lexer {
public:
  enum {
    NUMBER = 1, VARIABLE = 2, PLUS = 3, MINUS = 4, MULT = 5, DIV = 6, POWER = 7, 
    LPAREN = 8, RPAREN = 9, EQUALS = 10, WS = 11
  };

  explicit myPolyParserGrammarLexer(antlr4::CharStream *input);

  ~myPolyParserGrammarLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

