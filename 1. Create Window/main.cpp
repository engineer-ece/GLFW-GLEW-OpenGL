// Introduction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string.h>
const GLint WIDTH = 800, HEIGHT = 600;

int main() {
  if (!glfwInit()) {
		printf("GLFW is not initialized");
		glfwTerminate();
		return 1;
	}

	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH,HEIGHT,"Main Window",NULL,NULL);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);
	glfwMakeContextCurrent(mainWindow);


	if (!mainWindow) {
		printf("MainWindow is not created!");
		glfwTerminate();
		return 1;
	}

  glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {

		printf("GLEW is not initialized");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glViewport(0,0,bufferWidth,bufferHeight);
	CreateTriangle();
	CompileShaders();
	


	while (!glfwWindowShouldClose(mainWindow)) {
	
		glfwPollEvents();
		glClearColor(1.0f,0.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(mainWindow);
	
	
	}
return 0;
}
