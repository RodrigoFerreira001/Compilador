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
			match(token_vector->at(i), index, token_vector);
		}else{
			print_syntactic_error(token_vector->at(i));
			synchronize(token_vector->at(i), index, int token_vector);
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

SyntaxAnalyzer::SyntaxAnalyzer(AbstractSyntaxTree* ast, vector<Token*>* token_vector){
	this->ast = ast;
	this->token_vector = token_vector;
}

void SyntaxAnalyzer::faz_o_urro(){

}
