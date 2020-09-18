#include <Buildings.h>

Buildings::Buildings() {
	

}
Buildings::Buildings(float cordsx, float cordsy, float cordsz,int number,int id) {
	
	this->cordsx = cordsx;
	this->cordsy = cordsy;
	this->cordsz = cordsz;
	this->id = id;
	this->number = number;
	/*this->P = P;
	this->V = V;
	this->M = M;
	this->cords = cords;*/

}
Buildings::~Buildings() {

}


