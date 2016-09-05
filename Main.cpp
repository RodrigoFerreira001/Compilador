#include "SymbolTable.hpp"
#include "LexicalAnalyzer.hpp"
#include "Buffer.hpp"
#include <iostream>
using namespace std;

int main(int argc, char **argv){

    Buffer* buffer = new Buffer(256, argv[1]);
    SymbolTable* symbolTable = new SymbolTable();
    vector<Token*>* tokenVector = new vector<Token*>();

    LexicalAnalyzer* Zhuli = new LexicalAnalyzer(buffer, tokenVector, symbolTable);
    //Zhuuuuu-li, Doooo the Thiing!!
    Zhuli->doTheThing();

    map <string, TableEntry*>::iterator it;
    TableEntry* tmp;

    cout << "Symbol Table Content:" << endl;
    for(it =  symbolTable->getHashMap()->begin(); it != symbolTable->getHashMap()->end(); it++){
    	if(it->second->getToken() == "ID"){
    		cout << "Lexema: " << it->second->getLexeme() << endl;
    		cout << "Token: " << it->second->getToken() << endl;
    		cout << "Posição: Linha " << it->second->getLineNumber() << ", Coluna " << it->second->getLinePos() << endl;

    	}else
    	if(it->second->getToken() == "NUMBER"){

    	}

    }

    return 0;
}
