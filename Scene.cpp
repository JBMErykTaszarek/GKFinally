#include <Externals.h>
#include <time.h>

Scene::Scene() {
	this->buildings = {};
	this->maxBuildings = 1;
}
Scene::Scene(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cords) {
	this->buildings = {};
	this->maxBuildings = 2;
}
void Scene::addBuilding(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cords) {
	if (this->buildings.size() < this->maxBuildings) {
		this->buildings.push_front(Buildings{ P,V,M,cords });
	}
};
void Scene::render() {

	glm::mat4 V = glm::mat4(1.0f); //Zainicjuj macierz modelu macierz¹ jednostkow¹
//V = glm::rotate(V, angle_y, glm::vec3(0.0f, 1.0f, 0.0f)); //Pomnó¿ macierz modelu razy macierz obrotu o k¹t angle wokó³ osi Y
//V = glm::rotate(V, angle_x, glm::vec3(1.0f, 0.0f, 0.0f)); //Pomnó¿ macierz modelu razy macierz obrotu o k¹t angle wokó³ osi X
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

	//Zamiast poni¿szych linijek nale¿y wstawiæ kod dotycz¹cy rysowania w³asnych obiektów (glDrawArrays/glDrawElements i wszystko dooko³a)
	//-----------
	spLambert->use(); //Aktyeuj program cieniuj¹cy
	glUniform4f(spLambert->u("color"), 0, 1, 0, 1); //Ustaw kolor rysowania obiektu
	glUniformMatrix4fv(spLambert->u("P"), 1, false, glm::value_ptr(P)); //Za³aduj do programu cieniuj¹cego macierz rzutowania
	glUniformMatrix4fv(spLambert->u("V"), 1, false, glm::value_ptr(V)); //Za³aduj do programu cieniuj¹cego macierz widoku
	glUniformMatrix4fv(spLambert->u("M"), 1, false, glm::value_ptr(M)); //Za³aduj do programu cieniuj¹cego macierz modelu
	//kom

	srand(time(NULL));
	float Cords = rand() % 10 + 1;
	
	//app.buildings;
	app.addBuilding(P, V, M, Cords);
	plane2(P, V, M);
	Ground(P, V,M);
		
	if (this->buildings.size() > 0) { 
		//todo: zrobiæ foreacha który bedzie renderowa³ wiêcej budynków ? xD
		
		Buildings s = this->samolot;
		Buildings g = this->ground;
		Buildings b = get(this->buildings, 0);

		if (s.cords == 0) {

			this->samolot.cords = b.cords;
			this->samolot.M = b.M;
			this->samolot.P = b.P;
			this->samolot.V = b.V;

			this->ground.cords = b.cords;
			this->ground.M = b.M;
			this->ground.P = b.P;
			this->ground.V = b.V;

		}
		//plane(s.P, s.V, s.M);
		Ground(g.P, g.V, g.M);
		for (int i = 0; i < this->buildings.size(); i++)
		{
			b = get(this->buildings, i);
			float inc = 1.5;
			Building(b.P , b.V , b.M, Cords+(i*inc));

		}
		
	}
};
Scene::Scene(int n) {

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
