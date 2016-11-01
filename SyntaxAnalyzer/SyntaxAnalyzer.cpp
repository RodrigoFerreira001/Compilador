#include "SyntaxAnalyzer.hpp"

void SyntaxAnalyzer::print_syntactic_error(Token token){
	if(token.getToken() == "ID" || token.getNome() == "NUMBER"){
		printf(“%s esperado na linha %d”, token.getNome(), token.getNumLinha());
	}else{
		printf(“%s esperado na linha %d”, token.getLexema(), token.getNumLinha());
	}
}

bool SyntaxAnalyzer::match(Token token, int index, vector<Token*>* token_vector){

}

vector<Declaration> SyntaxAnalyzer::declarations_list(vector<Token*>* token_vector, int index){

}

int SyntaxAnalyzer::type(vector<Token*>* token_vector, int index){

}

SyntaxAnalyzer::SyntaxAnalyzer(AbstractSyntaxTree* ast, vector<Token*>* token_vector){
	this->ast = ast;
	this->token_vector = token_vector;
}

void SyntaxAnalyzer::faz_o_urro(){

}
