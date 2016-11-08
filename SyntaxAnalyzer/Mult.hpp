#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Mult : public Expr{
private:
	Expr* e1;
	Expr* e2;

public:
	Mult(Expr* e1, Expr* e2, string c_type);
	~Mult();
	Expr* get_expr_1();
	Expr* get_expr_2();
};
