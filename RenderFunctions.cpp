#pragma once
#include <Externals.h>

void plane2(glm::mat4 P, glm::mat4 V, glm::mat4 M) {
	//Przyk�adowe tablice dla tego zadania - mo�liwo�ci jest bardzo du�o
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



	spColored->use(); //Aktywuj program cieniuj�cy

	glUniformMatrix4fv(spColored->u("P"), 1, false, glm::value_ptr(P)); //Za�aduj do programu cieniuj�cego macierz rzutowania
	glUniformMatrix4fv(spColored->u("V"), 1, false, glm::value_ptr(V)); //Za�aduj do programu cieniuj�cego macierz widoku
	glUniformMatrix4fv(spColored->u("M"), 1, false, glm::value_ptr(M)); //Za�aduj do programu cieniuj�cego macierz modelu



	glEnableVertexAttribArray(spColored->a("vertex"));
	glVertexAttribPointer(spColored->a("vertex"), 4, GL_FLOAT, false, 0, birdVertices); //Wsp�rz�dne wierzcho�k�w bierz z tablicy birdVertices

	glEnableVertexAttribArray(spColored->a("color"));
	glVertexAttribPointer(spColored->a("color"), 4, GL_FLOAT, false, 0, birdColors); //Wsp�rz�dne wierzcho�k�w bierz z tablicy birdColors

	glDrawArrays(GL_TRIANGLES, 0, 12);

	glDisableVertexAttribArray(spColored->a("vertex"));
	glDisableVertexAttribArray(spColored->a("color"));

}

void plane(glm::mat4 P, glm::mat4 V, glm::mat4 M) {
	//Przyk�adowe tablice dla tego zadania - mo�liwo�ci jest bardzo du�o
	int currentZ = 1;
	float birdVertices[] = {
		0,1,currentZ,1,
		1,0,currentZ,1,  //CuremtZ = Zcamery
		0,1,-currentZ,1,

		0,1,currentZ,1,
		0,1,-currentZ,1,
		-1,0,currentZ,1

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

void Ground(glm::mat4 P, glm::mat4 V, glm::mat4 M) {
	//Przyk�adowe tablice dla tego zadania - mo�liwo�ci jest bardzo du�o

	float groundVertices[] = {

		-100,-3,-1,1,
		100,-3,-1,1,
		-100,-3,100,1,

		100,-3,100,1,
		100,-3,1,1,
		-100,-3,100,1
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

void Building(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cords) {
	//Przyk�adowe tablice dla tego zadania - mo�liwo�ci jest bardzo du�o

	float buildingVertices[] = {

		-5 + cords,3,10 + cords,1,
		-5 + cords,-3,10 + cords,1,
		-3 + cords,-3,10 + cords,1,

		-3 + cords,-3,10 + cords,1,
		-3 + cords,3,10 + cords,1,
		-5 + cords,3,10 + cords,1,

		-5 + cords,3,8 + cords,1,
		-5 + cords,-3,8 + cords,1,
		-3 + cords,-3,8 + cords,1,

		-3 + cords,-3,8 + cords,1,
		-3 + cords,3,8 + cords,1,
		-5 + cords,3,8 + cords,1,


		-5 + cords,3,10 + cords,1,
		-5 + cords,-3,10 + cords,1,
		-5 + cords,3,10 + cords,1,

		-5 + cords,3,8 + cords,1,
		-5 + cords,3,8 + cords,1,
		-5 + cords,-3,8 + cords,1,
		
		-3 + cords,-3,10 + cords,1,
		-3 + cords,-3,10 + cords,1,
		-3 + cords,3,10 + cords,1,

		-3 + cords,-3,8 + cords,1,
		-3 + cords,-3,8 + cords,1,
		-3 + cords,3,8 + cords,1,




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

	glDrawArrays(GL_TRIANGLES, 0, 1);

	glDisableVertexAttribArray(spColored->a("vertex"));
	glDisableVertexAttribArray(spColored->a("color"));

}