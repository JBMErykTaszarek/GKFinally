#include <Buildings.h>

Buildings::Buildings() {
	

}
Buildings::Buildings(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cords) {
	this->P = P;
	this->V = V;
	this->M = M;
	this->cords = cords;

}
Buildings::~Buildings() {

}


