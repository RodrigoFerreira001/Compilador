#pragma once
#include "Command.hpp"
#include "Id.hpp"

class Attr : public Command{
private:
	Id* id;
	Expr* e;
	
public:
	Attr(Id* id, Expr* e, string c_type);
	~Attr();
	Id* get_id();
	Expr* get_expr();
};
