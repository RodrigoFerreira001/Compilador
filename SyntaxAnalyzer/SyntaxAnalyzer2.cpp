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
	Expr* e1 = plus();
	if(token_vector->at(index)->getToken() == "LT"){
			match(token_vector->at(index), index, token_vector);
			Expr* e2 = plus();
			//Lt* lt = new Lt(e1,e2);
			return lt;
	}else{
		if(token_vector->at(index)->getToken() == "GT"){
				match(token_vector->at(index), index, token_vector);
				Expr* e2 = plus();
				//Gt* gt = new Gt(e1,e2);
				return gt;
		}else{
			if(token_vector->at(index)->getToken() == "LTE"){
					match(token_vector->at(index), index, token_vector);
					Expr* e2 = plus();
					//Lte* le = new Lte(e1,e2);
					return lt;
			}else{
				if(token_vector->at(index)->getToken() == "GTE"){
						match(token_vector->at(index), index, token_vector);
						Expr* e2 = plus();
						//Gte* ge = new Gte(e1,e2);
						return ge;
				}
			}
		}
	}

	return e1;
}

Expr SyntaxAnalyzer::plus(vector<Token*>* token_vector, int index){
	Expr* e1 = term();
	if(token_vector->at(index)->getToken() == "PLUS"){
			match(token_vector->at(index), index, token_vector);
			Expr* e2 = term();
			//Plus* a = new Plus(e1,e2);
			return a;
	}else{
		if(token_vector->at(index)->getToken() == "MINUS"){
				match(token_vector->at(index), index, token_vector);
				Expr* e2 = term();
				//Minus* m = new Minus(e1,e2);
				return m;
		}
	}
	return e1;
}

Expr SyntaxAnalyzer::term(vector<Token*>* token_vector, int index){
	Expr* e1 = factor();
	if(token_vector->at(index)->getToken() == "TIMES"){
			match(token_vector->at(index), index, token_vector);
			Expr e2 = fator();
			//Mult mu = new Mult(e1,e2);
			return mu;
	}else{
		if(oken_vector->at(index)->getToken() == "DIV"){
				match(token_vector->at(index), index, token_vector);
				Expr* e2 = fator();
				//Div* d = new Div(e1,e2);
				return d;
		}
	}
	return e1;
}

Expr SyntaxAnalyzer::factor(vector<Token*>* token_vector, int index){
	int current_type = -1;

	if(token_vector->at(index)->getToken() == "ID"){
			Temp* temp = new Temp();
			//Id* id = new Id(token_vector->at(index)->getTableEntry(),);
			match(token_vector->at(index), index, token_vector);
			return id;
	}else{
		if(token_vector->at(index)->getToken() == "NUMBER"){
			//Number* num = new Number(token_vector->at(index)->getTableEntry(),);
				match(token_vector->at(index), index, token_vector);
				return num;
		}else{
			if(token_vector->at(index)->getToken() == "LBRACKET"){
					match(token_vector->at(index), index, token_vector);
					current_type = type(token_vector, index);
					//Expr* e = new Expr(current_type, token_vector->at(i)->getTableEntry(), true , temp);
					match(token_vector->at(index), index, token_vector);
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
