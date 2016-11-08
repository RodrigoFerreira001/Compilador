#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Gt : public Expr{
private:
	Expr* e1;
	Expr* e2;

public:
	Gt();
	Gt(Expr* e1, Expr* e2, string c_type);
	~Gt();
	Expr* get_expr_1();
	Expr* get_expr_2();
};
