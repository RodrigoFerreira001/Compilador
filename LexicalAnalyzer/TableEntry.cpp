#include "TableEntry.hpp"

//Construtor padrão
TableEntry::TableEntry(){
    this->lexeme = new string;
    this->token = new string;
    this->lineNumber = new int;
    this->linePos = new int;
    this->value = new float;
    this->next = NULL;
	this->type = new int;
	this->is_var_decl = new bool;
}

//Construtor padrão
TableEntry::TableEntry(string lexeme, string token, int lineNumber, int linePos, float value){
    this->lexeme = new string;
    this->token = new string;
    this->lineNumber = new int;
    this->linePos = new int;
    this->value = new float;
    this->next = NULL;
	this->type = new int;
	this->is_var_decl = new bool;

    *(this->lexeme) = lexeme;
    *(this->token) = token;
    *(this->lineNumber) = lineNumber;
    *(this->linePos) = linePos;
    *(this->value) = value;
}

TableEntry::~TableEntry(){
    delete this->lexeme;
    delete this->token;
    delete this->lineNumber;
    delete this->linePos;
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

void TableEntry::setLinePos(int linePos){
    *(this->linePos) = linePos;
}

int TableEntry::getLinePos() const{
    return *(this->linePos);
}

void TableEntry::setValue(float value){
    *(this->value) = value;
}

float TableEntry::getValue() const{
    return *(this->value);
}

void TableEntry::setNextEntry(TableEntry* entry){
    this->next = entry;
}

TableEntry* TableEntry::getNextEntry() const{
    return this->next;
}

void TableEntry::set_type(int type){
	*(this->type) = type;
}

int TableEntry::get_type(){
	return *(this->type);
}

void TableEntry::set_var_decl(bool is_var_decl){
	*(this->is_var_decl) = is_var_decl;
}

bool TableEntry::get_var_decl(){
	return *(this->is_var_decl);
}

void TableEntry::set_temp(Temp* temp){
	this->temp = temp;
}

string TableEntry::get_temp(){
	return temp->get_name();
}
