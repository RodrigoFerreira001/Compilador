#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Or : public Expr{
private:
	Expr* e1;
	Expr* e2;

public:
	Or(Expr* e1, Expr* e2, string c_type);
	~Or();
	Expr* get_expr_1();
	Expr* get_expr_2();
};
