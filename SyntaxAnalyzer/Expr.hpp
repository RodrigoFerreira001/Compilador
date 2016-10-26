#pragma once
#include "Command.hpp"

class Expr : public Command{
private:
	int* type;
	int* i_value;
	float* f_value;
	bool* b_value;

public:
	Expr();
	Expr(int type, int i_value, float f_value, bool b_value);
	~Expr();

	void set_type(int type);
	int get_type();

	void set_i_value(int i_value);
	int get_i_value();

	void set_f_value(float f_value);
	float get_f_value();

	void set_b_value(bool b_value);
	bool get_b_value();
}
