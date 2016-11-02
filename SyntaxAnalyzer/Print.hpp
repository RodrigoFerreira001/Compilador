#pragma once
#include "Command.hpp"
#include "Id.hpp"

class Print : public Command{
public:
<<<<<<< HEAD
	Print();
=======
>>>>>>> fcf17136218d8d372735ac63b5e481aa09493d15
	Print(Expr* e);
	~Print();
	Expr* get_expr();

private:
	Expr* e;
};
