#include "Read.hpp"

Read::Read(Id* id, string c_type) : Command(c_type){
	this->id = id;
}

Read::~Read(){
	delete id;
}

Id* Read::get_id(){
	return this->id;
}
