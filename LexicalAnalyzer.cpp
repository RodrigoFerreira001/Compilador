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
					state = 0;
				}else
				if(c == ')'){
					TableEntry* tableEntry = new TableEntry(string(")"),"RBRACKET",0,0);
					Token token("RBRACKET", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == '{'){
					TableEntry* tableEntry = new TableEntry(string("{"),"LBRACE",0,0);
					Token token("LBRACE", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == '}'){
					TableEntry* tableEntry = new TableEntry(string("}"),"RBRACE",0,0);
					Token token("RBRACE", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == ','){
					TableEntry* tableEntry = new TableEntry(string(","),"COMMA",0,0);
					Token token("COMMA", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else if(c == ';'){
					TableEntry* tableEntry = new TableEntry(string(";"),"PCOMMA",0,0);
					Token token("PCOMMA", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == '|'){
					state = 5;
				}else
				if(c == '&'){
					state = 6;
				}else
				if(c == '+'){
					TableEntry* tableEntry = new TableEntry(string("+"),"PLUS",0,0);
					Token token("PLUS", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == '-'){
					TableEntry* tableEntry = new TableEntry(string("-"),"MINUS",0,0);
					Token token("MINUS", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == '*'){
					TableEntry* tableEntry = new TableEntry(string("*"),"PLUS",0,0);
					Token token("PLUS", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == '/'){
					TableEntry* tableEntry = new TableEntry(string("/"),"DIV",0,0);
					Token token("DIV", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
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
					TableEntry* tableEntry = new TableEntry(string("<="),"LE",0,0);
					Token token("LE", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else{
					TableEntry* tableEntry = new TableEntry(string("<"),"LT",0,0);
					Token token("LT", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
					//MOVER O CURSOR DO BUFFER PARA TRÁS
				}
				break;

			case 2:
				char c = this->charBuffer->getNextChar();
				if (c == '='){
					TableEntry* tableEntry = new TableEntry(string(">="),"GE",0,0);
					Token token("GE", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else{
					TableEntry* tableEntry = new TableEntry(string(">"),"GT",0,0);
					Token token("GT", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
					//MOVER O CURSOR DO BUFFER PARA TRÁS
				}
				break;

			case 3:
				char c = this->charBuffer->getNextChar();
				if (c == '='){
					TableEntry* tableEntry = new TableEntry(string("=="),"EQUAL",0,0);
					Token token("EQUAL", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else{
					TableEntry* tableEntry = new TableEntry(string("="),"ATTR",0,0);
					Token token("ATTR", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
					//MOVER O CURSOR DO BUFFER PARA TRÁS
				}
				break;

			case 4:
				char c = this->charBuffer->getNextChar();
				if (c == '!'){
					TableEntry* tableEntry = new TableEntry(string("!="),"NE",0,0);
					Token token("NE", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else{
					cout << "ERROR : character expected " << endl;
					// REVER COUT
					exit(EXIT_FAILURE);
				}
				break;

			case 5:
				char c = this->charBuffer->getNextChar();
				if (c == '|'){
					TableEntry* tableEntry = new TableEntry(string("||"),"OR",0,0);
					Token token("OR", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else{
					cout << "ERROR : character expected " << endl;
					// REVER COUT
					exit(EXIT_FAILURE);
				}
				break;

			case 6:
				char c = this->charBuffer->getNextChar();
				if (c == '&'){
					TableEntry* tableEntry = new TableEntry(string("&&"),"AND",0,0);
					Token token("AND", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else{
					cout << "ERROR : character expected " << endl;
					// REVER COUT
					exit(EXIT_FAILURE);
				}
				break;

			case 7:
				char c = this->charBuffer->getNextChar();
				if (c => 'a' && c <= 'z' || c => 'A' && c <= 'Z' || c => '0' && c <= '9'){
					lexeme.push_back(c);
					state = 7;
				}else{
					TableEntry* tableEntry = new TableEntry(string("("),"ID",this->charBuffer->getNumLines,0);
					// VERIFICAR O MÉTODO CERTO
					Token token("ID", tableEntry);
					this->tokenVector->push_back(token);
					lexeme.clear();
					//MOVER O CURSOR DO BUFFER PARA TRÁS
				}
				break;

			case 8:
				char c = this->charBuffer->getNextChar();
				if (c => '0' && c <= '9'){
					lexeme.push_back(c);
					state = 8;
				}else if (c == '.'){

				}else{
					float
					TableEntry* tableEntry = new TableEntry(string("("),"INT",this->charBuffer->getNumLines,stringstream str(lexema));
					// VERIFICAR O MÉTODO CERTO
					Token token("ID", tableEntry);
					this->tokenVector->push_back(token);
					lexeme.clear();
					//MOVER O CURSOR DO BUFFER PARA TRÁS
				}
				break;

			case 9:
				break;

			case 10:
				break;


		}
	}
}
