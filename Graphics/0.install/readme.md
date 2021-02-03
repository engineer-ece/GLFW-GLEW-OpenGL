sudo apt-get install libglfw3
sudo apt-get install libglfw3-dev
sudo apt-get install -y glew-utils
sudo apt-get install libglew-dev
sudo apt-get install -y libglm-dev

Compile build:

g++ -pthread -o test test.c -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl
