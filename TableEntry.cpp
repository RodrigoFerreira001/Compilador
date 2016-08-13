#include "TableEntry.hpp"

    string* lexeme;
    int* token;
    int* lineNumber;
    float* value;
    TableEntry* next;

//Construtor padrão
TableEntry::TableEntry(){
    this->lexeme = new string;
    this->token = new int;
    this->lineNumber = new int;
    this->value = new float;
}

//Construtor padrão
TableEntry::TableEntry(string lexeme, int token, int lineNumber, int value){
    this->lexeme = new string;
    this->token = new int;
    this->lineNumber = new int;
    this->value = new float;

    this->lexeme = lexeme;
    this->token = token;
    this->lineNumber = lineNumber;
    this->value = value;
}

TableEntry::~TableEntry(){
    delete this->lexeme;
    delete this->token;
    delete this->lineNumber;
    delete this->value;

    
}

void TableEntry::setLexeme(string lexeme){

}

string TableEntry::getLexeme(){

}

void TableEntry::setToken(int token){

}

int TableEntry::getToken(){

}

void TableEntry::setLineNumber(int lineNumber){

}

int TableEntry::getLineNumber(){

}

void TableEntry::setValue(float value){

}

float TableEntry::getValue(){

}

TableEntry* TableEntry::getNextEntry(){

}
