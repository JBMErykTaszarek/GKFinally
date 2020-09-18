#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
class Buildings
{
public:
	/*glm::mat4 P; glm::mat4 V; glm::mat4 M; 
	float cords;*/
	float cordsx; float cordsy; float cordsz;
	float cords; //czasowa zmienna sprawdzamy tylk czy jest ustawiony boiekt w pamieci czy ma wartosci
	Buildings();
	Buildings(float cordsx, float cordsy, float cordsz);
	~Buildings();

private:

};