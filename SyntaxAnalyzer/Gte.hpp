#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Gte : public Expr{
public:
	Gte();
	Gte(Expr* e1, Expr* e2);
	~Gte();
	Expr* get_expr_1();
	Expr* get_expr_2();

private:
	Expr* e1;
	Expr* e2;
};
