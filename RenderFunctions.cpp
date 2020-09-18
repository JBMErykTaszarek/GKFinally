#pragma once
#include <Externals.h>
//dupa
void plane2(glm::mat4 P, glm::mat4 V, glm::mat4 M) {
	//Przykładowe tablice dla tego zadania - możliwości jest bardzo dużo
	//int currentZ = 1;
	float birdVertices[] = {
		-0.5, 0.2, 1, 1,
		-1.5, 0.2, 1, 1,
		0, 0.2, 3, 1,

		0.5, 0.2, 1, 1,
		1.5, 0.2, 1, 1,
		0, 0.2, 3, 1,

		0,0,1,1,
		-0.5,0.2,1,1,
		0,0.2,3,1,

		0,0,1,1,
		0.5,0.2,1,1,
		0,0.2,3,1



	};

	float birdColors[] = {
		1,1,1,1,
		1,1,1,1,
		1,1,1,1,

		1,1,1,1,
		1,1,1,1,
		1,1,1,1,

		1,1,1,1,
		1,1,1,1,
		1,1,1,1,

		1,1,1,1,
		1,1,1,1,
		1,1,1,1
	};



	spColored->use(); //Aktywuj program cieniujący

	glUniformMatrix4fv(spColored->u("P"), 1, false, glm::value_ptr(P)); //Załaduj do programu cieniującego macierz rzutowania
	glUniformMatrix4fv(spColored->u("V"), 1, false, glm::value_ptr(V)); //Załaduj do programu cieniującego macierz widoku
	glUniformMatrix4fv(spColored->u("M"), 1, false, glm::value_ptr(M)); //Załaduj do programu cieniującego macierz modelu



	glEnableVertexAttribArray(spColored->a("vertex"));
	glVertexAttribPointer(spColored->a("vertex"), 4, GL_FLOAT, false, 0, birdVertices); //Współrzędne wierzchołków bierz z tablicy birdVertices

	glEnableVertexAttribArray(spColored->a("color"));
	glVertexAttribPointer(spColored->a("color"), 4, GL_FLOAT, false, 0, birdColors); //Współrzędne wierzchołków bierz z tablicy birdColors

	glDrawArrays(GL_TRIANGLES, 0, 12);

	glDisableVertexAttribArray(spColored->a("vertex"));
	glDisableVertexAttribArray(spColored->a("color"));

}

void plane(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cordsx, float cordsy, float cordsz) {
	int currentZ = 1;
	int x1 = 0, x2 = 1, x3 = -1;
	int y1 = 1, y2 = 0;
	int z1 = 1, z2 = -1;
	float birdVertices[] = {
	-0.5, 0.2, 1, 1,
		-1.5, 0.2, 1, 1,
		0, 0.2, 3, 1,

		0.5, 0.2, 1, 1,
		1.5, 0.2, 1, 1,
		0, 0.2, 3, 1,

		0,0,1,1,
		-0.5,0.2,1,1,
		0,0.2,3,1,

		0,0,1,1,
		0.5,0.2,1,1,
		0,0.2,3,1

	};

	float birdColors[] = {
		1,1,1,1,
		1,1,1,1,
		1,1,1,1,

		1,1,1,1,
		1,1,1,1,
		1,1,1,1,

		1,1,1,1,
		1,1,1,1,
		1,1,1,1,

		1,1,1,1,
		1,1,1,1,
		1,1,1,1
	};



	spColored->use(); //Aktywuj program cieniujący

	glUniformMatrix4fv(spColored->u("P"), 1, false, glm::value_ptr(P)); //Załaduj do programu cieniującego macierz rzutowania
	glUniformMatrix4fv(spColored->u("V"), 1, false, glm::value_ptr(V)); //Załaduj do programu cieniującego macierz widoku
	glUniformMatrix4fv(spColored->u("M"), 1, false, glm::value_ptr(M)); //Załaduj do programu cieniującego macierz modelu



	glEnableVertexAttribArray(spColored->a("vertex"));
	glVertexAttribPointer(spColored->a("vertex"), 4, GL_FLOAT, false, 0, birdVertices); //Współrzędne wierzchołków bierz z tablicy birdVertices

	glEnableVertexAttribArray(spColored->a("color"));
	glVertexAttribPointer(spColored->a("color"), 4, GL_FLOAT, false, 0, birdColors); //Współrzędne wierzchołków bierz z tablicy birdColors

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(spColored->a("vertex"));
	glDisableVertexAttribArray(spColored->a("color"));

}

