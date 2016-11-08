#pragma once
#include "Command.hpp"
#include "Id.hpp"

class While : public Command{
public:
	While();
	While(Expr* e, Command* c_true);
	~While();
	Expr* get_expr();
	Command* get_c_true();
	string get_type_name();

private:
	string type_class;
	Expr* e;
	Command* c_true;
};
