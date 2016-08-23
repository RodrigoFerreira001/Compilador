#include "LexicalAnalyzer.hpp"

LexicalAnalyzer::LexicalAnalyzer(Buffer* charBuffer, vector<Token>* tokenVector, SymbolTable* symbolTable){
	this->charBuffer = charBuffer;
	this->tokenVector = tokenVector;
	this->symbolTable = symbolTable;
}

void LexicalAnalyzer::start(){

	int state = 0;
	string lexeme;

	while(!this->charBuffer->eob()){
		switch (state) {
			case 0:
				char c = this->charBuffer->getNextChar();

				if(c == '<'){
					state = 1;
				}else
				if(c == '>'){
					state = 2;
				}else
				if(c == '='){
					state = 3;
				}else
				if(c == '!'){
					state = 4;
				}else
				if(c == '('){
					TableEntry* tableEntry = new TableEntry(string("("),"LBRACKET",0,0);
					Token token("LBRACKET", tableEntry);
					this->tokenVector->push_back(token);
				}else
				if(c == ')'){
					
				}else
				if(c == '{'){
					
				}else
				if(c == '}'){
					
				}else
				if(c == ','){
					
				}else if(c == ';'){
					
				}else
				if(c == '|'){
					state = 5;
				}else
				if(c == '&'){
					state = 6;
				}else
				if(c == '+'){
					
				}else
				if(c == '-'){
					
				}else
				if(c == '*'){
					
				}else
				if(c == '/'){
					
				}else
				if(c => 'a' && c <= 'z' || c => 'A' && c <= 'Z'){
					state = 7;
				}else
				if(c => '0' && c <= '9'){
					state = 8;
				}

				lexeme.push_back(c);
				break;

			case 1:
				char c = this->charBuffer->getNextChar();
				if (c == '='){
					state = 2;

				}
				break;

			case 2:
				break;

			case 3:
				break;

			case 4:
				break;

			case 5:
				break;

			case 6:
				break;

			case 7:
				break;

			case 8:
				break;

			case 9:
				break;

			case 10:
				break;


		}
	}
}
