#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Plus : public Expr{
private:
	Expr* e1;
	Expr* e2;

public:
	Plus(Expr* e1, Expr* e2, string c_type);
	~Plus();
	Expr* get_expr_1();
	Expr* get_expr_2();
};
