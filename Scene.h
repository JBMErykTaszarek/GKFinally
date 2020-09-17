#pragma once
#include <list>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Buildings.h>
class Scene
{
public:
	std::list <Buildings> buildings; //tablica trzymajaca budynki
	int maxBuildings;

	Scene();

	Scene(int n);
	void addBuilding(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cords);
	~Scene();



};
extern Scene app;


void test();

