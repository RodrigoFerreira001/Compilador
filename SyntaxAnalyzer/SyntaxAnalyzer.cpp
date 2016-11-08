#include "SyntaxAnalyzer.hpp"

// ==============================	CONSTRUCTOR	==========================================
SyntaxAnalyzer::SyntaxAnalyzer(AbstractSyntaxTree* ast, vector<Token*>* token_vector){
	this->ast = ast;
	this->token_vector = token_vector;
	has_error = new bool(false);
}


// =============================	FUNCTIONS	============================================
// =====================================================================================

void SyntaxAnalyzer::faz_o_urro(int& index){
	//(flagErro variavel global ou um atributo da classe AnalisadorSintatico)
  *has_error = false;

	match(new Token("LBRACE",token_vector->at(index)->getTableEntry()), index, token_vector);

	vector<Declaration*>* decl_list = declarations_list(token_vector, index);
	ast->set_declarations(decl_list);

	vector<Command*>* comm_list = new vector<Command*>;

  string tk = token_vector->at(index)->getToken();
	while(((token_vector->size() - 1) > index) && (tk == "PCOMMA") || (tk == "LBRACE") || (tk == "ID") || (tk == "IF") ||
	(tk == "WHILE") || (tk == "READ") || (tk == "PRINT")){
		comm_list = commands_list(token_vector, index);
		//ast->get_commands()->push_back(comm_list->at(0));
		cout << "STRING TK: " << tk << endl;
		tk = token_vector->at(index)->getToken();
	}

	cout << "TOMEI ERRO AQUI\n";
	match(new Token("RBRACE",token_vector->at(index)->getTableEntry()), index, token_vector);

	if(*has_error){
		cout << "Foram encontrados erros sintáticos no código. A compilação não pode continuar." << endl;
		exit(1);
	}else{
		cout << "Análise sintática realizada com sucesso. Nenhum erro foi encontrado." << endl;
	}
}

// =====================================================================================

void SyntaxAnalyzer::print_syntactic_error(Token* token){

	cout << "TOKEN ESPERADO: \t" << token->getToken() << endl;
	cout << "TOKEN ENCONTRADO: \t" << token->getTableEntry()->getToken() << endl;
	cout << "LINE: \t\t\t" << token->getTableEntry()->getLineNumber() << endl;
	cout << "POS: \t\t\t" << token->getTableEntry()->getLinePos() << endl;
	cout << "LEXEMA: \t\t" << token->getTableEntry()->getLexeme() << endl;

	if(token->getToken() == "ID" || token->getToken() == "NUMBER"){
		cout << "'" << token->getTableEntry()->getLexeme() << "'' esperado na linha " <<
		token->getTableEntry()->getLineNumber() << endl;
	}else{
		cout << "'" << token->getToken() << "' esperado na linha " <<
		token->getTableEntry()->getLineNumber() << endl;
	}

	cout << "\n\n" << endl;
	exit(1);
}


// =====================================================================================

bool synchronize(Token* token, int& index, vector<Token*>* token_vector){
	return true;
}


// =====================================================================================

bool SyntaxAnalyzer::match(Token* token, int& index, vector<Token*>* token_vector){

	/*
	cout << "TOKEN: " << token->getToken() << endl;
	cout << "TOKEN VECTOR: " << token_vector->at(index)->getToken() << endl;


	cout << "TABLE ENTRY LINE: " << token->getTableEntry()->getLineNumber() << endl;
	cout << "TABLE ENTRY POS: " << token->getTableEntry()->getLinePos() << endl;
	cout << "TABLE ENTRY TOKEN: " << token->getTableEntry()->getToken() << endl;
	cout << "TABLE ENTRY LEXEMA: " << token->getTableEntry()->getLexeme() << endl;
	cout << "TABLE ENTRY TYPE: " << token->getTableEntry()->get_type() << endl;
	cout << "\n\n" << endl;
	*/

	if(token_vector->at(index)->getToken() == token->getToken()){
	//if(token_vector->at(index)->getToken() == token->getTableEntry()->getToken()){
		index++;
	}else{
		*has_error = true;
		print_syntactic_error(token);
		return synchronize(token, index, token_vector);
	}
}


