#include "Read.hpp"

Read::Read(){

}

Read::Read(Id* id){
	this->type_class = "READ";
	this->id = id;
}

Read::~Read(){

}

Id* Read::get_id(){
	return this->id;
}

string Read::get_type_name(){
	return this->type_class;
}
