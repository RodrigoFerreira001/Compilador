#pragma once

#include <map>
#include <string>
#include "TableEntry.hpp"
using namespace std;

class SymbolTable{
private:
    map<string,TableEntry>*  hashMap;

public:
    SymbolTable();
    ~SymbolTable();
    void insertEntry();
};
