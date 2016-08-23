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
					TableEntry* tableEntry = new TableEntry("(","LBRACKET",0,0);
					Token token("LBRACKET", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == ')'){
					TableEntry* tableEntry = new TableEntry(")","RBRACKET",0,0);
					Token token("RBRACKET", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == '{'){
					TableEntry* tableEntry = new TableEntry("{","LBRACE",0,0);
					Token token("LBRACE", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == '}'){
					TableEntry* tableEntry = new TableEntry("}","RBRACE",0,0);
					Token token("RBRACE", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == ','){
					TableEntry* tableEntry = new TableEntry(",","COMMA",0,0);
					Token token("COMMA", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else if(c == ';'){
					TableEntry* tableEntry = new TableEntry(";","PCOMMA",0,0);
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
					TableEntry* tableEntry = new TableEntry("+","PLUS",0,0);
					Token token("PLUS", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == '-'){
					TableEntry* tableEntry = new TableEntry("-","MINUS",0,0);
					Token token("MINUS", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == '*'){
					TableEntry* tableEntry = new TableEntry("*","PLUS",0,0);
					Token token("PLUS", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == '/'){
					TableEntry* tableEntry = new TableEntry("/","DIV",0,0);
					Token token("DIV", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c => 'a' && c <= 'z' || c => 'A' && c <= 'Z'){
					state = 7;
					lexeme.push_back(c);
				}else
				if(c => '0' && c <= '9'){
					state = 8;
					lexeme.push_back(c);
				}


				break;

			case 1:
				char c = this->charBuffer->getNextChar();
				if (c == '='){
					TableEntry* tableEntry = new TableEntry("<=","LE",0,0);
					Token token("LE", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else{
					TableEntry* tableEntry = new TableEntry("<","LT",0,0);
					Token token("LT", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
					//MOVER O CURSOR DO BUFFER PARA TRÁS
				}
				break;

			case 2:
				char c = this->charBuffer->getNextChar();
				if (c == '='){
					TableEntry* tableEntry = new TableEntry(">=","GE",0,0);
					Token token("GE", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else{
					TableEntry* tableEntry = new TableEntry(">","GT",0,0);
					Token token("GT", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
					//MOVER O CURSOR DO BUFFER PARA TRÁS
				}
				break;

			case 3:
				char c = this->charBuffer->getNextChar();
				if (c == '='){
					TableEntry* tableEntry = new TableEntry("==","EQUAL",0,0);
					Token token("EQUAL", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else{
					TableEntry* tableEntry = new TableEntry("=","ATTR",0,0);
					Token token("ATTR", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
					//MOVER O CURSOR DO BUFFER PARA TRÁS
				}
				break;

			case 4:
				char c = this->charBuffer->getNextChar();
				if (c == '='){
					TableEntry* tableEntry = new TableEntry("!=","NE",0,0);
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
					TableEntry* tableEntry = new TableEntry("||","OR",0,0);
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
					TableEntry* tableEntry = new TableEntry("&&","AND",0,0);
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
					//MOVER O CURSOR DO BUFFER PARA TRÁS
					if(lexeme == "int"){
						TableEntry* tableEntry = new TableEntry(lexeme,"INT",0,0);
						// VERIFICAR O MÉTODO CERTO
						Token token("INT", tableEntry);
						this->tokenVector->push_back(token);
						lexeme.clear();
					}else if(lexeme == "float"){
						TableEntry* tableEntry = new TableEntry(lexeme,"FLOAT",0,0);
						// VERIFICAR O MÉTODO CERTO
						Token token("FLOAT", tableEntry);
						this->tokenVector->push_back(token);
						lexeme.clear();
					}else if(lexeme == "if"){
						TableEntry* tableEntry = new TableEntry(lexeme,"IF",0,0);
						// VERIFICAR O MÉTODO CERTO
						Token token("IF", tableEntry);
						this->tokenVector->push_back(token);
						lexeme.clear();
					}else if(lexeme == "else"){
						TableEntry* tableEntry = new TableEntry(lexeme,"ELSE",0,0);
						// VERIFICAR O MÉTODO CERTO
						Token token("ELSE", tableEntry);
						this->tokenVector->push_back(token);
						lexeme.clear();
					}else if(lexeme == "while"){
						TableEntry* tableEntry = new TableEntry(lexeme,"WHILE",0,0);
						// VERIFICAR O MÉTODO CERTO
						Token token("WHILE", tableEntry);
						this->tokenVector->push_back(token);
						lexeme.clear();
					}else if(lexeme == "read"){
						TableEntry* tableEntry = new TableEntry(lexeme,"READ",0,0);
						// VERIFICAR O MÉTODO CERTO
						Token token("READ", tableEntry);
						this->tokenVector->push_back(token);
						lexeme.clear();
					}else if(lexeme == "print"){
						TableEntry* tableEntry = new TableEntry(lexeme,"PRINT",0,0);
						// VERIFICAR O MÉTODO CERTO
						Token token("PRINT", tableEntry);
						this->tokenVector->push_back(token);
						lexeme.clear();
					}else {
						TableEntry* tableEntry = new TableEntry(lexeme,"ID",this->charBuffer->getNumLines,0);
						// VERIFICAR O MÉTODO CERTO
						Token token("ID", tableEntry);
						this->tokenVector->push_back(token);
						this->hashMap->insertEntry(tableEntry);
						lexeme.clear();
					}

				}
				break;

			case 8:
				char c = this->charBuffer->getNextChar();
				if (c => '0' && c <= '9'){
					lexeme.push_back(c);
					state = 8;
				}else if (c == '.'){
					lexeme.push_back(c);
					state = 9;
				}else{
					float stringvalue;
					stringstream str(lexema);
					str >> stringvalue;
					TableEntry* tableEntry = new TableEntry(lexeme,"NUMBER",this->charBuffer->getNumLines,stringvalue);
					// VERIFICAR O MÉTODO CERTO
					Token token("NUMBER", tableEntry);
					this->tokenVector->push_back(token);
					this->hashMap->insertEntry(tableEntry);
					lexeme.clear();
					//MOVER O CURSOR DO BUFFER PARA TRÁS
				}
				break;

			case 9:
				char c = this->charBuffer->getNextChar();
				if (c => '0' && c <= '9'){
					lexeme.push_back(c);
					state = 9;
				}else{
					float stringvalue;
					stringstream str(lexema);
					str >> stringvalue;
					TableEntry* tableEntry = new TableEntry(lexeme,"NUMBER",this->charBuffer->getNumLines,stringvalue);
					// VERIFICAR O MÉTODO CERTO
					Token token("NUMBER", tableEntry);
					this->tokenVector->push_back(token);
					this->hashMap->insertEntry(tableEntry);
					lexeme.clear();
					//MOVER O CURSOR DO BUFFER PARA TRÁS
				}
				break;


		}
	}
}
