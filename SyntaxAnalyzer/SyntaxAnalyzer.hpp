#include "AbstractSyntaxTree.hpp"
#include "../LexicalAnalyzer/Token.hpp"
#include "../LexicalAnalyzer/TableEntry.hpp"
#include <vector>

class SyntaxAnalyzer{
private:
	AbstractSyntaxTree* ast;
	vector<Token*>* token_vector;
	
	void print_syntactic_error(Token token);
	bool match(Token token, int index, vector<Token*>* token_vector);
	vector<Declaration> declarations_list(vector<Token*>* token_vector, int index);
	int type(vector<Token*>* token_vector, int index);
	vector<Declaration> declarations_list2(vector<Token*>* token_vector, int index, int currentType);
	vector<Comannd> commands_list(vector<Token*>* token_vector, int index);
	Expr expression(vector<Token*>* token_vector, int index);
	Expr and(vector<Token*>* token_vector, int index);
	Expr equal(vector<Token*>* token_vector, int index);
	Expr relation(vector<Token*>* token_vector, int index);
	Expr plus(vector<Token*>* token_vector, int index);
	Expr term(vector<Token*>* token_vector, int index);
	Expr factor(vector<Token*>* token_vector, int index);

public:
	SyntaxAnalyzer(AbstractSyntaxTree* ast, vector<Token*>* token_vector);
	void faz_o_urro();
};
