#pragma once
#include <list>
#include <Externals.h>
#include <Buildings.h>
#include <windows.h>

class Scene
{
public:
	//dane dla poczatkowych kordynantów - wysrodkowany samolot
	glm::mat4 P; glm::mat4 V; glm::mat4 M; float cords;
	float speed_x = 0;//[radiany/s]
	float speed_y = 0;//[radiany/s]
	int nextBuildingNumber = 0;
	//dane o obiektach
	Buildings samolot;
	Buildings ground;
	std::list <Buildings> buildings; //tablica trzymajaca budynki
	int maxBuildings;

	Scene();
	//Scene(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cords);


	~Scene();

	void addBuilding(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cords);
	void render();
};
	VOID CALLBACK ChangeBuildingsPosition(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime);
	VOID CALLBACK CheckBuildingsInScreen(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime);
extern Scene app;
void replace(std::list<Buildings>& l, const Buildings b);
Buildings get(std::list<Buildings> _list, int _i);
