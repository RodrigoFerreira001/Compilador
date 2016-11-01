printSyntacticError(token){
	if(token.getNome() == “ID” || token.getNome() == “NUMBER”)
		printf(“%s esperado na linha %d”, token.getNome(), token.getNumLinha()); 
	else{
		printf(“%s esperado na linha %d”, token.getLexema(), token.getNumLinha()); 	
	}
}


bool match(int token, indice, )
{
    if(w[i].getTk() == token.getTk()
    {
        i++;
    }
    else
    {
        printSyntacticError(token);
	flagErro = 1;
        bool recuperouDoErro = sincroniza(w[i],token);
	return recuperouDoErro; 
    }
}


Programa prog;

Programa Programa_()
{
    //(flagErro variavel global ou um atributo da classe AnalisadorSintatico) 
    int flagErro = 0; 

    match(LBRACE);
    List<Declaracao> listaDeclaracoes = Declaracoes();
    prog = new Programa();
    prog.adicionaNosFilhos(listaDeclaracoes);

    List<Comando> listComandos = Comandos();
    prog.adicionaNosFilhos(listComandos);
    while (w[i] == PCOMMA || w[i] == LBRACE || w[i] == ID || w[i] == IF || w[i] == WHILE || w[i] == READ || w[i] == PRINT){
        listComandos = Comandos();
        prog.adicionaNosFilhos(listComandos);///Percorre a lista adicionando todo objeto Comando como um novo nó flho de prog
    }
    match(RBRACE);

    if(flagErro) {
	print("Foram encontrados erros sintáticos no código. A compilação não pode continuar.");
	exit(1); 
    }
    else print("Análise sintática realizada com sucesso. Nenhum erro foi encontrado. ");
    return prog;
}

List<Declaracao> Declaracoes()
{
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


int Tipo()
{
    int currentType = -1;
    if(w[i] == INT)
    {
        currentType = 0;
        match(INT);
    }
    else if(w[i] == FLOAT)
    {
        currentType = 1;
        match(FLOAT);
    }
    return currentType;
}

List<Declaracao> Decl2(int currentType)
{
    if(w[i] == COMMA)
    {
        List<Declaracao> declList = new ArrayList();
        match(COMMA);
        if(w[i] == ID)
        {
            w[i].getEntry().setType(currentType);
            //w[i].getEntry().setIsVarDecl(true);
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
    else if(w[i] == PCOMMA)
    {
        match(PCOMMA);
        return Declaracoes();
    }
}

List<Comando> Comandos()
{
    List<Comando> listComandos = new ArrayList();
    if(w[i] == PCOMMA) match(PCOMMA);
    if(w[i] == LBRACE)
    {
        match(LBRACE);
        List<Comando> lc = Comandos();
        match(RBRACE);
        return lc;
    }
    if(w[i] == ID)
    {
        ///Todos os tokens ID apontam para a entrada da tabela de símbolos que se refere à declaração daquele ID
        ///TableEntry te = buscaDeclaracaoNaTabSimbolos(w[i].getEntry().lexema) - Mais trabalhoso
        Identificador id = new Identificador(w[i].getEntry());
        id.setIsLValue(true);
        match(ID);
	match(ATTR);
        Attr attr = new Attr(id,Expressao());
        match(PCOMMA);
        listComandos.add(attr);
        return listComandos;
    }
    if(w[i] == IF)
    {
        IF if_;
        match(IF);
        match(LBRACKET);
        Expr e = Expressao();
        match(RBRACKET);
        List<Comando> lc = Comandos();
        if(w[i] == ELSE)
        {
            match(ELSE);
            List<Comando> lc2 = Comandos();
        }
        if(lc2.size() > 0)
        {
            if_ = new IF(e,lc,lc2);            
        }
        else if_ = new IF(e,lc,nullptr);
        listComandos.add(if_);
        return listComandos;
    }
    if(w[i] == WHILE)
    {
        match(WHILE);
        match(LBRACKET);
        Expr e = Expressao();
        match(RBRACKET);
        List<Comando> lc = Comando();
        While w = new While(e,lc);
        listComandos.add(w);
        return listComandos;
    }
    if(w[i] == READ)
    {
        match(READ);
        if(w[i] == ID)
        {
            Identificador id = new Identificador(w[i].getEntry());
            ///a entrada da tabela já guarda todas as informaçoes sobre esse ID
            Read r = new Read(id);
            match(ID);
            match(PCOMMA);
            listComandos.add(r);
            return listComandos;
        }
    }
    if(w[i] == PRINT)
    {
        match(PRINT);
        Expr e = Expressao();
        Print p = new Print(e);
        match(PCOMMA);
        listComandos.add(p);
        return listComandos;
    }
    return nullptr;
}


Expr Expressao()
{
    Expr e1 = Conjuncao();
    if(w[i] == OR)
    {
        match(OR);
        Expr e2 = Conjuncao();
        return new Or(e1,e2);
    }
    return e1;
}

Expr Conjuncao()
{
    Expr e1 = Igualdade();
    if(w[i] == AND)
    {
        match(AND);
        Expr e2 = Igualdade();
        And and = new And(e1,e2);
        return and;
    }
    return e1;
}

Expr Igualdade()
{
    Expr e1 = Relacao();
    if(w[i] == EQUAL)
    {
        match(EQUAL);
        Expr e2 = Relacao();
        Equal eq = new Equal(e1,e2);
        return eq;
    }
    if(w[i] == NE)
    {
        match(NE);
        Expr e2 = Relacao();
        NotEqual ne = new NotEqual(e1,e2);
        return ne;
    }
    return e1;
}

Expr Relacao()
{
    Expr e1 = Adicao();
    if(w[i] == LT)
    {
        match(LT);
        Expr e2 = Adicao();
        LessThan lt = new LessThan(e1,e2);
        return lt;
    }
    if(w[i] == GT)
    {
        match(GT);
        Expr e2 = Adicao();
        GreaterThan gt = new GreaterThan(e1,e2);
        return gt;
    }
    if(w[i] == LE)
    {
        match(LE);
        Expr e2 = Adicao();
        LessThanEqual le = new LessThanEqual(e1,e2);
        return lt;
    }
    if(w[i] == GE)
    {
        match(GE);
        Expr e2 = Adicao();
        GreaterThanEqual ge = new GreaterThanEqual(e1,e2);
        return ge;
    }
    return e1;
}

Expr Adicao()
{
    Expr e1 = Termo();
    if(w[i] == PLUS)
    {
        match(PLUS);
        Expr e2 = Termo();
        Add a = new Add(e1,e2);
        return a;
    }
    if(w[i] == MINUS)
    {
        match(MINUS);
        Expr e2 = Termo();
        Minus m = new Minus(e1,e2);
        return m;
    }
    return e1;
}

Expr Termo()
{
    Expr e1 = Fator();
    if(w[i] == TIMES)
    {
        match(TIMES);
        Expr e2 = Fator();
        Mult mu = new Mult(e1,e2);
        return mu;
    }
    if(w[i] == DIV)
    {
        match(DIV);
        Expr e2 = Fator();
        Div d = new Div(e1,e2);
        return d;
    }
    return e1;
}

Expr Fator()
{
    if(w[i] == ID)
    {
        Identificador id = new Identificador(w[i].getEntry());
        match(ID);
        return id;
    }
    else if(w[i] == NUMBER)
    {
        Numero num = new Numero(w[i].getEntry());
        match(NUMBER);
        return num;
    }
    else if(w[i] == LBRACKET)
    {
        match(LBRACKET);
        Expr e = Expressao();
        match(RBRACKET);
        return e;
    }
    else printf("Erro! Identificador, número ou abre parênteses esperado na linha ...");
}
