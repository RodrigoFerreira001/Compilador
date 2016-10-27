#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv){

	string class_name = string(argv[1]);
	string class_ext = string(argv[2]);

	ofstream o_cpp(string(class_name + ".cpp").c_str());
	ofstream o_hpp(string(class_name + ".hpp").c_str());

	//Write hpp file
	o_hpp << "#include \"" + class_ext + ".hpp\"" << endl << endl;
	o_hpp << "class " + class_name + " : public " + class_ext + "{" << endl;
	o_hpp << "public:" << endl;
	o_hpp << "\t" + class_name + "();" << endl;
	o_hpp << "\t~" + class_name + "();" << endl;
	o_hpp << "};";

	//Write cpp file
	o_cpp << "#include \"" + class_name + ".hpp\"" << endl << endl;
	o_cpp << class_name + "::" + class_name + "(){\n\t\n}" << endl << endl;
	o_cpp << class_name + "::~" + class_name + "(){\n\t\n}" << endl;

	o_hpp.close();
	o_cpp.close();

	return 0;
}
