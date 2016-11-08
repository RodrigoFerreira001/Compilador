#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class And : public Expr{
public:
	And();
	And(Expr* e1, Expr* e2, string type);
	~And();
	Expr* get_expr_1();
	Expr* get_expr_2();

private:
	Expr* e1;
	Expr* e2;
};
