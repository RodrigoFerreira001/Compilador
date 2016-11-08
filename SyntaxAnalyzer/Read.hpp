#pragma once
#include "Command.hpp"
#include "Id.hpp"

class Read : public Command{
public:
	Read();
	Read(Id* id);
	~Read();
	Id* get_id();

private:
	Id* id;
};
