#include "Token.hpp"

Token::Token(){
    this->token = new string;
}

Token::Token(string token, TableEntry* tableEntry){
    this->token = new string;
    *(this->token) = token;
    this->tableEntry = tableEntry;
}

Token::~Token(){
    cout << "Olá, Soy um cusaum!" << endl;
    //delete this->token;
}

void Token::setToken(string token){
    *(this->token) = token;
}

string Token::getToken(){
    return *(this->token);
}

void Token::setTableEntry(TableEntry* tableEntry){
    this->tableEntry = tableEntry;
}

TableEntry* Token::getTableEntry(){
    return this->tableEntry;
}
