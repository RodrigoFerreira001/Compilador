#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Ne : public Expr{
public:
	Ne();
	Ne(Expr* e1, Expr* e2);
	~Ne();
	Expr* get_expr_1();
	Expr* get_expr_2();

private:
	Expr* e1;
	Expr* e2;
};
