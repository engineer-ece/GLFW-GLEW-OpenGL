// Introduction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//g++ -pthread -o test test.c  -lglfw -lGLU -lGL -lXrandr   -lX11 -lrt -ldl -lGLEW

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string.h>
const GLint WIDTH = 800, HEIGHT = 600;

GLuint VAO, VBO, shader;


//Vertex Shader

static const char* vshader = "                                          \n\
#version 330                                                            \n\
                                                                        \n\
layout (location = 0) in vec3 pos;                                      \n\
                                                                        \n\
void main() {                                                           \n\
                                                                        \n\
	gl_Position = vec4( 0.3 * pos.x,0.3 * pos.y, 0.5*pos.z,1.0);        \n\
}                                                                       \n\
";

static const char* fshader= "           \n\
#version 330                            \n\
                                        \n\
out vec4 colour;                        \n\
                                        \n\
void main() {                           \n\
                                        \n\
	colour = vec4(1.0,1.0,1.0,1.0);       \n\
}                                       \n\
";
void CreateTriangle() {
	
	GLfloat vertices[] = {
		-1.0f,-1.0f,0.0f,
		 1.0f,-1.0f,0.0f,
		 0.0f, 1.0f,0.0f
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices,GL_STATIC_DRAW);
  
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER,0);
	glBindVertexArray(0);

}

void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType) {
	
	GLuint theShader = glCreateShader(shaderType);
	const GLchar* theCode[1];
	theCode[0] = shaderCode;
	GLint codeLength[1];
	codeLength[0] = strlen(shaderCode);

	glShaderSource(theShader,1,theCode,codeLength);
	glCompileShader(theShader);

	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	//glLinkProgram(theShader);
	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
	if (!result) {
		glGetShaderInfoLog(theShader, sizeof(eLog), NULL, eLog);
		printf("Error linking shader : '%s' \n", eLog);
		return;
	}

	

	glAttachShader(theProgram,theShader);
	//return;
}

void CompileShaders() {
	shader = glCreateProgram();

	if (!shader) {
		printf("Error creating shader program! \n");
		return;
	}

	AddShader(shader , vshader,GL_VERTEX_SHADER);
	AddShader(shader , fshader, GL_FRAGMENT_SHADER);

	GLint result = 0;
	GLchar eLog[1024] = { 0 };

	glLinkProgram(shader);
	glGetProgramiv(shader, GL_LINK_STATUS, &result);
	if (!result) {
		glGetProgramInfoLog(shader,sizeof(eLog),NULL,eLog);
		printf("Error linking program : '%s' \n", eLog);
		return;
	}

	glValidateProgram(shader);

	glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
	if (!result) {
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("Error validate program : '%s' \n", eLog);
		return;
	}


}
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

		glUseProgram(shader);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0,3);
		glBindVertexArray(0);

		glUseProgram(0);
		glfwSwapBuffers(mainWindow);
	
	
	}
return 0;
}
