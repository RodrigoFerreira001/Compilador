#include <vector>
using namespace std;

class Command{
private:
	vector<Command*>* children;

public:
	Command();
	~Command();
	void append_child(Command* c);
	vector<Command*>* get_children();
};
