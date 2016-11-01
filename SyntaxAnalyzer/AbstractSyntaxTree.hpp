#pragma once
#include "Declaration.hpp"
#include "Command.hpp"
#include "And.hpp"
#include "Attr.hpp"
#include "Div.hpp"
#include "Eq.hpp"
#include "Expr.hpp"
#include "Gt.hpp"
#include "Gte.hpp"
#include "Id.hpp"
#include "If.hpp"
#include "Lt.hpp"
#include "Lte.hpp"
#include "Minus.hpp"
#include "Mult.hpp"
#include "Ne.hpp"
#include "Num.hpp"
#include "Or.hpp"
#include "Plus.hpp"
#include "Print.hpp"
#include "Read.hpp"
#include "While.hpp"
#include <vector>

class AbstractSyntaxTree{
private:
	vector<Declaration>* declarations;
	vector<Command>* commands;

public:
	AbstractSyntaxTree();
	~AbstractSyntaxTree();
	void set_declarations(vector<Declaration>* declarations);
	void set_commands(vector<Command>* commands);
	vector<Declaration>* get_declarations();
	vector<Command>* get_commands();
};
