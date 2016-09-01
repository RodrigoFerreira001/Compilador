#pragma once
#include <string>
#include "TableEntry.hpp"
using namespace std;

class Token{
private:
    string* token;
    TableEntry* tableEntry;

public:
    Token();
    Token(string token, TableEntry* tableEntry);
    ~Token();

    void setToken(string token);
    string getToken();

    void setTableEntry(TableEntry* tableEntry);
    TableEntry* getTableEntry();
};
