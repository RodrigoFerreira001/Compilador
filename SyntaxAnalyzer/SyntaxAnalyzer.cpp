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

vector<Declaration> SyntaxAnalyzer::declarations_list(vector<Token*>* token_vector, int index){
	int currentType = -1;
    if(w[i] == INT || w[i] == FLOAT)
    {
        List<Declaracao> declList = new ArrayList();
        currentType = Tipo(); ///0 = INT, 1 = FLOAT
        if(w[i] == ID)
        {
            w[i].getEntry().setType(currentType);
            w[i].getEntry().setIsVarDecl(true);
            /**
            A classe Temp gera um novo temporário a cada instanciação. O número de temporários é ilimitado.
            Um temporário é uma abstração para um registrador ou para uma posição de memória.
            */
            Temp temp = new Temp();///o nome do novo temporário é definido no construtor
            Declaracao id = new Declaracao(w[i].getEntry(),temp);
            w[i].getEntry().setTemp(temp);
            declList.add(id);
            match(ID);
        }
        else
        {
            imprimeErro(ID);
            sincroniza(ID);
        }
        List<Declaracao> declList2 = Decl2(currentType);
        declList.add(declList2);
        return declList;
    }
    else return nullptr; ///else não faz nada Declaracoes -> e
}

int SyntaxAnalyzer::type(vector<Token*>* token_vector, int index){

}

SyntaxAnalyzer::SyntaxAnalyzer(AbstractSyntaxTree* ast, vector<Token*>* token_vector){
	this->ast = ast;
	this->token_vector = token_vector;
}

void SyntaxAnalyzer::faz_o_urro(){

}
