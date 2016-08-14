#include "TableEntry.hpp"

//Construtor padrão
TableEntry::TableEntry(){
    this->lexeme = new string;
    this->token = new string;
    this->lineNumber = new int;
    this->value = new float;
}

//Construtor padrão
TableEntry::TableEntry(string lexeme, string token, int lineNumber, int value){
    this->lexeme = new string;
    this->token = new string;
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

    TableEntry *tmp;

    while(this->next != NULL){
        tmp = this->next;
        this->next = this->next->getNextEntry();
        delete tmp;
    }
}

void TableEntry::setLexeme(string lexeme){
    *(this->lexeme) = lexeme;
}

string TableEntry::getLexeme() const{
    return *(this->lexeme);
}

void TableEntry::setToken(string token){
    *(this-> token) = token;
}

string TableEntry::getToken() const{
    return *(this->token);
}

void TableEntry::setLineNumber(int lineNumber){
    *(this->lineNumber) = lineNumber;
}

int TableEntry::getLineNumber() const{
    return *(this->lineNumber);
}

void TableEntry::setValue(float value){
    *(this->value) = value;
}

float TableEntry::getValue() const{
    return *(this->value);
}

TableEntry* TableEntry::getNextEntry() const{
    return this->next;
}