// =====================================================================================

vector<Declaration*>* SyntaxAnalyzer::declarations_list(vector<Token*>* token_vector, int& index){
	int current_type = -1;

	if(token_vector->at(index)->getToken() == "INT" ||  token_vector->at(index)->getToken() == "FLOAT"){
		vector<Declaration*>* decl_list = new vector<Declaration*>;
		current_type = type(token_vector, index);

		if(token_vector->at(index)->getToken() == "ID"){
			token_vector->at(index)->getTableEntry()->set_type(current_type);
			token_vector->at(index)->getTableEntry()->set_var_decl(true);

			Temp* temp = new Temp();
			Declaration* id = new Declaration(token_vector->at(index)->getTableEntry(), true, current_type, temp);
			token_vector->at(index)->getTableEntry()->set_temp(temp);
			decl_list->push_back(id);
			match(new Token("ID",token_vector->at(index)->getTableEntry()), index, token_vector);
		}else{
			print_syntactic_error(new Token("ID", token_vector->at(index)->getTableEntry()));
			synchronize(new Token("ID", token_vector->at(index)->getTableEntry()), index, token_vector);
		}

		vector<Declaration*>* decl_list2 = declarations_list2(token_vector, index, current_type);
		for(int i = 0; i < decl_list2->size(); i++){
			decl_list->push_back(decl_list2->at(i));
		}
		return decl_list;
	}else{
		return new vector<Declaration*>;
	}
}


// =====================================================================================

int SyntaxAnalyzer::type(vector<Token*>* token_vector, int& index){
	int current_type = -1;

	if(token_vector->at(index)->getToken() == "INT"){
		current_type = 0;
		match(new Token("INT", token_vector->at(index)->getTableEntry()), index, token_vector);
	}else
	if(token_vector->at(index)->getToken() == "FLOAT"){
		current_type = 1;
		match(new Token("FLOAT", token_vector->at(index)->getTableEntry()), index, token_vector);
	}

	return current_type;
}


// =====================================================================================

vector<Declaration*>* SyntaxAnalyzer::declarations_list2(vector<Token*>* token_vector, int& index, int current_type){
	if(token_vector->at(index)->getToken() == "COMMA"){

		vector<Declaration*>* decl_list = new vector<Declaration*>;
		match(new Token("COMMA", token_vector->at(index)->getTableEntry()), index, token_vector);

		if(token_vector->at(index)->getToken() == "ID"){
			token_vector->at(index)->getTableEntry()->set_type(current_type);

			Temp* temp = new Temp();
			Declaration* id = new Declaration(token_vector->at(index)->getTableEntry(), true, current_type, temp);
			token_vector->at(index)->getTableEntry()->set_temp(temp);
			decl_list->push_back(id);
			match(new Token("ID", token_vector->at(index)->getTableEntry()), index, token_vector);

		}else{
			print_syntactic_error(token_vector->at(index));
			synchronize(token_vector->at(index), index, token_vector);
		}

		vector<Declaration*>* decl_list2 = declarations_list2(token_vector, index, current_type);
		for(int i = 0; i < decl_list2->size(); i++){
			decl_list->push_back(decl_list2->at(i));
		}

		return decl_list;
	}else
	if(token_vector->at(index)->getToken() == "PCOMMA"){
		match(new Token("PCOMMA", token_vector->at(index)->getTableEntry()), index, token_vector);
		return declarations_list(token_vector, index);
	}

}


// =====================================================================================

