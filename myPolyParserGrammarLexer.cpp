
// Generated from C:/ANTLR/myPolyParserGrammar.g4 by ANTLR 4.13.2


#include "myPolyParserGrammarLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct MyPolyParserGrammarLexerStaticData final {
  MyPolyParserGrammarLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MyPolyParserGrammarLexerStaticData(const MyPolyParserGrammarLexerStaticData&) = delete;
  MyPolyParserGrammarLexerStaticData(MyPolyParserGrammarLexerStaticData&&) = delete;
  MyPolyParserGrammarLexerStaticData& operator=(const MyPolyParserGrammarLexerStaticData&) = delete;
  MyPolyParserGrammarLexerStaticData& operator=(MyPolyParserGrammarLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mypolyparsergrammarlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<MyPolyParserGrammarLexerStaticData> mypolyparsergrammarlexerLexerStaticData = nullptr;

void mypolyparsergrammarlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (mypolyparsergrammarlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(mypolyparsergrammarlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MyPolyParserGrammarLexerStaticData>(
    std::vector<std::string>{
      "NUMBER", "VARIABLE", "PLUS", "MINUS", "MULT", "DIV", "POWER", "LPAREN", 
      "RPAREN", "EQUALS", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "", "'+'", "'-'", "'*'", "'/'", "'^'", "'('", "')'", "'='"
    },
    std::vector<std::string>{
      "", "NUMBER", "VARIABLE", "PLUS", "MINUS", "MULT", "DIV", "POWER", 
      "LPAREN", "RPAREN", "EQUALS", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,11,61,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,1,0,4,0,25,8,0,11,0,12,0,26,1,0,1,
  	0,4,0,31,8,0,11,0,12,0,32,3,0,35,8,0,1,1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,
  	1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,4,10,56,8,10,11,10,12,10,
  	57,1,10,1,10,0,0,11,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,
  	11,1,0,3,1,0,48,57,2,0,65,90,97,122,3,0,9,10,13,13,32,32,64,0,1,1,0,0,
  	0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,
  	0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,1,24,1,0,0,
  	0,3,36,1,0,0,0,5,38,1,0,0,0,7,40,1,0,0,0,9,42,1,0,0,0,11,44,1,0,0,0,13,
  	46,1,0,0,0,15,48,1,0,0,0,17,50,1,0,0,0,19,52,1,0,0,0,21,55,1,0,0,0,23,
  	25,7,0,0,0,24,23,1,0,0,0,25,26,1,0,0,0,26,24,1,0,0,0,26,27,1,0,0,0,27,
  	34,1,0,0,0,28,30,5,46,0,0,29,31,7,0,0,0,30,29,1,0,0,0,31,32,1,0,0,0,32,
  	30,1,0,0,0,32,33,1,0,0,0,33,35,1,0,0,0,34,28,1,0,0,0,34,35,1,0,0,0,35,
  	2,1,0,0,0,36,37,7,1,0,0,37,4,1,0,0,0,38,39,5,43,0,0,39,6,1,0,0,0,40,41,
  	5,45,0,0,41,8,1,0,0,0,42,43,5,42,0,0,43,10,1,0,0,0,44,45,5,47,0,0,45,
  	12,1,0,0,0,46,47,5,94,0,0,47,14,1,0,0,0,48,49,5,40,0,0,49,16,1,0,0,0,
  	50,51,5,41,0,0,51,18,1,0,0,0,52,53,5,61,0,0,53,20,1,0,0,0,54,56,7,2,0,
  	0,55,54,1,0,0,0,56,57,1,0,0,0,57,55,1,0,0,0,57,58,1,0,0,0,58,59,1,0,0,
  	0,59,60,6,10,0,0,60,22,1,0,0,0,5,0,26,32,34,57,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mypolyparsergrammarlexerLexerStaticData = std::move(staticData);
}

}

myPolyParserGrammarLexer::myPolyParserGrammarLexer(CharStream *input) : Lexer(input) {
  myPolyParserGrammarLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *mypolyparsergrammarlexerLexerStaticData->atn, mypolyparsergrammarlexerLexerStaticData->decisionToDFA, mypolyparsergrammarlexerLexerStaticData->sharedContextCache);
}

myPolyParserGrammarLexer::~myPolyParserGrammarLexer() {
  delete _interpreter;
}

std::string myPolyParserGrammarLexer::getGrammarFileName() const {
  return "myPolyParserGrammar.g4";
}

const std::vector<std::string>& myPolyParserGrammarLexer::getRuleNames() const {
  return mypolyparsergrammarlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& myPolyParserGrammarLexer::getChannelNames() const {
  return mypolyparsergrammarlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& myPolyParserGrammarLexer::getModeNames() const {
  return mypolyparsergrammarlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& myPolyParserGrammarLexer::getVocabulary() const {
  return mypolyparsergrammarlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView myPolyParserGrammarLexer::getSerializedATN() const {
  return mypolyparsergrammarlexerLexerStaticData->serializedATN;
}

const atn::ATN& myPolyParserGrammarLexer::getATN() const {
  return *mypolyparsergrammarlexerLexerStaticData->atn;
}




void myPolyParserGrammarLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  mypolyparsergrammarlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(mypolyparsergrammarlexerLexerOnceFlag, mypolyparsergrammarlexerLexerInitialize);
#endif
}
