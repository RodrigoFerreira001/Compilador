#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Minus : public Expr{
private:
	Expr* e1;
	Expr* e2;

public:
	Minus(Expr* e1, Expr* e2, string c_type);
	~Minus();
	Expr* get_expr_1();
	Expr* get_expr_2();
};