vector<Command*>* SyntaxAnalyzer::commands_list(vector<Token*>* token_vector, int& index){
	vector<Command*>* command_vector = new vector<Command*>;

	if(token_vector->at(index)->getToken() == "PCOMMA"){
		match(new Token("PCOMMA", token_vector->at(index)->getTableEntry()), index, token_vector);
	}

	if(token_vector->at(index)->getToken() == "ID"){
		Temp* temp = new Temp;
		Id* id = new Id(token_vector->at(index)->getTableEntry(), true, token_vector->at(index)->getTableEntry()->get_var_decl(), token_vector->at(index)->getTableEntry()->get_type(), temp);

		match(new Token("ID", token_vector->at(index)->getTableEntry()), index, token_vector);
		match(new Token("ATTR", token_vector->at(index)->getTableEntry()), index, token_vector);

		Attr* attr = new Attr(id, expression(token_vector, index));
		match(new Token("PCOMMA", token_vector->at(index)->getTableEntry()), index, token_vector);
		command_vector->push_back(attr);
		return command_vector;
	}

	if(token_vector->at(index)->getToken() == "IF"){
		If* if_;
		match(new Token("IF", token_vector->at(index)->getTableEntry()), index, token_vector);
		match(new Token("LBRACKET", token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e = expression(token_vector, index);
		match(new Token("RBRACKET", token_vector->at(index)->getTableEntry()), index, token_vector);

		vector<Command*>* c = commands_list(token_vector, index);

		if(token_vector->at(index)->getToken() == "ELSE"){
			match(new Token("ELSE", token_vector->at(index)->getTableEntry()), index, token_vector);
			vector<Command*>* c2 = commands_list(token_vector, index);

			if(c2->size() > 0){
				if_ = new If(e, c->at(0), c2->at(0));
				command_vector->push_back(if_);
			}else{
				if_ = new If(e, c->at(0), nullptr);
				command_vector->push_back(if_);
			}
		}
		return command_vector;
	}

	if(token_vector->at(index)->getToken() == "WHILE"){
		match(new Token("WHILE", token_vector->at(index)->getTableEntry()), index, token_vector);
		match(new Token("LBRACKET", token_vector->at(index)->getTableEntry()), index, token_vector);

		Expr* e = expression(token_vector, index);

		match(new Token("RBRACKET", token_vector->at(index)->getTableEntry()), index, token_vector);

		vector<Command*>* c = commands_list(token_vector, index);
		While* w = new While(e, c->at(0));
		command_vector->push_back(w);

		return command_vector;
	}

	if(token_vector->at(index)->getToken() == "READ"){
		match(new Token("READ", token_vector->at(index)->getTableEntry()), index, token_vector);
		if(token_vector->at(index)->getToken() == "ID"){

			Temp* temp = new Temp;
			Id* id = new Id(token_vector->at(index)->getTableEntry(), true, token_vector->at(index)->getTableEntry()->get_var_decl(), token_vector->at(index)->getTableEntry()->get_type(), temp);
			Read* r = new Read(id);
			match(new Token("ID", token_vector->at(index)->getTableEntry()), index, token_vector);
			match(new Token("PCOMMA", token_vector->at(index)->getTableEntry()), index, token_vector);
			command_vector->push_back(r);
			return command_vector;
		}
	}

	if(token_vector->at(index)->getToken() == "PRINT"){
		match(new Token("PRINT", token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e = expression(token_vector, index);
		Print* p = new Print(e);
		match(new Token("PCOMMA", token_vector->at(index)->getTableEntry()), index, token_vector);
		command_vector->push_back(p);
		return command_vector;
	}

	if(token_vector->at(index)->getToken() == "LBRACE"){
		match(new Token("LBRACE", token_vector->at(index)->getTableEntry()), index, token_vector);
		vector<Command*>* c = commands_list(token_vector, index);
		match(new Token("RBRACE", token_vector->at(index)->getTableEntry()), index, token_vector);
		return c;
	}

	return nullptr;
}


// =====================================================================================

Expr* SyntaxAnalyzer::expression(vector<Token*>* token_vector, int& index){
	Expr* e1 = conjunction(token_vector, index);
	if(token_vector->at(index)->getToken() == "OR"){
		match(new Token("OR", token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e2 = conjunction(token_vector, index);
		return new Or(e1, e2);
	}
	return e1;
}


// =====================================================================================

Expr* SyntaxAnalyzer::conjunction(vector<Token*>* token_vector, int& index){
	Expr* e1 = equal(token_vector, index);
	if(token_vector->at(index)->getToken() == "AND"){
		match(new Token("AND", token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e2 = equal(token_vector, index);
		return new And(e1, e2);
	}
	return e1;
}


// =====================================================================================

Expr* SyntaxAnalyzer::equal(vector<Token*>* token_vector, int& index){
	Expr* e1 = relation(token_vector, index);

	if(token_vector->at(index)->getToken() == "EQUAL"){
		match(new Token("EQUAL", token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e2 = relation(token_vector, index);
		return new Eq(e1, e2);
	}

	if(token_vector->at(index)->getToken() == "NE"){
		match(new Token("NE", token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e2 = relation(token_vector, index);
		return new Ne(e1, e2);
	}

	return e1;
}


// =====================================================================================

Expr* SyntaxAnalyzer::relation(vector<Token*>* token_vector, int& index){
	Expr* e1 = plus(token_vector, index);

	if(token_vector->at(index)->getToken() == "LT"){
		match(new Token("LT",token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e2 = plus(token_vector, index);
		Lt* lt = new Lt(e1,e2);
		return lt;
	}

	if(token_vector->at(index)->getToken() == "GT"){
			match(new Token("GT",token_vector->at(index)->getTableEntry()), index, token_vector);
			Expr* e2 = plus(token_vector, index);
			Gt* gt = new Gt(e1,e2);
			return gt;
	}

	if(token_vector->at(index)->getToken() == "LTE"){
			match(new Token("LTE",token_vector->at(index)->getTableEntry()), index, token_vector);
			Expr* e2 = plus(token_vector, index);
			Lte* le = new Lte(e1,e2);
			return le;
	}

	if(token_vector->at(index)->getToken() == "GTE"){
			match(new Token("GTE",token_vector->at(index)->getTableEntry()), index, token_vector);
			Expr* e2 = plus(token_vector, index);
			Gte* ge = new Gte(e1,e2);
			return ge;
	}

	return e1;
}


// =====================================================================================


Expr* SyntaxAnalyzer::plus(vector<Token*>* token_vector, int& index){
	Expr* e1 = term(token_vector, index);

	if(token_vector->at(index)->getToken() == "PLUS"){
		match(new Token("PLUS", token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e2 = term(token_vector, index);
		Plus* a = new Plus(e1,e2);
		return a;
	}

	if(token_vector->at(index)->getToken() == "MINUS"){
		match(new Token("MINUS", token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e2 = term(token_vector, index);
		Minus* m = new Minus(e1,e2);
		return m;
	}

	return e1;
}

Expr* SyntaxAnalyzer::term(vector<Token*>* token_vector, int& index){
	Expr* e1 = factor(token_vector, index);

	if(token_vector->at(index)->getToken() == "TIMES"){
		match(new Token("TIMES",token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e2 = factor(token_vector, index);
		Mult* mu = new Mult(e1,e2);
		return mu;
	}

	if(token_vector->at(index)->getToken() == "DIV"){
		match(new Token("DIV",token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e2 = factor(token_vector, index);
		Div* d = new Div(e1,e2);
		return d;
	}

	return e1;
}


// =====================================================================================


Expr* SyntaxAnalyzer::factor(vector<Token*>* token_vector, int& index){
	int current_type = -1;

	if(token_vector->at(index)->getToken() == "ID"){
		Temp* temp = new Temp;
		Id* id = new Id(token_vector->at(index)->getTableEntry(), false, token_vector->at(index)->getTableEntry()->get_var_decl(), token_vector->at(index)->getTableEntry()->get_type(), temp);
		match(new Token("ID",token_vector->at(index)->getTableEntry()), index, token_vector);
		return id;
	}else
		if(token_vector->at(index)->getToken() == "NUMBER"){
			Num* num = new Num(token_vector->at(index)->getTableEntry(), token_vector->at(index)->getTableEntry()->get_type());
			match(new Token("NUMBER",token_vector->at(index)->getTableEntry()), index, token_vector);
			return num;
		}else
			if(token_vector->at(index)->getToken() == "LBRACKET"){
				match(new Token("LBRACKET",token_vector->at(index)->getTableEntry()), index, token_vector);
				Expr* e = expression(token_vector, index);
				match(new Token("RBRACKET",token_vector->at(index)->getTableEntry()), index, token_vector);
				return e;
			}else{
				printf("Erro! Identificador, número ou abre parênteses esperado na linha ...");
			}
}
