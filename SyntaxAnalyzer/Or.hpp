#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Or : public Expr{
public:
	Or();
	~Or();
	Or(Expr* e1, Expr* e2, string c_type);
	Expr* get_expr_1();
	Expr* get_expr_2();

private:
	Expr* e1;
	Expr* e2;
};
