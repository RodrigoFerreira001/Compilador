#include "SymbolTable.hpp"
#include "LexicalAnalyzer.hpp"
#include "Buffer.hpp"
#include <iostream>
using namespace std;

int main(int argc, char **argv){

    Buffer* buffer = new Buffer(256, argv[1]);
    SymbolTable* symbolTable = new SymbolTable();
    vector<Token*>* tokenVector = new vector<Token*>();

    LexicalAnalyzer* Zhuli = new LexicalAnalyzer(buffer, tokenVector, symbolTable);
    //Zhuuuuu-li, Doooo the Thiing!!
    Zhuli->doTheThing();
    return 0;
}
