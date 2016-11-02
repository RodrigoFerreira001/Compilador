#include "SyntaxAnalyzer.hpp"

void SyntaxAnalyzer::print_syntactic_error(Token* token){
	if(token->getToken() == "ID" || token->getToken() == "NUMBER"){
		cout << token->getTableEntry()->getToken() << " esperado na linha " <<
		token->getTableEntry()->getLineNumber() << endl;
	}else{
		cout << token->getTableEntry()->getLexeme() << " esperado na linha " <<
		token->getTableEntry()->getLineNumber() << endl;
	}
}

bool synchronize(Token* token, int& index, vector<Token*>* token_vector){
	return true;
}

bool SyntaxAnalyzer::match(Token* token, int& index, vector<Token*>* token_vector){
	if(token_vector->at(index).getToken() == token->getToken()){
		i++;
	}else{
		*has_error = true;
		print_syntactic_error(token);
		return synchronize();
	}
}

vector<Declaration*>* SyntaxAnalyzer::declarations_list(vector<Token*>* token_vector, int& index){
	int current_type = -1;

	if(token_vector->at(i)->getToken() == "INT" ||  token_vector->at(i)->getToken() == "FLOAT"){
		vector<Declaration*>* decl_list = new vector<Declaration*>;
		current_type = type(token_vector, index);

		if(token_vector->at(i)->getToken() == "INT"){
			token_vector->at(i)->getTableEntry()->set_type(current_type);
			token_vector->at(i)->getTableEntry()->set_var_decl(true);

			Temp* temp = new Temp();
			Declaration* id = new Declaration(token_vector->at(i)->getTableEntry(), true, current_type, temp);
			token_vector->at(i)->getTableEntry()->set_temp(temp);
			decl_list->push_back(id);
			match(Token("ID",nullptr), index, token_vector);
		}else{
			print_syntactic_error(Token("ID", nullptr));
			synchronize(Token("ID", nullptr), index, int token_vector);
		}

		vector<Declaration*>* decl_list2 = declarations_list2(token_vector, index, current_type);
		decl_list->push_back(decl_list2);
		return decl_list;

	}else{
		return nullptr;
	}
}

int SyntaxAnalyzer::type(vector<Token*>* token_vector, int& index){
	int current_type = -1;

	if(token_vector->at(i)->getToken() == "INT"){
		current_type = 0;
		match(token_vector->at(i), index, token_vector);
	}else
	if(token_vector->at(i)->getToken() == "FLOAT"){
		current_type = 1;
		match(token_vector->at(i), index, token_vector);
	}

	return current_type;
}

vector<Declaration> SyntaxAnalyzer::declarations_list2(vector<Token*>* token_vector, int index, int currentType){
	if(token_vector->at(index)->getToken() == "COMMA"){

		vector<Declaration*>* decl_list = new vector<Declaration*>;
		match(token_vector->at(index)->getToken(), index, token_vector);

		if(token_vector->at(index)->getToken() == "ID"){
			token_vector->at(index)->getTableEntry()->set_type(current_type);
			token_vector->at(index)->set_type(currentType);

			Temp* temp = new Temp();
			Declaration* id = new Declaration(token_vector->at(index)->getTableEntry(), true, current_type, temp);
			token_vector->at(index)->getTableEntry()->set_temp(temp);
			decl_list->push_back(id);
			match(token_vector->at(index)->getToken(), index, token_vector);

		} else {

			print_syntactic_error(token_vector->at(index));
			synchronize(token_vector->at(index)->getToken(), index, token_vector);

		}
		List<Declaracao> declList2 = Decl2(currentType);
		decl_list->push_back(declList2);
		return declList;
	} else{
		if(token_vector->at(index)->getToken() == "PCOMMA"){
			match(token_vector->at(index)->getToken(), index, token_vector);
			return Declaration();
		}
	}
}