void Ground(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cordsx, float cordsy, float cordsz) {
	int x1 = 100, x2 = -100;
	int y1 = -3;
	int z1 = -1, z2 = 1, z3 = 100;

	float groundVertices[] = {

		x2 + cordsx,y1 + cordsy,z1 + cordsz,1,
		x1 + cordsx,y1 + cordsy,z1 + cordsz,1,
		x2 + cordsx,y1 + cordsy,z3 + cordsz,1,

		x1 + cordsx,y1 + cordsy,z3 + cordsz,1,
		x1 + cordsx,y1 + cordsy,z2 + cordsz,1,
		x2 + cordsx,y1 + cordsy,z3 + cordsz,1
	};

	float groundColors[] = {

		0,1,0.5,1,
		0,1,0.5,1,
		0,1,0.5,1
	};



	spColored->use(); //Aktywuj program cieniujący

	glUniformMatrix4fv(spColored->u("P"), 1, false, glm::value_ptr(P)); //Załaduj do programu cieniującego macierz rzutowania
	glUniformMatrix4fv(spColored->u("V"), 1, false, glm::value_ptr(V)); //Załaduj do programu cieniującego macierz widoku
	glUniformMatrix4fv(spColored->u("M"), 1, false, glm::value_ptr(M)); //Załaduj do programu cieniującego macierz modelu



	glEnableVertexAttribArray(spColored->a("vertex"));
	glVertexAttribPointer(spColored->a("vertex"), 4, GL_FLOAT, false, 0, groundVertices); //Współrzędne wierzchołków bierz z tablicy birdVertices

	glEnableVertexAttribArray(spColored->a("color"));
	glVertexAttribPointer(spColored->a("color"), 4, GL_FLOAT, false, 0, groundColors); //Współrzędne wierzchołków bierz z tablicy birdColors

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(spColored->a("vertex"));
	glDisableVertexAttribArray(spColored->a("color"));

}

void Building(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cordsx, float cordsy, float cordsz) {
	//Przykładowe tablice dla tego zadania - możliwości jest bardzo dużo
	int x1 = -5, x2 = -3;
	int y1 = 3, y2 = -3;
	int z1 = 10, z2 = 8;
	float buildingVertices[] = {

		//piertwszy tr�jkat
	//X,Y,Z,Opacity

	x1 + cordsx, y1 + cordsy, z1 + cordsz, 1,
	x1 + cordsx,y2 + cordsy,z1 + cordsz,1,
	x2 + cordsx,y2 + cordsy,z1 + cordsz,1,
	//drtugi trojkat
	x2 + cordsx,y2 + cordsy,z1 + cordsz,1,
	x2 + cordsx,y1 + cordsy,z1 + cordsz,1,
	x1 + cordsx,y1 + cordsy,z1 + cordsz,1,
	//te z ty�u xD
	x1 + cordsx,y1 + cordsy,z2 + cordsz,1,
	x1 + cordsx,y2 + cordsy,z2 + cordsz,1,
	x2 + cordsx,y2 + cordsy,z2 + cordsz,1,
	//te z ty�u xD
	x2 + cordsx,y2 + cordsy,z2 + cordsz,1,
	x2 + cordsx,y1 + cordsy,z2 + cordsz,1,
	x1 + cordsx,y1 + cordsy,z2 + cordsz,1




	};

	float buildingColors[] = {

		0,0,0,1,
		0,0,0,1,
		0,0,0,1,

		0,0,0,1,
		0,0,0,1,
		0,0,0,1,

		0,0,0,1,
		0,0,0,1,
		0,0,0,1,

		0,0,0,1,
		0,0,0,1,
		0,0,0,1,

	
	};



	spColored->use(); //Aktywuj program cieniujący

	glUniformMatrix4fv(spColored->u("P"), 1, false, glm::value_ptr(P)); //Załaduj do programu cieniującego macierz rzutowania
	glUniformMatrix4fv(spColored->u("V"), 1, false, glm::value_ptr(V)); //Załaduj do programu cieniującego macierz widoku
	glUniformMatrix4fv(spColored->u("M"), 1, false, glm::value_ptr(M)); //Załaduj do programu cieniującego macierz modelu



	glEnableVertexAttribArray(spColored->a("vertex"));
	glVertexAttribPointer(spColored->a("vertex"), 4, GL_FLOAT, false, 0, buildingVertices); //Współrzędne wierzchołków bierz z tablicy birdVertices

	glEnableVertexAttribArray(spColored->a("color"));
	glVertexAttribPointer(spColored->a("color"), 4, GL_FLOAT, false, 0, buildingColors); //Współrzędne wierzchołków bierz z tablicy birdColors

	glDrawArrays(GL_TRIANGLES, 0, 12);

	glDisableVertexAttribArray(spColored->a("vertex"));
	glDisableVertexAttribArray(spColored->a("color"));

}