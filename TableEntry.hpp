#pragma once

#include <string>
using namespace std;

class TableEntry{
private:
    string* lexeme;
    string* token;
    int* lineNumber;
    float* value;
    TableEntry* next;

public:
    TableEntry();
    TableEntry(string lexeme, string token, int lineNumber, float value);
    ~TableEntry();

    void setLexeme(string lexeme);
    string getLexeme();

    void setToken(string token);
    string getToken() const;

    void setLineNumber(int lineNumber);
    int getLineNumber() const;

    void setValue(float value);
    float getValue() const;

    void setNextEntry(TableEntry* entry);
    TableEntry* getNextEntry() const;
};
