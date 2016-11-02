#include "SyntaxAnalyzer.hpp"

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


SyntaxAnalyzer::SyntaxAnalyzer(AbstractSyntaxTree* ast, vector<Token*>* token_vector){
	this->ast = ast;
	this->token_vector = token_vector;
}

void SyntaxAnalyzer::faz_o_urro(){

}
