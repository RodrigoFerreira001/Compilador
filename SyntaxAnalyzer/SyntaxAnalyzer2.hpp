#include "AbstractSyntaxTree.hpp"
#include "../LexicalAnalyzer/Token.hpp"
#include "../LexicalAnalyzer/TableEntry.hpp"
#include <vector>

class SyntaxAnalyzer{
private:
	AbstractSyntaxTree* ast;
	vector<Token*>* token_vector;
	
	Expr relation(vector<Token*>* token_vector, int index);
	Expr plus(vector<Token*>* token_vector, int index);
	Expr term(vector<Token*>* token_vector, int index);
	Expr factor(vector<Token*>* token_vector, int index);

public:
	SyntaxAnalyzer(AbstractSyntaxTree* ast, vector<Token*>* token_vector);
	void faz_o_urro();
};
