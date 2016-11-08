#pragma once
#include "Command.hpp"
#include "Id.hpp"

class Attr : public Command{
public:
	Attr();
	Attr(Id* id, Expr* e);
	~Attr();
	Id* get_id();
	Expr* get_expr();

	private:
		Id* id;
		Expr* e;
};
