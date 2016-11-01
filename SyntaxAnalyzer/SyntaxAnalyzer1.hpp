#include "AbstractSyntaxTree.hpp"
#include "../LexicalAnalyzer/Token.hpp"
#include "../LexicalAnalyzer/TableEntry.hpp"
#include <vector>

class SyntaxAnalyzer{
private:
	AbstractSyntaxTree* ast;
	vector<Token*>* token_vector;

	vector<Declaration> declarations_list2(vector<Token*>* token_vector, int index, int currentType);
	vector<Comannd> commands_list(vector<Token*>* token_vector, int index);
	Expr expression(vector<Token*>* token_vector, int index);
	Expr and(vector<Token*>* token_vector, int index);
	Expr equal(vector<Token*>* token_vector, int index);

public:
	SyntaxAnalyzer(AbstractSyntaxTree* ast, vector<Token*>* token_vector);
	void faz_o_urro();
};
