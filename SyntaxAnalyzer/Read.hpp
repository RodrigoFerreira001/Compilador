#pragma once
#include "Command.hpp"

class Read : public Command{
public:
	Read();
	Read(Id* id);
	~Read();
	Id* get_id();

private:
	Id* id;
};
