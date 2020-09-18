#pragma once
#include <list>
#include <Externals.h>
#include <Buildings.h>

class Scene
{
public:
	//dane dla poczatkowych kordynantów - wysrodkowany samolot
	glm::mat4 P; glm::mat4 V; glm::mat4 M; float cords;
	float speed_x = 0;//[radiany/s]
	float speed_y = 0;//[radiany/s]
	//dane o obiektach
	Buildings samolot;
	Buildings ground;
	std::list <Buildings> buildings; //tablica trzymajaca budynki
	int maxBuildings;
	Scene();

	//Scene(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cords);

	Scene(int n);
	void addBuilding(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cords);
	void render();
	~Scene();


	
};
extern Scene app;

Buildings get(std::list<Buildings> _list, int _i);
