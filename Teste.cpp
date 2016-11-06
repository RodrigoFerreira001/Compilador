#include <iostream>
using namespace std;

void function(int& num){
	for(int i = 0; i < 10; i++){
		num++;
	}
}


int main(){

	int mun = 0;
	cout << mun << endl;
	function(mun);
	cout << mun << endl;

	return 0;
}
