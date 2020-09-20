

#define GLM_FORCE_RADIANS

#include <Externals.h>
#include <stdlib.h>
#include <stdio.h>
#include "myCube.h"
#include "constants.h"
#include "allmodels.h"
#include "lodepng.h"
#include "OBJ_Loader.h"
GLuint tex[3];

void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void key_callback(
	GLFWwindow* window,
	int key,
	int scancode,
	int action,
	int mod
) {
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_LEFT) {
			app.speed_y = -1;
		}
		if (key == GLFW_KEY_RIGHT) {
			app.speed_y = 1;
		}
		if (key == GLFW_KEY_UP) {
			app.speed_x = 1;
		}
		if (key == GLFW_KEY_DOWN) {
			app.speed_x = -1;
		}
	}
	if (action == GLFW_RELEASE) {
		if (key == GLFW_KEY_LEFT || key == GLFW_KEY_RIGHT) {
			app.speed_y = 0;
		}
		if (key == GLFW_KEY_UP || key == GLFW_KEY_DOWN) {
			app.speed_x = 0;
		}
	}
}
GLuint readTexture(const char* filename) {
	GLuint tex;
	glActiveTexture(GL_TEXTURE0);

	//Wczytanie do pamięci komputera
	std::vector<unsigned char> image;   //Alokuj wektor do wczytania obrazka
	unsigned width, height;   //Zmienne do których wczytamy wymiary obrazka
	//Wczytaj obrazek
	unsigned error = lodepng::decode(image, width, height, filename);

	//Import do pamięci karty graficznej
	glGenTextures(1, &tex); //Zainicjuj jeden uchwyt
	glBindTexture(GL_TEXTURE_2D, tex); //Uaktywnij uchwyt
	//Wczytaj obrazek do pamięci KG skojarzonej z uchwytem
	glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return tex; 
}


//Procedura inicjująca
void initOpenGLProgram(GLFWwindow* window) {
	initShaders();
	//************Tutaj umieszczaj kod, który należy wykonać raz, na początku programu************
	glClearColor(0, 1, 1, 1); //Ustaw kolor czyszczenia bufora kolorów
	glEnable(GL_DEPTH_TEST); //Włącz test głębokości na pikselach
	glfwSetKeyCallback(window, key_callback);
	tex[0] = readTexture("green+grass.png");
	tex[1] = readTexture("bricks.png");
	tex[2] = readTexture("paper.png");
}


