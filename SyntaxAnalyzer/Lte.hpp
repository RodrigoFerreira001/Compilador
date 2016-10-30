#pragma once
#include "Expr.hpp"

class Lte : public Expr{
public:
	Lte();
	Lte(Expr* e1, Expr* e2);
	~Lte();
	Expr* get_expr_1();
	Expr* get_expr_2();

private:
	Expr* e1;
	Expr* e2;	
};
