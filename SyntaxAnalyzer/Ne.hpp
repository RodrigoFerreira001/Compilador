#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Ne : public Expr{
private:
	Expr* e1;
	Expr* e2;

public:
	Ne(Expr* e1, Expr* e2, string c_type);
	~Ne();
	Expr* get_expr_1();
	Expr* get_expr_2();
};
