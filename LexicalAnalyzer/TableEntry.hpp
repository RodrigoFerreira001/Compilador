#pragma once

#include <string>
using namespace std;

class TableEntry{
private:
    string* lexeme;
    string* token;
    int* lineNumber;
    int* linePos;
    float* value;
    TableEntry* next;

public:
    TableEntry();
    TableEntry(string lexeme, string token, int lineNumber, int linePos, float value);
    ~TableEntry();

    void setLexeme(string lexeme);
    string getLexeme()const;

    void setToken(string token);
    string getToken() const;

    void setLineNumber(int lineNumber);
    int getLineNumber() const;

    void setLinePos(int linePos);
    int getLinePos() const;

    void setValue(float value);
    float getValue() const;

    void setNextEntry(TableEntry* entry);
    TableEntry* getNextEntry() const;
};