vector<Command> SyntaxAnalyzer::commands_list(vector<Token*>* token_vector, int index){
	vector<Command*>* command_vector = new vector<Command*>;

	if(token_vector->at(index)->getToken() == "PCOMMA")
		match(token_vector->at(index)->getToken(), index, token_vector);

	if(token_vector->at(index)->getToken() == "LBRACE"){
		match(token_vector->at(index)->getToken(), index, token_vector);
		vector<Command*>* c = Command();
		match(Token("RBRACE", nullptr), index, token_vector);
		return c;
	}


	if(token_vector->at(index)->getToken() == "ID"){
		Id* id = new Id(token_vector->at(index)->getTableEntry());
		id->setIsLValue(true);

		match(token_vector->at(index)->getToken(), index, token_vector);
		match(Token("ATTR", nullptr), index, token_vector);

		Attr attr = new Attr(id, Expr());
		match(Token("PCOMMA", nullptr), index, token_vector);
		command_vector->push_back(attr);
	}


	if(token_vector->at(index)->getToken() == "IF"){
		If if_ = new If();
		match(Token("IF", nullptr), index, token_vector);
		match(Token("LBRACKET", nullptr), index, token_vector);
		Expr e = new Expr();
		match(Token("RBRACKET", nullptr), index, token_vector);
		vector<Command*>* c = Command();

			if(token_vector->at(index)->getToken() == "ELSE"){
				match(Token("ELSE", nullptr), index, token_vector);
				vector<Command*>* c2 = Command();
			}

			if(c2->size() > 0)
				if_ = new If(e, c, c2);
			else
				if_ = new If(e, lc, nullptr);

				command_vector->push_back(if_);
				return command_vector;
	}

	if(token_vector->at(index)->getToken() == "WHILE"){
		match(token_vector->at(index)->getToken(), index, token_vector);
		match(Token("LBRACKET", nullptr), index, token_vector);
		Expr e = Expr();
		match(Token("RBRACKET", nullptr), index, token_vector);
		vector<Command*>* c = Command();
		While w = new While(e, c);
		command_vector->push_back(w);
		return command_vector;
	}

	if(token_vector->at(index)->getToken() == "READ"){
		match(token_vector->at(index)->getToken(), index, token_vector);
		if(token_vector->at(index)->getToken() == "ID"){
			Id id = new Id(token_vector->at(index)->getTableEntry());
			Read r = new Read(id);
			match(Token("ID", nullptr), index, token_vector);
			match(Token("PCOMMA", nullptr), index, token_vector);
			command_vector->push_back(r);
			return command_vector;
		}
	}

	if(token_vector->at(index)->getToken() == "PRINT"){
		match(token_vector->at(index)->getToken(), index, token_vector);
		Expr e = Expr();
		Print p = new Print(e);
		match(Token("PCOMMA", nullptr), index, token_vector);
		command_vector->push_back(p);
		return command_vector;
	}

	return nullptr;
}


Expr SyntaxAnalyzer::expression(vector<Token*>* token_vector, int index){
	Expr* e1 = and(token_vector, index);
	if(token_vector->at(index)->getToken() == "OR"){
		match(token_vector->at(index)->getToken(), index, token_vector);
		Expr* e2 = and(token_vector, index);
		return new Or(e1, e2);
	}
	return e1;
}


Expr SyntaxAnalyzer::and(vector<Token*>* token_vector, int index){
	Expr* e1 = equal(vector<Token*>* token_vector, int index);
	if(token_vector->at(index)->getToken() == "AND"){
		match(token_vector->at(index)->getToken(), index, token_vector);
		Expr* e2 = equal(token_vector, index);
		return new And(e1, e2);
	}
	return e1;
}


Expr SyntaxAnalyzer::equal(vector<Token*>* token_vector, int index){
	Expr* e1 = relation(token_vector, index);

	if(token_vector->at(index)->getToken() == "EQUAL"){
		match(token_vector->at(index)->getToken(), index, token_vector);
		Expr* e2 = relation(token_vector, index);
		return new Eq(e1, e2);
	}

	if(token_vector->at(index)->getToken() == "NE"){
		match(token_vector->at(index)->getToken(), index, token_vector);
		Expr* e2 = relation(token_vector, index);
		return new Ne(e1, e2);
	}

	return e1;
}

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
	has_error = new bool(false);
}

void SyntaxAnalyzer::faz_o_urro(){
	//(flagErro variavel global ou um atributo da classe AnalisadorSintatico)
    *has_error = false;
	int index = 0;

	match(Token("LBRACE",nullptr), &index, token_vector);

	vector<Declaration*>* decl_list = declarations_list(token_vector, &index);
	faz_o_urro();
	ast->get_declarations()->push_back(decl_list);

	vector<Command*>* comm_list = commands_list(token_vector, &index);

	ast->get_commands()->push_back(comm_list);

    string tk = token_vector->at(i)->getToken();
	while(tk == "PCOMMA" || tk == "LBRACE" || tk == "ID" || tk == "IF" || tk == "WHILE" || tk == "READ" || tk == "PRINT"){
		comm_list = commands_list(token_vector, &index);
		ast->get_commands()->push_back(comm_list);
		tk = token_vector->at(i)->getToken();
	}

    match(Token("RBRACE",nullptr), &index, token_vector);

	if(*has_erro){
		cout << "Foram encontrados erros sintáticos no código. A compilação não pode continuar." << endl;
		exit(1);
	}else{
		cout << "Análise sintática realizada com sucesso. Nenhum erro foi encontrado." << endl;
		return;
	}
}
