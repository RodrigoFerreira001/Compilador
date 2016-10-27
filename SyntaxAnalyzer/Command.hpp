#pragma once
#include <vector>
using namespace std;

class Command{
private:
	vector<Command*>* children;

public:
	Command();
	~Command();
	vector<Command*>* get_children();
};
