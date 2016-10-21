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
            cout << "Token: " << it->second->getToken() << endl;
    		cout << "Lexema: " << it->second->getLexeme() << endl;
    		cout << "Posição:\n";
            cout << "\tLinha" <<it->second->getLineNumber() << ", Coluna " << it->second->getLinePos() << endl;

            tmp = it->second->getNextEntry();
            while(tmp != NULL){
                cout << "\tLinha" <<tmp->getLineNumber() << ", Coluna " << tmp->getLinePos() << endl;
                tmp = tmp->getNextEntry();
            }
            cout << "\n\n";

    	}else
    	if(it->second->getToken() == "NUMBER"){
            cout << "Token: " << it->second->getToken() << endl;
    		cout << "Lexema: " << it->second->getLexeme() << endl;
            cout << "Valor: " << it->second->getValue() << endl;
    		cout << "Posição:\n";
            cout << "\tLinha" <<it->second->getLineNumber() << ", Coluna " << it->second->getLinePos() << endl;

            tmp = it->second->getNextEntry();
            while(tmp != NULL){
                cout << "\tLinha" <<tmp->getLineNumber() << ", Coluna " << tmp->getLinePos() << endl;
                tmp = tmp->getNextEntry();
            }
            cout << "\n\n";
    	}
    }

    cout << "Token Vector Content:" << endl;
    for(int i = 0; i < tokenVector->size(); i++){
        cout << i << ": " << tokenVector->at(i)->getToken() << endl;
    }

    return 0;
}
