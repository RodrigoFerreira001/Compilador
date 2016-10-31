#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Div : public Expr{
public:
	Div();
	Div(Expr* e1, Expr* e2);
	~Div();
	Expr* get_expr_1();
	Expr* get_expr_2();

private:
	Expr* e1;
	Expr* e2;
};
