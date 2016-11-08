#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Gte : public Expr{
private:
	Expr* e1;
	Expr* e2;

public:
	Gte(Expr* e1, Expr* e2, string c_type);
	~Gte();
	Expr* get_expr_1();
	Expr* get_expr_2();
};
