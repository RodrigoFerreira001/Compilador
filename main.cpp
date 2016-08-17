#include "Buffer.hpp"

int main(int argc, char** argv){

	if(argc < 2) {
		printf("Invalid parameters.\n");
		exit(EXIT_FAILURE);
	}
	stringstream aux(argv[1]);
	int bufferSize;
	aux >> bufferSize;

	Buffer buffer(bufferSize);
	buffer.load(argv[2]);
	//buffer.print();

	

	return 0;
}