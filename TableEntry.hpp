#include <string>
using namespace std;

class TableEntry{
private:
    string *lexeme;
    int *token;
    int *lineNumber;
    float *value;
    TableEntry *next;
    
public:
    TableEntry();
    TableEntry(string lexeme, int token, int lineNumber, int value);
    ~TableEntry();

    void setLexeme(string lexeme);
    string getLexeme();

    void setToken(int token);
    int getToken();

    void setLineNumber(int lineNumber);
    int getLineNumber();

    void setValue(float value);
    float getValue();

    TableEntry *getNextEntry();
};