//Zwolnienie zasobów zajętych przez program
void freeOpenGLProgram(GLFWwindow* window) {
	freeShaders();
	//************Tutaj umieszczaj kod, który należy wykonać po zakończeniu pętli głównej************
	glDeleteTextures(3, tex);
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

	float texGroundCoords[]{
		20.0f,0.0f,
		0.0f,20.0f,
		0.0f,0.0f,

		20.0f,0.0f,
		20.0f,20.0f,
		0.0f,20.0f
	};



	//spColored->use(); //Aktywuj program cieniujący

	//glUniformMatrix4fv(spColored->u("P"), 1, false, glm::value_ptr(P)); //Załaduj do programu cieniującego macierz rzutowania
	//glUniformMatrix4fv(spColored->u("V"), 1, false, glm::value_ptr(V)); //Załaduj do programu cieniującego macierz widoku
	//glUniformMatrix4fv(spColored->u("M"), 1, false, glm::value_ptr(M)); //Załaduj do programu cieniującego macierz modelu



	//glEnableVertexAttribArray(spColored->a("vertex"));
	//glVertexAttribPointer(spColored->a("vertex"), 4, GL_FLOAT, false, 0, groundVertices); //Współrzędne wierzchołków bierz z tablicy birdVertices

	//glEnableVertexAttribArray(spColored->a("color"));
	//glVertexAttribPointer(spColored->a("color"), 4, GL_FLOAT, false, 0, groundColors); //Współrzędne wierzchołków bierz z tablicy birdColors

	//glDrawArrays(GL_TRIANGLES, 0, 6);

	//glDisableVertexAttribArray(spColored->a("vertex"));
	//glDisableVertexAttribArray(spColored->a("color"));

	spTextured->use(); //Aktywuj program cieniujący

	glUniformMatrix4fv(spTextured->u("P"), 1, false, glm::value_ptr(P)); //Załaduj do programu cieniującego macierz rzutowania
	glUniformMatrix4fv(spTextured->u("V"), 1, false, glm::value_ptr(V)); //Załaduj do programu cieniującego macierz widoku
	glUniformMatrix4fv(spTextured->u("M"), 1, false, glm::value_ptr(M)); //Załaduj do programu cieniującego macierz modelu


	glEnableVertexAttribArray(spTextured->a("vertex"));
	glVertexAttribPointer(spTextured->a("vertex"), 4, GL_FLOAT, false, 0, groundVertices); //Współrzędne wierzchołków bierz z tablicy myCubeVertices

	glEnableVertexAttribArray(spTextured->a("texCoord"));
	glVertexAttribPointer(spTextured->a("texCoord"), 2, GL_FLOAT, false, 0, texGroundCoords); //Współrzędne teksturowania bierz z tablicy myCubeTexCoords

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex[0]);
	glUniform1i(spTextured->u("tex"), 0);

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(spTextured->a("vertex"));
	glDisableVertexAttribArray(spTextured->a("color"));

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
	x1 + cordsx,y1 + cordsy,z2 + cordsz,1,
	// Ściana boczna lewa
	x1 + cordsx, y1 + cordsy, z1 + cordsz, 1,
	x1 + cordsx,y2 + cordsy,z1 + cordsz,1,
	x1 + cordsx,y2 + cordsy,z2 + cordsz,1,
	//drtugi trojkat
	x1 + cordsx,y2 + cordsy,z2 + cordsz,1, //int x1 = -5, x2 = -3;
											//int y1 = 3, y2 = -3;
											//int z1 = 10, z2 = 8
	x1 + cordsx,y1 + cordsy,z2 + cordsz,1,
	x1 + cordsx,y1 + cordsy,z1 + cordsz,1,
	//ściana boczna prawa
	x2 + cordsx, y1 + cordsy, z1 + cordsz, 1,
	x2 + cordsx,y2 + cordsy,z1 + cordsz,1,
	x2 + cordsx,y2 + cordsy,z2 + cordsz,1,
	//drtugi trojkat
	x2 + cordsx,y2 + cordsy,z2 + cordsz,1, //int x1 = -5, x2 = -3;
											//int y1 = 3, y2 = -3;
											//int z1 = 10, z2 = 8
	x2 + cordsx,y1 + cordsy,z2 + cordsz,1,
	x2 + cordsx,y1 + cordsy,z1 + cordsz,1,
	



	};

	float normals[] = {
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,

		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f

	};

	float texbuildingCoords[]{
		0.0f,1.0f,
		0.0f,0.0f,
		1.0f,0.0f,

		
		1.0f,0.0f,
		1.0f,1.0f,
		0.0f,1.0f,
		

		0.0f,1.0f,
		0.0f,0.0f,
		1.0f,0.0f,


		1.0f,0.0f,
		1.0f,1.0f,
		0.0f,1.0f,

		0.0f,1.0f,
		0.0f,0.0f,
		1.0f,0.0f,


		1.0f,0.0f,
		1.0f,1.0f,
		0.0f,1.0f,


		0.0f,1.0f,
		0.0f,0.0f,
		1.0f,0.0f,


		1.0f,0.0f,
		1.0f,1.0f,
		0.0f,1.0f
	};



	spTextured->use(); //Aktywuj program cieniujący

	glUniformMatrix4fv(spTextured->u("P"), 1, false, glm::value_ptr(P)); //Załaduj do programu cieniującego macierz rzutowania
	glUniformMatrix4fv(spTextured->u("V"), 1, false, glm::value_ptr(V)); //Załaduj do programu cieniującego macierz widoku
	glUniformMatrix4fv(spTextured->u("M"), 1, false, glm::value_ptr(M)); //Załaduj do programu cieniującego macierz modelu


	glEnableVertexAttribArray(spTextured->a("vertex"));
	glVertexAttribPointer(spTextured->a("vertex"), 4, GL_FLOAT, false, 0, buildingVertices); //Współrzędne wierzchołków bierz z tablicy myCubeVertices

	glEnableVertexAttribArray(spTextured->a("texCoord"));
	glVertexAttribPointer(spTextured->a("texCoord"), 2, GL_FLOAT, false, 0, texbuildingCoords); //Współrzędne teksturowania bierz z tablicy myCubeTexCoords

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex[1]);
	glUniform1i(spTextured->u("tex"), 0);

	glDrawArrays(GL_TRIANGLES, 0, 24);

	glDisableVertexAttribArray(spTextured->a("vertex"));
	glDisableVertexAttribArray(spTextured->a("color"));

}
void plane(glm::mat4 P, glm::mat4 V, glm::mat4 M, float cordsx, float cordsy, float cordsz) {
	int currentZ = 1;
	float x1 = 0, x2 = 0.5, x3 = 1.5;
	float y1 = -0.3, y2 = 0.2;
	float z1 = 1, z2 = 3;
	float birdVertices[] = {
	-x2 + cordsx, y2 + cordsy, z1, 1,
		-x3 + cordsx, y2 + cordsy, z1, 1,
		x1 + cordsx, y2 + cordsy, z2, 1,

		x2 + cordsx, y2 + cordsy, z1, 1,
		x3 + cordsx, y2 + cordsy, z1, 1,
		x1 + cordsx, y2 + cordsy, z2, 1,

		x1 + cordsx,y1 + cordsy,z1,1,
		-x2 + cordsx,y2 + cordsy,z1,1,
		x1 + cordsx,y2 + cordsy,z2,1,

		x1 + cordsx,y1 + cordsy,z1,1,
		x2 + cordsx,y2 + cordsy,z1,1,
		x1 + cordsx,y2 + cordsy,z2,1,

		

	};
	float texBirdVerts[]{
		0.0f,0.0f,
		0.25f,0.0f,
		0.0f,1.0f,

		0.25f,0.0f,
		0.5f,0.0f,
		1.0f,1.0f,

		0.0f,0.0f,
		0.25f,0.0f,
		0.0f,1.0f,

		0.25f,0.0f,
		0.5f,0.0f,
		1.0f,1.0f

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



	spTextured->use(); //Aktywuj program cieniujący

	glUniformMatrix4fv(spTextured->u("P"), 1, false, glm::value_ptr(P)); //Załaduj do programu cieniującego macierz rzutowania
	glUniformMatrix4fv(spTextured->u("V"), 1, false, glm::value_ptr(V)); //Załaduj do programu cieniującego macierz widoku
	glUniformMatrix4fv(spTextured->u("M"), 1, false, glm::value_ptr(M)); //Załaduj do programu cieniującego macierz modelu


	glEnableVertexAttribArray(spTextured->a("vertex"));
	glVertexAttribPointer(spTextured->a("vertex"), 4, GL_FLOAT, false, 0, birdVertices); //Współrzędne wierzchołków bierz z tablicy myCubeVertices

	glEnableVertexAttribArray(spTextured->a("texCoord"));
	glVertexAttribPointer(spTextured->a("texCoord"), 2, GL_FLOAT, false, 0, texBirdVerts); //Współrzędne teksturowania bierz z tablicy myCubeTexCoords

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex[2]);
	glUniform1i(spTextured->u("tex"), 0);

	glDrawArrays(GL_TRIANGLES, 0, 12);

	glDisableVertexAttribArray(spTextured->a("vertex"));
	glDisableVertexAttribArray(spTextured->a("color"));

}
//Procedura rysująca zawartość sceny
void drawScene(GLFWwindow* window) {
	//************Tutaj umieszczaj kod rysujący obraz******************l
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Wyczyść bufor koloru i bufor głębokości


	app.render();
	glfwSwapBuffers(window); //Skopiuj bufor tylny do bufora przedniego
}

