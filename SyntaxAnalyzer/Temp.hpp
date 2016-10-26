#pragma once
#include <string>
using namespace std;

class Temp{
private:
	static int name_id = 0;
	string* name;
public:
	Temp();
	~Temp();
	string get_name();
};
