#include <Scene.h>


Scene::Scene() {
	this->buildings = {};
}
void Scene::addBuilding(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cords) {
	this->buildings.push_front(Buildings{ P,V,M,cords });
	

};
Scene::Scene(int n) {

}

Scene::~Scene() {

}

Scene app;


void test() {
	int x = 5;
	int y = 4;
}