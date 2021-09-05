g++ -fexceptions -g -O3 -std=c++11 -g -Iinclude -c main.cpp -o main.o
g++ -fexceptions -g -O3 -std=c++11 -g -Iinclude -c common\shader.cpp -o common\shader.o
g++ -fexceptions -g -O3 -std=c++11 -g -Iinclude -c common\texture.cpp -o common\texture.o
g++ -Llib -o main.exe main.o common\texture.o common\shader.o -lglew32s -lglfw3 -lgdi32 -lopengl32
main.exe