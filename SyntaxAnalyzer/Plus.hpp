#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Plus : public Expr{
public:
	Plus();
	Plus(Expr* e1, Expr* e2);
	~Plus();
	Expr* get_expr_1();
	Expr* get_expr_2();

private:
	Expr* e1;
	Expr* e2;
};
