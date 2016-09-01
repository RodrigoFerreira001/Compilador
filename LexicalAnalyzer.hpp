#pragma once

#include "SymbolTable.hpp"
#include "TableEntry.hpp"
#include "Buffer.hpp"
#include "Token.hpp"
#include <vector>
using namespace std;

class LexicalAnalyzer{
private:
    Buffer* charBuffer;
    vector<Token>* tokenVector;
    SymbolTable* symbolTable;

public:
    LexicalAnalyzer(Buffer* charBuffer, vector<Token>* tokenVector, SymbolTable* symbolTable);
    void start();
};
