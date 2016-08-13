#include "readFile.hpp"

int main(int argc, char** argv){

	if(argc < 2){
		printf("Invalid parameters.\n");
		exit(EXIT_FAILURE);
	}

	string* buffer = readFile(argv[1]);

	cout << *buffer << endl;

	return 0;
}