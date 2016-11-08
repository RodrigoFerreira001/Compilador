#pragma once
#include "Command.hpp"
#include "Id.hpp"

class Read : public Command{
public:
	Read();
	Read(Id* id);
	~Read();
	Id* get_id();
	string get_type_name();

private:
	Id* id;
	string type_class;
};
