#pragma once
#include <vector>
#include <string>
using namespace std;

class Command{
private:
	vector<Command*>* children;
	string* c_type;

public:
	Command(string c_type);
	~Command();
	vector<Command*>* get_children();
	string get_c_type();
};
