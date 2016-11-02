#include "AbstractSyntaxTree.hpp"
#include "../LexicalAnalyzer/Token.hpp"
#include "../LexicalAnalyzer/TableEntry.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

class SyntaxAnalyzer{
private:
	AbstractSyntaxTree* ast;
	vector<Token*>* token_vector;
	bool* has_erro;

	void print_syntactic_error(Token* token);
	bool match(Token* token, int& index, vector<Token*>* token_vector);
	vector<Declaration*>* declarations_list(vector<Token*>* token_vector, int& index);
	int type(vector<Token*>* token_vector, int& index);

public:
	SyntaxAnalyzer(AbstractSyntaxTree* ast, vector<Token*>* token_vector);
	void faz_o_urro();
};
