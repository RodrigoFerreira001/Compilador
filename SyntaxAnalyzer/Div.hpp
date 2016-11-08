#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Div : public Expr{
private:
	Expr* e1;
	Expr* e2;

public:
	Div(Expr* e1, Expr* e2, string c_type);
	~Div();
	Expr* get_expr_1();
	Expr* get_expr_2();
};