int main(void)
{
	GLFWwindow* window; //Wskaźnik na obiekt reprezentujący okno

	glfwSetErrorCallback(error_callback);//Zarejestruj procedurę obsługi błędów

	if (!glfwInit()) { //Zainicjuj bibliotekę GLFW
		fprintf(stderr, "Nie można zainicjować GLFW.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(1000, 1000, "MICROSOFT FLIGHT SYMULATOR 2", NULL, NULL);  //Utwórz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.

	if (!window) //Jeżeli okna nie udało się utworzyć, to zamknij program
	{
		fprintf(stderr, "Nie można utworzyć okna.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window); //Od tego momentu kontekst okna staje się aktywny i polecenia OpenGL będą dotyczyć właśnie jego.
	glfwSwapInterval(1); //Czekaj na 1 powrót plamki przed pokazaniem ukrytego bufora

	if (glewInit() != GLEW_OK) { //Zainicjuj bibliotekę GLEW
		fprintf(stderr, "Nie można zainicjować GLEW.\n");
		exit(EXIT_FAILURE);
	}

	initOpenGLProgram(window); //Operacje inicjujące

	//Główna pętla
	//float speed_x = 0; //zadeklaruj zmienną przechowującą aktualny kąt obrotu
	//float speed_y = 0; //zadeklaruj zmienną przechowującą aktualny kąt obrotu
	glfwSetTime(0); //Wyzeruj licznik czasu
	
	
	
	while (!glfwWindowShouldClose(window)) //Tak długo jak okno nie powinno zostać zamknięte
	{
		//speed_x += speed_x * glfwGetTime(); //Oblicz kąt o jaki obiekt obrócił się podczas poprzedniej klatki
		//speed_x += speed_y * glfwGetTime(); //Oblicz kąt o jaki obiekt obrócił się podczas poprzedniej klatki
		//lfwSetTime(0); //Wyzeruj licznik czasu
		drawScene(window); //Wykonaj procedurę rysującą
		glfwPollEvents(); //Wykonaj procedury callback w zalezności od zdarzeń jakie zaszły.
	}

	freeOpenGLProgram(window);

	glfwDestroyWindow(window); //Usuń kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zajęte przez GLFW
	exit(EXIT_SUCCESS);
}


