#include "SyntaxAnalyzer.hpp"

void SyntaxAnalyzer::faz_o_urro(int& index){
	//(flagErro variavel global ou um atributo da classe AnalisadorSintatico)
    *has_error = false;

	match(new Token("LBRACE",token_vector->at(index)->getTableEntry()), index, token_vector);

	vector<Declaration*>* decl_list = declarations_list(token_vector, index);
	ast->set_declarations(decl_list);

	vector<Command*>* comm_list = new vector<Command*>;

    string tk = token_vector->at(index)->getToken();
	while(((token_vector->size() - 1) > index) && tk == "PCOMMA" || tk == "LBRACE" || tk == "ID" || tk == "IF" || tk == "WHILE" || tk == "READ" || tk == "PRINT"){
		comm_list = commands_list(token_vector, index);
        for(int i = 0; i < comm_list->size(); ++i)
		      ast->get_commands()->push_back(comm_list->at(i));
		tk = token_vector->at(index)->getToken();
	}

    match(new Token("RBRACE",token_vector->at(index)->getTableEntry()), index, token_vector);

	if(*has_error){
		cout << "Foram encontrados erros sintáticos no código. A compilação não pode continuar." << endl;
		exit(1);
	}else{
		cout << "Análise sintática realizada com sucesso. Nenhum erro foi encontrado." << endl;
	}
}

