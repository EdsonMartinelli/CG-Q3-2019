g++ -fexceptions -g -O3 -std=c++11 -g -Iinclude -c main.cpp -o main.o
g++ -fexceptions -g -O3 -std=c++11 -g -Iinclude -c shader.cpp -o shader.o
g++ -Llib -o main.exe main.o shader.o -lglew32s -lglfw3 -lgdi32 -lopengl32
main.exe