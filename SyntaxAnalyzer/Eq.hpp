#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Eq : public Expr{
private:
	Expr* e1;
	Expr* e2;

public:
	Eq(Expr* e1, Expr* e2, string c_type);
	~Eq();
	Expr* get_expr_1();
	Expr* get_expr_2();
};
