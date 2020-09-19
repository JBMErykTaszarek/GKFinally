#include <Buildings.h>

Buildings::Buildings() {
	

}
Buildings::Buildings(glm::mat4 P, glm::mat4 V, glm::mat4 M,float cordsx, float cordsy, float cordsz,int number,int id) {
	
	this->id = id;
	this->number = number;
	this->cordsx = cordsx;
	this->cordsy = cordsy;
	this->cordsz = cordsz;
	this->cords = cords;
	this->P = P;
	this->V = V;
	this->M = M;

}
Buildings::~Buildings() {

}


