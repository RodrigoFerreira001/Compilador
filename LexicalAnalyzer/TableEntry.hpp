#pragma once

#include <string>
#include "../SyntaxAnalyzer/Temp.hpp"
using namespace std;

class TableEntry{
private:
    string* lexeme;
    string* token;
	Temp* temp;
	int* type;
	bool* is_var_decl;
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

	void set_type(int type);
	int get_type();

	void set_var_decl(bool is_var_decl);
	bool get_var_decl();

	void set_temp(Temp* temp);
	string get_temp();
};
