#include "LexicalAnalyzer.hpp"

LexicalAnalyzer::LexicalAnalyzer(Buffer* charBuffer, vector<string, TableEntry*>* tokenVector, SymbolTable* symbolTable){

}

void LexicalAnalyzer::start(){
	while(!this->charBuffer->eob()){
		char c = this->charBuffer->getNextChar();
	}
}