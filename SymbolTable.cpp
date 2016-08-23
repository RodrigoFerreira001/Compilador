#include "SymbolTable.hpp"

SymbolTable::SymbolTable(){
    this->hashMap = new map <string, TableEntry*>;

    //inserção dos tokens na hash
    TableEntry* lInt = new TableEntry;
    lInt->setToken("INT");
    this->hashMap->insert(pair<string, TableEntry*> ("int", lInt));

    TableEntry* lFloat = new TableEntry;
    lInt->setToken("FLOAT");
    this->hashMap->insert(pair<string, TableEntry*> ("float", lFloat));

    TableEntry* lIf = new TableEntry;
    lInt->setToken("IF");
    this->hashMap->insert(pair<string, TableEntry*> ("if", lIf));

    TableEntry* lElse = new TableEntry;
    lInt->setToken("ELSE");
    this->hashMap->insert(pair<string, TableEntry*> ("else", lElse));

    TableEntry* lWhile = new TableEntry;
    lInt->setToken("WHILE");
    this->hashMap->insert(pair<string, TableEntry*> ("while", lWhile));

    TableEntry* lLbracket = new TableEntry;
    lInt->setToken("LBRACKET");
    this->hashMap->insert(pair<string, TableEntry*> ("(", lLbracket));

    TableEntry* lRbracket = new TableEntry;
    lInt->setToken("RBRACKET");
    this->hashMap->insert(pair<string, TableEntry*> (")", lRbracket));

    TableEntry* lLbrace = new TableEntry;
    lInt->setToken("LBRACE");
    this->hashMap->insert(pair<string, TableEntry*> ("{", lLbrace));

    TableEntry* lRbrace = new TableEntry;
    lInt->setToken("RBRACE");
    this->hashMap->insert(pair<string, TableEntry*> ("}", lRbrace));

    TableEntry* lComma = new TableEntry;
    lInt->setToken("COMMA");
    this->hashMap->insert(pair<string, TableEntry*> (",", lComma));

    TableEntry* lPcomma = new TableEntry;
    lInt->setToken("PCOMMA");
    this->hashMap->insert(pair<string, TableEntry*> (";", lPcomma));

    TableEntry* lAttr = new TableEntry;
    lInt->setToken("ATTR");
    this->hashMap->insert(pair<string, TableEntry*> ("=", lAttr));

    TableEntry* lEqual = new TableEntry;
    lInt->setToken("EQUAL");
    this->hashMap->insert(pair<string, TableEntry*> ("==", lEqual));

    TableEntry* lLt = new TableEntry;
    lInt->setToken("LT");
    this->hashMap->insert(pair<string, TableEntry*> ("<", lLt));

    TableEntry* lLe = new TableEntry;
    lInt->setToken("LE");
    this->hashMap->insert(pair<string, TableEntry*> ("<=", lLe));

    TableEntry* lGt = new TableEntry;
    lInt->setToken("GT");
    this->hashMap->insert(pair<string, TableEntry*> (">", lGt));

    TableEntry* lGe = new TableEntry;
    lInt->setToken("GE");
    this->hashMap->insert(pair<string, TableEntry*> (">=", lGe));

    TableEntry* lNe = new TableEntry;
    lInt->setToken("NE");
    this->hashMap->insert(pair<string, TableEntry*> ("!=", lNe));

    TableEntry* lOr = new TableEntry;
    lInt->setToken("OR");
    this->hashMap->insert(pair<string, TableEntry*> ("||", lOr));

    TableEntry* lAnd = new TableEntry;
    lInt->setToken("AND");
    this->hashMap->insert(pair<string, TableEntry*> ("&&", lAnd));

    TableEntry* lPlus = new TableEntry;
    lInt->setToken("PLUS");
    this->hashMap->insert(pair<string, TableEntry*> ("+", lPlus));

    TableEntry* lMinus = new TableEntry;
    lInt->setToken("MINUS");
    this->hashMap->insert(pair<string, TableEntry*> ("-", lMinus));

    TableEntry* lTimes = new TableEntry;
    lInt->setToken("TIMES");
    this->hashMap->insert(pair<string, TableEntry*> ("*", lTimes));

    TableEntry* lDiv = new TableEntry;
    lInt->setToken("DIV");
    this->hashMap->insert(pair<string, TableEntry*> ("/", lDiv));

    TableEntry* lRead = new TableEntry;
    lInt->setToken("READ");
    this->hashMap->insert(pair<string, TableEntry*> ("read", lRead));

    TableEntry* lPrint = new TableEntry;
    lInt->setToken("PRINT");
    this->hashMap->insert(pair<string, TableEntry*> ("print", lPrint));
}

SymbolTable::~SymbolTable(){
    delete this->hashMap;
}

void SymbolTable::insertEntry(TableEntry* entry){
    if(entry->getToken() == "ID" || entry->getToken() == "NUMBER"){
        if(this->hashMap->count(entry->getLexeme()) == 0){
            this->hashMap->insert(pair<string, TableEntry*> (entry->getLexeme(), entry));
        }else{
            TableEntry* tmp = (*(this->hashMap))[entry->getLexeme()];
            entry->setNextEntry(tmp);
            (*(this->hashMap))[entry->getLexeme()] = entry;
        }
    }
}

map<string,TableEntry*> SymbolTable::getHashMap(){
    return *(this->hashMap);
}
