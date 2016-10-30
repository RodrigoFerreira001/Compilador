#pragma once
#include "Expr.hpp"

class Lt : public Expr{
public:
	Lt();
	Lt(Expr* e1, Expr* e2);
	~Lt();
	Expr* get_expr_1();
	Expr* get_expr_2();

private:
	Expr* e1;
	Expr* e2;
};
