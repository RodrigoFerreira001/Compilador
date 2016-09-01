#include "LexicalAnalyzer.hpp"

LexicalAnalyzer::LexicalAnalyzer(Buffer* charBuffer, vector<Token*>* tokenVector, SymbolTable* symbolTable){
	this->charBuffer = charBuffer;
	this->tokenVector = tokenVector;
	this->symbolTable = symbolTable;
}

void LexicalAnalyzer::doTheThing(){

	int state = 0;
	char c;
	string lexeme;

	while(!this->charBuffer->eob()){
		switch (state) {
			case 0:
				c = this->charBuffer->getNextChar();
				if(c == ' ' || c == '\n' || c == '\t'){
					state = 0;
				}else
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
					TableEntry* tableEntry = new TableEntry("(","LBRACKET",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("LBRACKET", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == ')'){
					TableEntry* tableEntry = new TableEntry(")","RBRACKET",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("RBRACKET", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == '{'){
					TableEntry* tableEntry = new TableEntry("{","LBRACE",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("LBRACE", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == '}'){
					TableEntry* tableEntry = new TableEntry("}","RBRACE",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("RBRACE", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == ','){
					TableEntry* tableEntry = new TableEntry(",","COMMA",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("COMMA", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else if(c == ';'){
					TableEntry* tableEntry = new TableEntry(";","PCOMMA",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("PCOMMA", tableEntry);
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
					TableEntry* tableEntry = new TableEntry("+","PLUS",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("PLUS", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == '-'){
					TableEntry* tableEntry = new TableEntry("-","MINUS",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("MINUS", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == '*'){
					TableEntry* tableEntry = new TableEntry("*","TIMES",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("TIMES", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(c == '/'){
					TableEntry* tableEntry = new TableEntry("/","DIV",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("DIV", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else
				if(((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))){
					state = 7;
					lexeme.push_back(c);
				}else
				if(c >= '0' && c <= '9'){
					state = 8;
					lexeme.push_back(c);
				}
				break;

			case 1:
				c = this->charBuffer->getNextChar();
				if (c == '='){
					TableEntry* tableEntry = new TableEntry("<=","LE",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("LE", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else{
					TableEntry* tableEntry = new TableEntry("<","LT",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("LT", tableEntry);
					this->tokenVector->push_back(token);
					this->charBuffer->ungetChar();
					state = 0;
				}
				break;

			case 2:
				c = this->charBuffer->getNextChar();
				if (c == '='){
					TableEntry* tableEntry = new TableEntry(">=","GE",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("GE", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else{
					TableEntry* tableEntry = new TableEntry(">","GT",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("GT", tableEntry);
					this->tokenVector->push_back(token);
					this->charBuffer->ungetChar();
					state = 0;
				}
				break;

			case 3:
				c = this->charBuffer->getNextChar();
				if (c == '='){
					TableEntry* tableEntry = new TableEntry("==","EQUAL",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("EQUAL", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else{
					TableEntry* tableEntry = new TableEntry("=","ATTR",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("ATTR", tableEntry);
					this->tokenVector->push_back(token);
					this->charBuffer->ungetChar();
					state = 0;
				}
				break;

			case 4:
				c = this->charBuffer->getNextChar();
				if (c == '='){
					TableEntry* tableEntry = new TableEntry("!=","NE",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("NE", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else{
					cout << "ERROR : character '=' expected on line " << this->charBuffer->getCurrentLine() << endl;
					exit(EXIT_FAILURE);
				}
				break;

			case 5:
				c = this->charBuffer->getNextChar();
				if (c == '|'){
					TableEntry* tableEntry = new TableEntry("||", "OR", this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("OR", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else{
					cout << "ERROR : character '|' expected on line " << this->charBuffer->getCurrentLine() << endl;
					exit(EXIT_FAILURE);
				}
				break;

			case 6:
				c = this->charBuffer->getNextChar();
				if (c == '&'){
					TableEntry* tableEntry = new TableEntry("&&","AND",this->charBuffer->getCurrentLine(),0);
					Token* token = new Token("AND", tableEntry);
					this->tokenVector->push_back(token);
					state = 0;
				}else{
					cout << "ERROR : character '&' expected on line " << this->charBuffer->getCurrentLine() << endl;
					exit(EXIT_FAILURE);
				}
				break;

			case 7:
				c = this->charBuffer->getNextChar();
				if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9'){
					lexeme.push_back(c);
					state = 7;
				}else{
					this->charBuffer->ungetChar();
					if(lexeme == "int"){
						TableEntry* tableEntry = new TableEntry(lexeme,"INT",this->charBuffer->getCurrentLine(),0);
						// VERIFICAR O MÉTODO CERTO
						Token* token = new Token("INT", tableEntry);
						this->tokenVector->push_back(token);
						lexeme.clear();
					}else if(lexeme == "float"){
						TableEntry* tableEntry = new TableEntry(lexeme,"FLOAT",this->charBuffer->getCurrentLine(),0);
						// VERIFICAR O MÉTODO CERTO
						Token* token = new Token("FLOAT", tableEntry);
						this->tokenVector->push_back(token);
						lexeme.clear();
					}else if(lexeme == "if"){
						TableEntry* tableEntry = new TableEntry(lexeme,"IF",this->charBuffer->getCurrentLine(),0);
						// VERIFICAR O MÉTODO CERTO
						Token* token = new Token("IF", tableEntry);
						this->tokenVector->push_back(token);
						lexeme.clear();
					}else if(lexeme == "else"){
						TableEntry* tableEntry = new TableEntry(lexeme,"ELSE",this->charBuffer->getCurrentLine(),0);
						// VERIFICAR O MÉTODO CERTO
						Token* token = new Token("ELSE", tableEntry);
						this->tokenVector->push_back(token);
						lexeme.clear();
					}else if(lexeme == "while"){
						TableEntry* tableEntry = new TableEntry(lexeme,"WHILE",this->charBuffer->getCurrentLine(),0);
						// VERIFICAR O MÉTODO CERTO
						Token* token = new Token("WHILE", tableEntry);
						this->tokenVector->push_back(token);
						lexeme.clear();
					}else if(lexeme == "read"){
						TableEntry* tableEntry = new TableEntry(lexeme,"READ",this->charBuffer->getCurrentLine(),0);
						// VERIFICAR O MÉTODO CERTO
						Token* token = new Token("READ", tableEntry);
						this->tokenVector->push_back(token);
						lexeme.clear();
					}else if(lexeme == "print"){
						TableEntry* tableEntry = new TableEntry(lexeme,"PRINT",this->charBuffer->getCurrentLine(),0);
						// VERIFICAR O MÉTODO CERTO
						Token* token = new Token("PRINT", tableEntry);
						this->tokenVector->push_back(token);
						lexeme.clear();
					}else {
						TableEntry* tableEntry = new TableEntry(lexeme,"ID",this->charBuffer->getCurrentLine(),0);
						// VERIFICAR O MÉTODO CERTO
						Token* token = new Token("ID", tableEntry);
						this->tokenVector->push_back(token);
						this->symbolTable->insertEntry(tableEntry);
						lexeme.clear();
					}
					state = 0;
				}
				break;

			case 8:
				c = this->charBuffer->getNextChar();
				if (c >= '0' && c <= '9'){
					lexeme.push_back(c);
					state = 8;
				}else if (c == '.'){
					lexeme.push_back(c);
					state = 9;
				}else{
					float stringvalue;
					stringstream str(lexeme);
					str >> stringvalue;
					TableEntry* tableEntry = new TableEntry(lexeme,"NUMBER",this->charBuffer->getCurrentLine(),stringvalue);
					Token* token = new Token("NUMBER", tableEntry);
					this->tokenVector->push_back(token);
					this->symbolTable->insertEntry(tableEntry);
					this->charBuffer->ungetChar();
					lexeme.clear();
					state = 0;
				}
				break;

			case 9:
				c = this->charBuffer->getNextChar();
				if (c >= '0' && c <= '9'){
					lexeme.push_back(c);
					state = 9;
				}else{
					float stringvalue;
					stringstream str(lexeme);
					str >> stringvalue;
					TableEntry* tableEntry = new TableEntry(lexeme,"NUMBER",this->charBuffer->getCurrentLine(),stringvalue);
					Token* token = new Token("NUMBER", tableEntry);
					this->tokenVector->push_back(token);
					this->symbolTable->insertEntry(tableEntry);
					this->charBuffer->ungetChar();
					lexeme.clear();
					state = 0;
				}
				break;
		}
	}
}
