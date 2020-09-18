#include <Externals.h>
#include <time.h>

Scene::Scene() {
	this->buildings = {};
	this->maxBuildings = 1;
}
//Scene::Scene(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cords) {
//	this->buildings = {};
//	this->maxBuildings = 2;
//}
void Scene::addBuilding(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cords) {
	if (this->buildings.size() < this->maxBuildings) {
		this->buildings.push_front(Buildings{ 0,0,0 });
	}
};
void Scene::render() {

	glm::mat4 V = glm::mat4(1.0f); //Zainicjuj macierz modelu macierz� jednostkow�
//V = glm::rotate(V, angle_y, glm::vec3(0.0f, 1.0f, 0.0f)); //Pomn� macierz modelu razy macierz obrotu o k�t angle wok� osi Y
//V = glm::rotate(V, angle_x, glm::vec3(1.0f, 0.0f, 0.0f)); //Pomn� macierz modelu razy macierz obrotu o k�t angle wok� osi X
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

	//Zamiast poni�szych linijek nale�y wstawi� kod dotycz�cy rysowania w�asnych obiekt�w (glDrawArrays/glDrawElements i wszystko dooko�a)
	//-----------
	spLambert->use(); //Aktyeuj program cieniuj�cy
	glUniform4f(spLambert->u("color"), 0, 1, 0, 1); //Ustaw kolor rysowania obiektu
	glUniformMatrix4fv(spLambert->u("P"), 1, false, glm::value_ptr(P)); //Za�aduj do programu cieniuj�cego macierz rzutowania
	glUniformMatrix4fv(spLambert->u("V"), 1, false, glm::value_ptr(V)); //Za�aduj do programu cieniuj�cego macierz widoku
	glUniformMatrix4fv(spLambert->u("M"), 1, false, glm::value_ptr(M)); //Za�aduj do programu cieniuj�cego macierz modelu
	//kom

	srand(time(NULL));
	float Cords = rand() % 10 + 1;
	
	//app.buildings;
	app.addBuilding(P, V, M, Cords);
	//plane2(P, V, M);
	//Ground(P, V,M);
	plane(P, V, M, 0, 0, 0);
	Ground(P, V, M, 0, 0, 0);
	if (this->buildings.size() > 0) { 
		//todo: zrobi� foreacha kt�ry bedzie renderowa� wi�cej budynk�w ? xD
		
		Buildings s = this->samolot;
		Buildings g = this->ground;
		Buildings b = get(this->buildings, 0);

		if (s.cords == 0) {
			this->samolot.cordsx = 0;
			this->samolot.cordsy = 0;
			this->samolot.cordsz = 0;
			this->samolot.cords = 1;

			this->ground.cordsx = 0;
			this->ground.cordsy = 0;
			this->ground.cordsz = 0;
			this->ground.cords = 1;

		}
		
		for (int i = 0; i < this->buildings.size(); i++)
		{
			b = get(this->buildings, i);
			Cords = rand() % 3 + 1;

			float inc = 2.5 * (i + 1);
			Building(P, V, M, 0, 0, 0);

		}
		
	}
};

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
