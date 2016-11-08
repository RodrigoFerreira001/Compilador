#pragma once
#include <vector>
using namespace std;

class Command{
private:
	vector<Command*>* children;
	string type_class;

public:
	Command();
	~Command();
	vector<Command*>* get_children();
	string get_type_name();

};
