#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Lte : public Expr{
private:
	Expr* e1;
	Expr* e2;

public:
	Lte(Expr* e1, Expr* e2, string c_type);
	~Lte();
	Expr* get_expr_1();
	Expr* get_expr_2();
};
