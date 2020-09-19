#pragma once
#include <list>
#include <Externals.h>
#include <Buildings.h>
#include <windows.h>

class Scene
{
public:
	//==========dane dla poczatkowych kordynantów - wysrodkowany samolot
	glm::mat4
		V, P, M;
	float
		speed_x = 0,//[radiany/s]
		speed_y = 0,//[radiany/s]
		stepDistance = 2,
		keyMovementDistance = 0.2f;

	int nextBuildingNumber = 0, //identyfikatory który to budynek
		maxBuildings = 3,
		MovementTimer = 50;


	Buildings ground;
	Buildings samolot;
	std::list <Buildings> buildings = {}; //tablica trzymajaca budynki


	//==========metody
	Scene();
	~Scene();

	void addBuilding(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cords);
	void setValues(glm::mat4 P, glm::mat4 V, glm::mat4 M);
	void planeMovement();
	void render();
};
extern Scene app;

void replace(std::list<Buildings>& l, const Buildings b);
Buildings get(std::list<Buildings> _list, int _i);

VOID CALLBACK ChangeBuildingsPosition(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime);
VOID CALLBACK CheckBuildingsInScreen(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime);