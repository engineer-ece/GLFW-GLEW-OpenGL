##### sudo apt-get install libglfw3
##### sudo apt-get install libglfw3-dev
##### sudo apt-get install -y glew-utils
##### sudo apt-get install libglew-dev
##### sudo apt-get install -y libglm-dev


##### Compile build for C:

gcc -pthread -o test test.c -lglfw -lGLU -lGL -lGLEW -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl

### simple Compile build for C:

gcc -pthread -o test test.c -lglfw -lGLU -lGL  -lGLEW



##### Compile build for C++:

g++ -pthread -o test test.c -lglfw -lGLU -lGL -lGLEW -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl

### simple Compile build for c++:

g++ -pthread -o test test.c -lglfw -lGLU -lGL  -lGLEW

### compile command for window

g++ -std=c++11 -IF:\glfw\ExternalLibs\GLFW\glfw-3.3.2.bin.WIN64\include -IF:\glfw\ExternalLibs\GLEW\glew-2.1.0\include -IF:\glfw\ExternalLibs\GLM -LF:\glfw\ExternalLibs\GLFW\glfw-3.3.2.bin.WIN64\lib-mingw-w64 -LF:\glfw\ExternalLibs\GLEW\glew-2.1.0\lib\Release\x64 main.cpp -o yay F:\glfw\ExternalLibs\GLFW\glfw-3.3.2.bin.WIN64\lib-mingw-w64\libglfw3dll.a -lglew32s -lglfw3 -lopengl32 -lglu32 -lgdi32


