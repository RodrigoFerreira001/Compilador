#pragma once
#include "Expr.hpp"
#include "Id.hpp"

class Lt : public Expr{
private:
	Expr* e1;
	Expr* e2;

public:
	Lt(Expr* e1, Expr* e2, string c_type);
	~Lt();
	Expr* get_expr_1();
	Expr* get_expr_2();
};
