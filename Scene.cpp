
#include <Externals.h>
#include <time.h>
#include <ctime>

Scene::Scene() {
	srand(time(NULL));

	this->samolot.V = glm::mat4(1.0f);

	UINT TimerId = SetTimer(NULL, 0, this->MovementTimer, &ChangeBuildingsPosition);
	UINT TimerId2 = SetTimer(NULL, 0, this->MovementTimer * 15, &CheckBuildingsInScreen);

}
Scene::~Scene() {

}


void Scene::addBuilding(glm::mat4 P, glm::mat4 V, glm::mat4 M, float nothink) {
	if (this->buildings.size() < this->maxBuildings) {
		float x = rand() % 9 + 1; //todo: algorytm obliczaj¹cy na jakich pozycjach ma siê spawniæ nastêpny budynek, chyba tylko X musi byæ ró¿ny 

		this->buildings.push_back(Buildings{ P,V,M, x,0,40,0,this->nextBuildingNumber++ });
	}
};
void Scene::setValues(glm::mat4 P, glm::mat4 V, glm::mat4 M) {
	this->P = P;
	this->V = V;
	this->M = M;

	if (this->samolot.id == 0) {
		this->samolot.id = 1;
		this->samolot.P = P;
		this->samolot.V = V;
		this->samolot.M = M;
	}
	if (this->ground.id == 0) {
		this->ground.id = 1;
		this->ground.P = P;
		this->ground.V = V;
		this->ground.M = M;
	}
}
void Scene::planeMovement() {
	if (speed_x == 1)
	{
		this->samolot.cordsy += app.keyMovementDistance;
		//this->samolot.V =  glm::translate(V, glm::vec3(0.0f, 1.0f, 1.0f));
	}
	if (speed_x == -1)
	{
		this->samolot.cordsy -= app.keyMovementDistance;
		//this->samolot.V = glm::translate(V, glm::vec3(0.0f, -0.5f, 1.0f));
	}
	if (speed_y == 1)
	{
		this->samolot.cordsx -= app.keyMovementDistance;
		//this->samolot.V = glm::translate(V, glm::vec3(0.4f, 0.0f, 1.0f));
	}
	if (speed_y == -1)
	{
		this->samolot.cordsx += app.keyMovementDistance;
		//this->samolot.V = glm::translate(V, glm::vec3(-0.4f, 0.0f, 1.0f));
	}
}
void Scene::render() {
	//zmiana macierzy V w zale¿noœci od speed_x i speed_y
	glm::mat4
		V = glm::mat4(1.0f),
		M = glm::lookAt(glm::vec3(0.0f, 0.0f, -5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)), //Wylicz macierz widoku
		P = glm::perspective(glm::radians(50.0f), 1.0f, 1.0f, 50.0f); //Wylicz macierz rzutowania

	this->planeMovement();


	spLambert->use(); //Aktyeuj program cieniuj¹cy
	glUniform4f(spLambert->u("color"), 0, 1, 0, 1); //Ustaw kolor rysowania obiektu
	glUniformMatrix4fv(spLambert->u("P"), 1, false, glm::value_ptr(P)); //Za³aduj do programu cieniuj¹cego macierz rzutowania
	glUniformMatrix4fv(spLambert->u("V"), 1, false, glm::value_ptr(V)); //Za³aduj do programu cieniuj¹cego macierz widoku
	glUniformMatrix4fv(spLambert->u("M"), 1, false, glm::value_ptr(M)); //Za³aduj do programu cieniuj¹cego macierz modelu

	this->setValues(P, V, M);
	Buildings
		s = this->samolot,
		g = this->ground;

	plane(s.P, s.V, s.M, s.cordsx, s.cordsy, s.cordsz);
	Ground(g.P, g.V, g.M, g.cordsx, g.cordsy, g.cordsz);
	//renderujemy aktualne budynki
	for (int i = 0; i < app.buildings.size(); i++)
	{
		Buildings building = get(app.buildings, i);
		float radians = 50.0f, a = 1.0f, b = 1.0f, c = 50.0f;
		
		building.P = glm::perspective(glm::radians(radians), a, b, c); //todo: zmienic perspektywe ??
		
		Building(building.P, building.V, building.M, building.cordsx, building.cordsy, building.cordsz);
	}
};


Scene app;
void replace(std::list<Buildings>& l, const Buildings b) { //zamienia obiekt Building z elementem listy jesli ID sie zgadzaja
	for (auto it = l.rbegin(); it != l.rend(); it++) {
		if (it->id == b.id) {
			it->id = b.id;
			it->number = b.number;
			it->cords = b.cords;
			it->cordsx = b.cordsx;
			it->cordsy = b.cordsy;
			it->cordsz = b.cordsz;
			it->P = b.P;
			it->M = b.M;
			it->V = b.V;

			return;
		}
	}
}
Buildings get(std::list<Buildings> _list, int _i) {
	std::list<Buildings>::iterator it = _list.begin();
	for (int i = 0; i < _i; i++) {
		++it;
	}
	return *it;
}



VOID CALLBACK ChangeBuildingsPosition(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime) {
	float z;
	for (int i = 0; i < app.buildings.size(); i++)
	{
		Buildings b = get(app.buildings, i);
		int random = rand() % 2 + 1;
		int x = 0;
		z = (app.stepDistance * (int)(b.number));

		//todo: czy nie trzeba by tez zmieniackorduynantow P V I M ?
		//tu zmieniamy dane danego budynku przy kazdym wywolaniu timeoyu
		z = b.cordsz - app.stepDistance;
		b.cordsz = z;

		b.number++;
		replace(app.buildings, b);


		if (z <= -8) {//wartosc graniczna jak budynek znika .. w sumie powinny iœæ w drug¹ stornê tak se myœlê ale chuj xDD
			app.buildings.pop_front();

		}

	}


}
VOID CALLBACK CheckBuildingsInScreen(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime) {
	int BuildingsInScreen = 5;
	int CurrentBuildings = app.buildings.size();
	if (CurrentBuildings < app.maxBuildings) { //jezeli jakiegoœ nam brakuje dodajemy kolejne
		app.addBuilding(app.P, app.V, app.M, 0);
	}
}