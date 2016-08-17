#pragma once

#include "SymbolTable.hpp"
#include "TableEntry.hpp"
#include "Buffer.hpp"
#include <vector>
using namespace std;

class LexicalAnalyzer{
private:
    Buffer* charBuffer;
    vector<string, TableEntry*>* tokenVector;
    SymbolTable* symbolTable;

    LexicalAnalyzer(Buffer* charBuffer, vector<string, TableEntry*>* tokenVector, SymbolTable* symbolTable);
    void start();
};
