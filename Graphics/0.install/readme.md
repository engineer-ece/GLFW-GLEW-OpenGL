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

