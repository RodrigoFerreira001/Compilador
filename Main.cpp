#include "LexicalAnalyzer/SymbolTable.hpp"
#include "LexicalAnalyzer/LexicalAnalyzer.hpp"
#include "LexicalAnalyzer/Buffer.hpp"
#include "SyntaxAnalyzer/AbstractSyntaxTree.hpp"
#include "SyntaxAnalyzer/SyntaxAnalyzer.hpp"
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
            cout << "\tLinha " <<it->second->getLineNumber() << ", Coluna " << it->second->getLinePos() << endl;

            tmp = it->second->getNextEntry();
            while(tmp != NULL){
                cout << "\tLinha " <<tmp->getLineNumber() << ", Coluna " << tmp->getLinePos() << endl;
                tmp = tmp->getNextEntry();
            }
            cout << "\n\n";

    	}else
    	if(it->second->getToken() == "NUMBER"){
            cout << "Token: " << it->second->getToken() << endl;
    		cout << "Lexema: " << it->second->getLexeme() << endl;
            cout << "Valor: " << it->second->getValue() << endl;
    		cout << "Posição:\n";
            cout << "\tLinha " <<it->second->getLineNumber() << ", Coluna " << it->second->getLinePos() << endl;

            tmp = it->second->getNextEntry();
            while(tmp != NULL){
                cout << "\tLinha " <<tmp->getLineNumber() << ", Coluna " << tmp->getLinePos() << endl;
                tmp = tmp->getNextEntry();
            }
            cout << "\n\n";
    	}
    }

    cout << "Token Vector Content:" << endl;
    for(int i = 0; i < tokenVector->size(); i++){
        cout << i << ": " << tokenVector->at(i)->getToken() << "\t\tLinha: " << tokenVector->at(i)->getTableEntry()->getLineNumber() << endl;
    }

<<<<<<< HEAD
	cout << "Chamando analizador sintático\n\n\n" << endl;
=======
	cout << "\n ====================== Chamando analizador sintático ====================== \n" << endl;
>>>>>>> 5c5eccc5645ef4dd8016a94bb56acae19ab5239a
	int index = 0;
	AbstractSyntaxTree ast;
	SyntaxAnalyzer syntax_analyzer(&ast, tokenVector);
	syntax_analyzer.faz_o_urro(index);
<<<<<<< HEAD
  return 0;
=======

    for(int i = 0; i < ast.get_declarations()->size(); ++i){
        cout << "TOKEN DECLARAÇÃO: " << ast.get_declarations()->at(i)->get_table_entry()->getToken() << endl;
        cout << "LEXEMA DECLARAÇÃO: " << ast.get_declarations()->at(i)->get_table_entry()->getLexeme() << endl;
        cout << "LEXEMA DECLARAÇÃO: " << ast.get_declarations()->at(i)->get_type() << endl;
        cout << endl;
    }

    for(int i = 0; i < ast.get_commands()->size(); ++i){
        //cout << "TOKEN DECLARAÇÃO: " << ast.get_commands()->at(i)->getToken() << endl;
        //cout << "LEXEMA DECLARAÇÃO: " << ast.get_commands()->at(i)->get_table_entry()->getLexeme() << endl;
        //cout << endl;
    }
    return 0;
>>>>>>> 5c5eccc5645ef4dd8016a94bb56acae19ab5239a
}
