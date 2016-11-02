#include "SyntaxAnalyzer.hpp"

Expr SyntaxAnalyzer::relation(vector<Token*>* token_vector, int& index){
	Expr* e1 = plus();
	if(token_vector->at(index)->getToken() == "LT"){
		match(Token("LT",nullptr), index, token_vector);
		Expr* e2 = plus();
		Lt* lt = new Lt(e1,e2);
		return lt;
	}else{
		if(token_vector->at(index)->getToken() == "GT"){
			match(Token("GT",nullptr), index, token_vector);
			Expr* e2 = plus();
			Gt* gt = new Gt(e1,e2);
			return gt;
		}else{
			if(token_vector->at(index)->getToken() == "LTE"){
				match(Token("LTE",nullptr), index, token_vector);
				Expr* e2 = plus();
				Lte* le = new Lte(e1,e2);
				return le;
			}else{
				if(token_vector->at(index)->getToken() == "GTE"){
					match(Token("GTE",nullptr), index, token_vector);
					Expr* e2 = plus();
					Gte* ge = new Gte(e1,e2);
					return ge;
				}
			}
		}
	}

	return e1;
}

Expr SyntaxAnalyzer::plus(vector<Token*>* token_vector, int& index){
	Expr* e1 = term();
	if(token_vector->at(index)->getToken() == "PLUS"){
		match(Token("PLUS",nullptr), index, token_vector);
		Expr* e2 = term();
		Plus* a = new Plus(e1,e2);
		return a;
	}else{
		if(token_vector->at(index)->getToken() == "MINUS"){
			match(Token("MINUS",nullptr), index, token_vector);
			Expr* e2 = term();
			Minus* m = new Minus(e1,e2);
			return m;
		}
	}
	return e1;
}

Expr SyntaxAnalyzer::term(vector<Token*>* token_vector, int& index){
	Expr* e1 = factor();
	if(token_vector->at(index)->getToken() == "TIMES"){
		match(Token("TIMES",nullptr), index, token_vector);
		Expr e2 = fator();
		Mult mu = new Mult(e1,e2);
		return mu;
	}else{
		if(token_vector->at(index)->getToken() == "DIV"){
			match(Token("DIV",nullptr), index, token_vector);
			Expr* e2 = fator();
			Div* d = new Div(e1,e2);
			return d;
		}
	}
	return e1;
}

Expr SyntaxAnalyzer::factor(vector<Token*>* token_vector, int& index){
	int current_type = -1;

	if(token_vector->at(index)->getToken() == "ID"){
		Temp* temp = new Temp();
		Id* id = new Id(token_vector->at(index)->getTableEntry(), false, token_vector->at(index)->getTableEntry()->get_var_decl(), token_vector->at(index)->getTableEntry()->get_type(), temp);
		match(Token("ID",nullptr), index, token_vector);
		return id;
	}else{
		if(token_vector->at(index)->getToken() == "NUMBER"){
			Number* num = new Number(token_vector->at(index)->getTableEntry(), token_vector->at(index)->getTableEntry()->get_type());
			match(Token("NUMBER",nullptr), index, token_vector);
			return num;
		}else{
			if(token_vector->at(index)->getToken() == "LBRACKET"){
				match(Token("LBRACKET",nullptr), index, token_vector);
				if (token_vector->at(i)->getTableEntry()->get_type() == 0){
					Expr* e = new Expr(token_vector->at(i)->getTableEntry()->get_type(), int(token_vector->at(i)->getTableEntry()->getValue()), 0.0, false);
				}else{
					if (token_vector->at(i)->getTableEntry()->get_type() == 1)
					Expr* e = new Expr(token_vector->at(i)->getTableEntry()->get_type(), token_vector->at(index)->getTableEntry(), 0 , token_vector->at(i)->getTableEntry()->getValue(), false);
				}else{
					Expr* e = new Expr(token_vector->at(i)->getTableEntry()->get_type(), token_vector->at(index)->getTableEntry(), 0, 0.0, true);
				}else{
				}
				match(Token("RBRACKET",nullptr), index, token_vector);
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
