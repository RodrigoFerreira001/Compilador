#include "SyntaxAnalyzer.hpp"


vector<Declaration> SyntaxAnalyzer::declarations_list2(vector<Token*>* token_vector, int index, int currentType){

}

vector<Comannd> SyntaxAnalyzer::commands_list(vector<Token*>* token_vector, int index){

}

Expr SyntaxAnalyzer::expression(vector<Token*>* token_vector, int index){

}

Expr SyntaxAnalyzer::and(vector<Token*>* token_vector, int index){

}

Expr SyntaxAnalyzer::equal(vector<Token*>* token_vector, int index){

}


SyntaxAnalyzer::SyntaxAnalyzer(AbstractSyntaxTree* ast, vector<Token*>* token_vector){
	this->ast = ast;
	this->token_vector = token_vector;
}

void SyntaxAnalyzer::faz_o_urro(){

}
