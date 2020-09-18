#pragma once
#include <Externals.h>


void plane(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cordsx, float cordsy, float cordsz) {
	//Przyk�adowe tablice dla tego zadania - mo�liwo�ci jest bardzo du�o
	int currentZ = 1;
	int x1 = 0, x2 = 1, x3 = -1;
	int y1 = 1, y2 = 0;
	int z1 = 1, z2 = -1;

	float birdVertices[] = {
		x1 + cordsx,y1 + cordsy,z1 + cordsz,1,
		x2 + cordsx,y2 + cordsy,z1 + cordsz,1,
		x1 + cordsx,y1 + cordsy,z2 + cordsz,1,

		x1 + cordsx,y1 + cordsy,z1 + cordsz,1,
		x1 + cordsx,y1 + cordsy,z2 + cordsz,1,
		x3 + cordsx,y2 + cordsy,z1 + cordsz,1

	};

	float birdColors[] = {
		1,0,0,1,
		0,1,0,1,
		1,0,0,1,

		1,0,0,1,
		1,0,0,1,
		0,0,1,1
	};



	spColored->use(); //Aktywuj program cieniuj�cy

	glUniformMatrix4fv(spColored->u("P"), 1, false, glm::value_ptr(P)); //Za�aduj do programu cieniuj�cego macierz rzutowania
	glUniformMatrix4fv(spColored->u("V"), 1, false, glm::value_ptr(V)); //Za�aduj do programu cieniuj�cego macierz widoku
	glUniformMatrix4fv(spColored->u("M"), 1, false, glm::value_ptr(M)); //Za�aduj do programu cieniuj�cego macierz modelu



	glEnableVertexAttribArray(spColored->a("vertex"));
	glVertexAttribPointer(spColored->a("vertex"), 4, GL_FLOAT, false, 0, birdVertices); //Wsp�rz�dne wierzcho�k�w bierz z tablicy birdVertices

	glEnableVertexAttribArray(spColored->a("color"));
	glVertexAttribPointer(spColored->a("color"), 4, GL_FLOAT, false, 0, birdColors); //Wsp�rz�dne wierzcho�k�w bierz z tablicy birdColors

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(spColored->a("vertex"));
	glDisableVertexAttribArray(spColored->a("color"));

}

void Ground(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cordsx, float cordsy, float cordsz) {
	//Przyk�adowe tablice dla tego zadania - mo�liwo�ci jest bardzo du�o
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



	spColored->use(); //Aktywuj program cieniuj�cy

	glUniformMatrix4fv(spColored->u("P"), 1, false, glm::value_ptr(P)); //Za�aduj do programu cieniuj�cego macierz rzutowania
	glUniformMatrix4fv(spColored->u("V"), 1, false, glm::value_ptr(V)); //Za�aduj do programu cieniuj�cego macierz widoku
	glUniformMatrix4fv(spColored->u("M"), 1, false, glm::value_ptr(M)); //Za�aduj do programu cieniuj�cego macierz modelu



	glEnableVertexAttribArray(spColored->a("vertex"));
	glVertexAttribPointer(spColored->a("vertex"), 4, GL_FLOAT, false, 0, groundVertices); //Wsp�rz�dne wierzcho�k�w bierz z tablicy birdVertices

	glEnableVertexAttribArray(spColored->a("color"));
	glVertexAttribPointer(spColored->a("color"), 4, GL_FLOAT, false, 0, groundColors); //Wsp�rz�dne wierzcho�k�w bierz z tablicy birdColors

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(spColored->a("vertex"));
	glDisableVertexAttribArray(spColored->a("color"));

}

void Building(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cordsx, float cordsy, float cordsz) {
	//Przyk�adowe tablice dla tego zadania - mo�liwo�ci jest bardzo du�o
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
		0,0,0,1
	};



	spColored->use(); //Aktywuj program cieniuj�cy

	glUniformMatrix4fv(spColored->u("P"), 1, false, glm::value_ptr(P)); //Za�aduj do programu cieniuj�cego macierz rzutowania
	glUniformMatrix4fv(spColored->u("V"), 1, false, glm::value_ptr(V)); //Za�aduj do programu cieniuj�cego macierz widoku
	glUniformMatrix4fv(spColored->u("M"), 1, false, glm::value_ptr(M)); //Za�aduj do programu cieniuj�cego macierz modelu



	glEnableVertexAttribArray(spColored->a("vertex"));
	glVertexAttribPointer(spColored->a("vertex"), 4, GL_FLOAT, false, 0, buildingVertices); //Wsp�rz�dne wierzcho�k�w bierz z tablicy birdVertices

	glEnableVertexAttribArray(spColored->a("color"));
	glVertexAttribPointer(spColored->a("color"), 4, GL_FLOAT, false, 0, buildingColors); //Wsp�rz�dne wierzcho�k�w bierz z tablicy birdColors

	glDrawArrays(GL_TRIANGLES, 0, 12);

	glDisableVertexAttribArray(spColored->a("vertex"));
	glDisableVertexAttribArray(spColored->a("color"));

}