#include "Read.hpp"

Read::Read(){

}

Read::Read(Id* id){
	this->id = id;
}

Read::~Read(){

}

Id* Read::get_id(){
	return this->id;
}
