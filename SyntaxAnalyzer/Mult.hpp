#pragma once
#include "Expr.hpp"

class Mult : public Expr{
public:
	Mult();
	Mult(Expr* e1, Expr* e2);
	~Mult();
	Expr* get_expr_1();
	Expr* get_expr_2();

private:
	Expr* e1;
	Expr* e2;
};
