#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Eq : public Expr{
public:
	Eq();
	Eq(Expr* e1, Expr* e2);
	~Eq();
	Expr* get_expr_1();
	Expr* get_expr_2();

private:
	Expr* e1;
	Expr* e2;
};
