#include <iostream>
using namespace std;

class Class1{
private:
	int a;
public:
	Class1(int a);
	int get_a();
};

Class1::Class1(int a){
	this->a = a;
}

int Class1::get_a(){
	return a;
}

class Class2 : public Class1{
public:
	Class2(int a);
};

Class2::Class2(int a) : Class1(a){}

class Class3 : public Class2{
private:
	int b;
public:
	Class3(int b, int a);
	int get_b();
};

Class3::Class3(int b, int a) : Class2(a){
	this->b = b;
}

int Class3::get_b(){
	return b;
}

int main(){

	Class3 c3(1,2);
	cout << c3.get_b() << endl;
	cout << c3.get_a() << endl;

	return 0;
}
