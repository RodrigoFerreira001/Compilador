#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class And : public Expr{
private:
	Expr* e1;
	Expr* e2;

public:
	And(Expr* e1, Expr* e2, string c_type);
	~And();
	Expr* get_expr_1();
	Expr* get_expr_2();
};
