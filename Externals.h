#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "shaderprogram.h"
#include <Scene.h>
#include <RenderFunctions.h>
#include <Windows.h>
#include <windows.h>

#ifdef _WIN32
#else
#include <unistd.h>
#endif