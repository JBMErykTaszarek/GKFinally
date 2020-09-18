#include <Externals.h>
#include <time.h>
#include <ctime>

Scene::Scene() {
	srand(time(NULL));
	this->buildings = {};
	this->maxBuildings = 3;
	this->cords = 10; //todo: zrobic zmienn¹ distanceStep okreslajac¹ dystans jaki pokonuje budynek na 1 ruch
	UINT TimerId = SetTimer(NULL, 0, 1000, &TimerProc);
}
VOID CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime) {

	float z;
	for (int i = 0; i < app.buildings.size(); i++)
	{
		Buildings b = get(app.buildings, i);
		int random = rand() % 10 + 1;
		int x = 0;
		 z =  (app.cords * (int)(b.number));
		b.cordsz += z;
		b.number++;
		replace(app.buildings, b);

	}

}
//Scene::Scene(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cords) {
//	this->buildings = {};
//	this->maxBuildings = 2;
//}
void Scene::addBuilding(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cords) {
	if (this->buildings.size() < this->maxBuildings) {
		float x = rand() % 15 + 1;
		this->buildings.push_front(Buildings{ x,0,0,0,this->nextBuildingNumber++ });
	}
};
void Scene::render() {
	//zmiana macierzy V w zale¿noœci od speed_x i speed_y
	glm::mat4 V = glm::mat4(1.0f);
	if (speed_x == 1)
	{
		V = glm::translate(V, glm::vec3(0.0f, 1.0f, 1.0f));
	}
	if (speed_x == -1)
	{
		V = glm::translate(V, glm::vec3(0.0f, -0.5f, 1.0f));
	}
	if (speed_y == 1)
	{
		V = glm::translate(V, glm::vec3(0.4f, 0.0f, 1.0f));
	}
	if (speed_y == -1)
	{
		V = glm::translate(V, glm::vec3(-0.4f, 0.0f, 1.0f));
	}

	glm::mat4 M = glm::lookAt(glm::vec3(0.0f, 0.0f, -5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)); //Wylicz macierz widoku
	glm::mat4 P = glm::perspective(glm::radians(50.0f), 1.0f, 1.0f, 50.0f); //Wylicz macierz rzutowania

	spLambert->use(); //Aktyeuj program cieniuj¹cy
	glUniform4f(spLambert->u("color"), 0, 1, 0, 1); //Ustaw kolor rysowania obiektu
	glUniformMatrix4fv(spLambert->u("P"), 1, false, glm::value_ptr(P)); //Za³aduj do programu cieniuj¹cego macierz rzutowania
	glUniformMatrix4fv(spLambert->u("V"), 1, false, glm::value_ptr(V)); //Za³aduj do programu cieniuj¹cego macierz widoku
	glUniformMatrix4fv(spLambert->u("M"), 1, false, glm::value_ptr(M)); //Za³aduj do programu cieniuj¹cego macierz modelu


	float Cords = rand() % 10 + 1;



	app.P = P;
	app.V = V;
	app.M = M;
	plane(P, V, M, 0, 0, 0);
	Ground(P, V, M, 0, 0, 0);


	if (this->buildings.size() == 0) {
		//todo:genmeruj budynki
		int BuildingsInScreen = 3;
		int CurrentBuildings = this->buildings.size();
		for (int i = CurrentBuildings; i < BuildingsInScreen; i++)
		{

			app.addBuilding(P, V, M, 0);
		}
	}
	else {

		for (int i = 0; i < app.buildings.size(); i++)
		{
			Buildings b = get(app.buildings, i);
			Building(app.P, app.V, app.M, b.cordsx, b.cordsy, b.cordsz);


		}
	}
};
void replace(std::list<Buildings>& l, const Buildings b) {
	for (auto it = l.rbegin(); it != l.rend(); it++) {
		if (it->id == b.id) {
			it->id = b.id;
			it->number = b.number;
			it->cords = b.cords ;
			it->cordsx = b.cordsx;
			it->cordsy= b.cordsy;
			it->cordsz = b.cordsz;
			return;
		}
	}
}
Scene::~Scene() {

}

Scene app;

Buildings get(std::list<Buildings> _list, int _i) {
	std::list<Buildings>::iterator it = _list.begin();
	for (int i = 0; i < _i; i++) {
		++it;
	}
	return *it;
}



