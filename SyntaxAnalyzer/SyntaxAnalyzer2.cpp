#include "SyntaxAnalyzer.hpp"

void SyntaxAnalyzer::print_syntactic_error(Token token){

}

bool SyntaxAnalyzer::match(Token token, int index, vector<Token*>* token_vector){

}

vector<Declaration> SyntaxAnalyzer::declarations_list(vector<Token*>* token_vector, int index){

}

int SyntaxAnalyzer::type(vector<Token*>* token_vector, int index){

}

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

Expr SyntaxAnalyzer::relation(vector<Token*>* token_vector, int index){

}

Expr SyntaxAnalyzer::plus(vector<Token*>* token_vector, int index){

}

Expr SyntaxAnalyzer::term(vector<Token*>* token_vector, int index){

}

Expr SyntaxAnalyzer::factor(vector<Token*>* token_vector, int index){
	//TODO OLHAR DECLARAÇÕES
	if(token_vector->at(index)->getToken() == "ID"){
		//Id id = new Id(token_vector->at(index)->getTableEntry(),);
			match(token_vector->at(index), index, token_vector);
			return id;
	}else{
		if(token_vector->at(index)->getToken() == "NUMBER"){
			//Number num = new Number(token_vector->at(index)->getTableEntry(),);
				match(token_vector->at(index), index, token_vector);
				return num;
		}else{
			if(token_vector->at(index)->getToken() == "LBRACKET"){
					match(token_vector->at(index), index, token_vector);
				//Expr e = new Expr()
					return e;
			}else{
				printf("Erro! Identificador, número ou abre parênteses esperado na linha ...");
			}
		}
	}

}

SyntaxAnalyzer::SyntaxAnalyzer(AbstractSyntaxTree* ast, vector<Token*>* token_vector){
	this->ast = ast;
	this->token_vector = token_vector;
}

void SyntaxAnalyzer::faz_o_urro(){

}
