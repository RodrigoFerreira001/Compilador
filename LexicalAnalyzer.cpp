#include "LexicalAnalyzer.hpp"

LexicalAnalyzer::LexicalAnalyzer(Buffer* charBuffer, vector<string, TableEntry*>* tokenVector, SymbolTable* symbolTable){

}

void LexicalAnalyzer::start(){

	int state = 0;
	string lexeme;

	while(!this->charBuffer->eob()){
		switch (state) {
			case 0:
				char c = this->charBuffer->getNextChar();

				if(c == '<') state = 1;
				else if(c == '>') state = 3;
				else if(c == '=') state = 7;
				else if(c == '!') state = 10;
				else if(c == '(') state = 12;
				else if(c == ')') state = 13;
				else if(c == '{') state = 14;
				else if(c == '}') state = 15;
				else if(c == ',') state = 16;
				else if(c == ';') state = 17;
				else if(c == '|') state = 18;
				else if(c == '&') state = 20;
				else if(c == '+') state = 22;
				else if(c == '-') state = 23;
				else if(c == '*') state = 24;
				else if(c == '/') state = 25;
				else if(c => 'a' && c <= 'z' || c => 'A' && c <= 'Z') state = 26;
				else if(c => '0' && c <= '9') state = 28;

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

			case 11:
				break;

			case 12:
				break;

			case 13:
				break;

			case 14:
				break;

			case 15:
				break;

			case 16:
				break;

			case 17:
				break;

			case 18:
				break;

			case 19:
				break;

			case 20:
				break;

			case 21:
				break;

			case 22:
				break;

			case 23:
				break;

			case 24:
				break;

			case 25:
				break;

			case 26:
				break;

			case 27:
				break;

			case 28:
				break;

			case 29:
				break;

			case 30:
				break;

			case 31:
				break;

			case 32:
				break;
		}
	}
}