void SyntaxAnalyzer::print_ast(Command* c, int& index){
	if(c->get_c_type() == "AND"){
		And* a = (And*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << a->get_c_type() << endl;
		index++;
		print_ast(a->get_expr_1(), index);
		index++;
		print_ast(a->get_expr_2(), index);
		index--;
	}else
	if(c->get_c_type() == "ATTR"){
		Attr* a = (Attr*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << a->get_c_type() << endl;
		index++;
		print_ast(a->get_id(), index);
		index++;
		print_ast(a->get_expr(), index);
		index--;
	}else
	if(c->get_c_type() == "DIV"){
		Div* d = (Div*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << d->get_c_type() << endl;
		index++;
		print_ast(d->get_expr_1(), index);
		index++;
		print_ast(d->get_expr_2(), index);
		index--;
	}else
	if(c->get_c_type() == "EQ"){
		Eq* e = (Eq*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << e->get_c_type() << endl;
		index++;
		print_ast(e->get_expr_1(), index);
		index++;
		print_ast(e->get_expr_2(), index);
		index--;
	}else
	if(c->get_c_type() == "EXPR"){
		Expr* e = (Expr* ) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << e->get_c_type() << endl;
		index--;
	}else
	if(c->get_c_type() == "GT"){
		Gt* g = (Gt*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << g->get_c_type() << endl;
		index++;
		print_ast(g->get_expr_1(), index);
		index++;
		print_ast(g->get_expr_2(), index);
		index--;
	}else
	if(c->get_c_type() == "GTE"){
		Gte* g = (Gte*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << g->get_c_type() << endl;
		index++;
		print_ast(g->get_expr_1(), index);
		index++;
		print_ast(g->get_expr_2(), index);
		index--;
	}else
	if(c->get_c_type() == "ID"){
		Id* i = (Id*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << i->get_c_type() << endl;
		index--;
	}else
	if(c->get_c_type() == "IF"){
		If* i = (If*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << i->get_c_type() << endl;
		index++;
		print_ast(i->get_expr(), index);
		if(i->get_c_false() != nullptr){
			index++;
			print_ast(i->get_c_false(), index);
		}
		index++;
		print_ast(i->get_c_true(), index);
		index--;
	}else
	if(c->get_c_type() == "LT"){
		Lt* l = (Lt*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << l->get_c_type() << endl;
		index++;
		print_ast(l->get_expr_1(), index);
		index++;
		print_ast(l->get_expr_2(), index);
		index--;
	}else
	if(c->get_c_type() == "LTE"){
		Lte* l = (Lte*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << l->get_c_type() << endl;
		index++;
		print_ast(l->get_expr_1(), index);
		index++;
		print_ast(l->get_expr_2(), index);
		index--;
	}else
	if(c->get_c_type() == "MINUS"){
		Minus* m = (Minus*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << m->get_c_type() << endl;
		index++;
		print_ast(m->get_expr_1(), index);
		index++;
		print_ast(m->get_expr_2(), index);
		index--;
	}else
	if(c->get_c_type() == "MULT"){
		Mult* m = (Mult*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << m->get_c_type() << endl;
		index++;
		print_ast(m->get_expr_1(), index);
		index++;
		print_ast(m->get_expr_2(), index);
		index--;
	}else
	if(c->get_c_type() == "NE"){
		Ne* n = (Ne*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << n->get_c_type() << endl;
		index++;
		print_ast(n->get_expr_1(), index);
		index++;
		print_ast(n->get_expr_2(), index);
		index--;
	}else
	if(c->get_c_type() == "NUM"){
		Num* n = (Num*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << n->get_c_type() << endl;
		index--;
	}else
	if(c->get_c_type() == "OR"){
		Or* o = (Or*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << o->get_c_type() << endl;
		index++;
		print_ast(o->get_expr_1(), index);
		index++;
		print_ast(o->get_expr_2(), index);
		index--;
	}else
	if(c->get_c_type() == "PLUS"){
		Plus* p = (Plus*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << p->get_c_type() << endl;
		index++;
		print_ast(p->get_expr_1(), index);
		index++;
		print_ast(p->get_expr_2(), index);
		index--;
	}else
	if(c->get_c_type() == "PRINT"){
		Print* p = (Print*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << p->get_c_type() << endl;
		index++;
		print_ast(p->get_expr(), index);
		index--;
	}else
	if(c->get_c_type() == "READ"){
		Read* r = (Read*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << r->get_c_type() << endl;
		index++;
		print_ast(r->get_id(), index);
		index--;
	}else
	if(c->get_c_type() == "WHILE"){
		While* w = (While*) c;
		for(int j = 0; j < index; j++){
			cout << "_";
		}
		cout << w->get_c_type() << endl;
		index++;
		print_ast(w->get_expr(), index);
		index++;
		print_ast(w->get_c_true(), index);
		index--;
	}
}


void SyntaxAnalyzer::print_syntactic_error(Token* token){

	cout << "TOKEN ESPERADO:_" << token->getToken() << endl;
	cout << "TOKEN ENCONTRADO:_" << token->getTableEntry()->getToken() << endl;
	cout << "LEXEMA:___" << token->getTableEntry()->getLexeme() << endl;
	cout << "LINHA:___" << token->getTableEntry()->getLineNumber() << endl;
	cout << "POS:___" << token->getTableEntry()->getLinePos() << endl;

	if(token->getToken() == "ID" || token->getToken() == "NUMBER"){
		cout << token->getTableEntry()->getLexeme() << " esperado na linha " <<
		token->getTableEntry()->getLineNumber() - 1<< endl;
	}else{
		cout << token->getToken() << " esperado na linha " <<
		token->getTableEntry()->getLineNumber() - 1 << endl;
	}

	exit(1);
}




bool synchronize(Token* token, int& index, vector<Token*>* token_vector){
	return true;
}




bool SyntaxAnalyzer::match(Token* token, int& index, vector<Token*>* token_vector){
	if(token_vector->at(index)->getToken() == token->getToken()){
		index++;
	}else{
		*has_error = true;
		print_syntactic_error(token);
		return synchronize(token, index, token_vector);
	}
}




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




vector<Command*>* SyntaxAnalyzer::commands_list(vector<Token*>* token_vector, int& index){
	vector<Command*>* command_vector = new vector<Command*>;

	if(token_vector->at(index)->getToken() == "PCOMMA"){
		match(new Token("PCOMMA", token_vector->at(index)->getTableEntry()), index, token_vector);
	}

    // ================================================================================================

	if(token_vector->at(index)->getToken() == "LBRACE"){
		match(new Token("LBRACE", token_vector->at(index)->getTableEntry()), index, token_vector);

        vector<Command*>* c = nullptr;
        string tq = token_vector->at(index)->getToken();
        while(tq == "ID" || tq == "PRINT" || tq == "READ" || tq == "WHILE" || tq == "IF"){
		        c = commands_list(token_vector, index);
            tq = token_vector->at(index)->getToken();
        }

		match(new Token("RBRACE", token_vector->at(index)->getTableEntry()), index, token_vector);
		return c;
	}

    // ================================================================================================

	if(token_vector->at(index)->getToken() == "ID"){
		Temp* temp = new Temp;
		Id* id = new Id(token_vector->at(index)->getTableEntry(), true, token_vector->at(index)->getTableEntry()->get_var_decl(), token_vector->at(index)->getTableEntry()->get_type(), temp, "ID");

		match(new Token("ID", token_vector->at(index)->getTableEntry()), index, token_vector);
		match(new Token("ATTR", token_vector->at(index)->getTableEntry()), index, token_vector);

		Attr* attr = new Attr(id, expression(token_vector, index), "ATTR");
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
				if_ = new If(e, c->at(0), c2->at(0), "IF");
				command_vector->push_back(if_);
			}else{
				if_ = new If(e, c->at(0), nullptr, "IF");
				command_vector->push_back(if_);
			}
		}else{
            if_ = new If(e, c->at(0), nullptr, "IF");
            command_vector->push_back(if_);
        }
		return command_vector;
	}

	if(token_vector->at(index)->getToken() == "WHILE"){
		match(new Token("WHILE", token_vector->at(index)->getTableEntry()), index, token_vector);
		match(new Token("LBRACKET", token_vector->at(index)->getTableEntry()), index, token_vector);

		Expr* e = expression(token_vector, index);

		match(new Token("RBRACKET", token_vector->at(index)->getTableEntry()), index, token_vector);
		vector<Command*>* c = commands_list(token_vector, index);
		While* w = new While(e, c->at(0), "WHILE");
		command_vector->push_back(w);
		return command_vector;
	}

	if(token_vector->at(index)->getToken() == "READ"){
		match(new Token("READ", token_vector->at(index)->getTableEntry()), index, token_vector);
		if(token_vector->at(index)->getToken() == "ID"){

			Temp* temp = new Temp;
			Id* id = new Id(token_vector->at(index)->getTableEntry(), true, token_vector->at(index)->getTableEntry()->get_var_decl(), token_vector->at(index)->getTableEntry()->get_type(), temp, "ID");
			Read* r = new Read(id, "READ");
			match(new Token("ID", token_vector->at(index)->getTableEntry()), index, token_vector);
			match(new Token("PCOMMA", token_vector->at(index)->getTableEntry()), index, token_vector);
			command_vector->push_back(r);
			return command_vector;
		}
	}

	if(token_vector->at(index)->getToken() == "PRINT"){
		match(new Token("PRINT", token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e = expression(token_vector, index);
		Print* p = new Print(e, "PRINT");
		match(new Token("PCOMMA", token_vector->at(index)->getTableEntry()), index, token_vector);
		command_vector->push_back(p);
		return command_vector;
	}

	return command_vector;
}




Expr* SyntaxAnalyzer::expression(vector<Token*>* token_vector, int& index){
	Expr* e1 = conjunction(token_vector, index);
	if(token_vector->at(index)->getToken() == "OR"){
		match(new Token("OR", token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e2 = conjunction(token_vector, index);
		return new Or(e1, e2, "OR");
	}
	return e1;
}


Expr* SyntaxAnalyzer::conjunction(vector<Token*>* token_vector, int& index){
	Expr* e1 = equal(token_vector, index);
	if(token_vector->at(index)->getToken() == "AND"){
		match(new Token("AND", token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e2 = equal(token_vector, index);
		return new And(e1, e2, "AND");
	}
	return e1;
}


Expr* SyntaxAnalyzer::equal(vector<Token*>* token_vector, int& index){
	Expr* e1 = relation(token_vector, index);

	if(token_vector->at(index)->getToken() == "EQUAL"){
		match(new Token("EQUAL", token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e2 = relation(token_vector, index);
		return new Eq(e1, e2, "EQUAL");
	}

	if(token_vector->at(index)->getToken() == "NE"){
		match(new Token("NE", token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e2 = relation(token_vector, index);
		return new Ne(e1, e2, "NE");
	}
	return e1;
}

Expr* SyntaxAnalyzer::relation(vector<Token*>* token_vector, int& index){
	Expr* e1 = plus(token_vector, index);

	if(token_vector->at(index)->getToken() == "LT"){
		match(new Token("LT",token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e2 = plus(token_vector, index);
		Lt* lt = new Lt(e1, e2, "LT");
		return lt;
	}else
	if(token_vector->at(index)->getToken() == "GT"){
			match(new Token("GT",token_vector->at(index)->getTableEntry()), index, token_vector);
			Expr* e2 = plus(token_vector, index);
			Gt* gt = new Gt(e1, e2, "GT");
			return gt;
	}else
	if(token_vector->at(index)->getToken() == "LTE"){
			match(new Token("LTE",token_vector->at(index)->getTableEntry()), index, token_vector);
			Expr* e2 = plus(token_vector, index);
			Lte* le = new Lte(e1, e2, "LTE");
			return le;
	}else
	if(token_vector->at(index)->getToken() == "GTE"){
			match(new Token("GTE",token_vector->at(index)->getTableEntry()), index, token_vector);
			Expr* e2 = plus(token_vector, index);
			Gte* ge = new Gte(e1, e2, "GTE");
			return ge;
	}

	return e1;
}

Expr* SyntaxAnalyzer::plus(vector<Token*>* token_vector, int& index){
	Expr* e1 = term(token_vector, index);
	if(token_vector->at(index)->getToken() == "PLUS"){
		match(new Token("PLUS", token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e2 = term(token_vector, index);
		Plus* a = new Plus(e1, e2, "PLUS");
		return a;
	}else{
		if(token_vector->at(index)->getToken() == "MINUS"){
			match(new Token("MINUS", token_vector->at(index)->getTableEntry()), index, token_vector);
			Expr* e2 = term(token_vector, index);
			Minus* m = new Minus(e1, e2, "MINUS");
			return m;
		}
	}
	return e1;
}

Expr* SyntaxAnalyzer::term(vector<Token*>* token_vector, int& index){
	Expr* e1 = factor(token_vector, index);
	if(token_vector->at(index)->getToken() == "TIMES"){
		match(new Token("TIMES",token_vector->at(index)->getTableEntry()), index, token_vector);
		Expr* e2 = factor(token_vector, index);
		Mult* mu = new Mult(e1, e2, "MULT");
		return mu;
	}else{
		if(token_vector->at(index)->getToken() == "DIV"){
			match(new Token("DIV",token_vector->at(index)->getTableEntry()), index, token_vector);
			Expr* e2 = factor(token_vector, index);
			Div* d = new Div(e1, e2, "DIV");
			return d;
		}
	}
	return e1;
}

Expr* SyntaxAnalyzer::factor(vector<Token*>* token_vector, int& index){
	int current_type = -1;

	if(token_vector->at(index)->getToken() == "ID"){
		Temp* temp = new Temp;
		Id* id = new Id(token_vector->at(index)->getTableEntry(), false, token_vector->at(index)->getTableEntry()->get_var_decl(), token_vector->at(index)->getTableEntry()->get_type(), temp, "ID");
		match(new Token("ID",token_vector->at(index)->getTableEntry()), index, token_vector);
		return id;
	}else
	if(token_vector->at(index)->getToken() == "NUMBER"){
		Num* num = new Num(token_vector->at(index)->getTableEntry(), token_vector->at(index)->getTableEntry()->get_type(), "NUM");
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


SyntaxAnalyzer::SyntaxAnalyzer(AbstractSyntaxTree* ast, vector<Token*>* token_vector){
	this->ast = ast;
	this->token_vector = token_vector;
	has_error = new bool(false);
}
