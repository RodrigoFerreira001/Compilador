#pragma once
#include "Expr.hpp"

class Minus : public Expr{
public:
	Minus();
	Minus(Expr* e1, Expr* e2);
	~Minus();
	Expr* get_expr_1();
	Expr* get_expr_2();

private:
	Expr* e1;
	Expr* e2;
};
