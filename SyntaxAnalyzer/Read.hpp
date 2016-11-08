#pragma once
#include "Command.hpp"
#include "Id.hpp"

class Read : public Command{
private:
	Id* id;

public:
	Read(Id* id, string c_type);
	~Read();
	Id* get_id();
};
