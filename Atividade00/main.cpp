#define GLEW_STATIC
#define GLFW_INCLUDE_NONE
#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <string>

typedef struct velocidade {
    float vel, velx, vely;
} Velocidade;

typedef struct Posicao{
    float xc, yc;
} Posicao;

Posicao pos = {.xc = 0, .yc = 0};

float maxPontos (float objeto[][2], int n, char eixo);
float minPontos (float objeto[][2], int n, char eixo);
void velAtualizada1 (Velocidade* velAtual, float objeto[][2], int n, Posicao pos);
void velAtualizada2 (Velocidade* velAtual, float objeto[][2], int n, Posicao pos);
void velAtualizada3 (Velocidade* velAtual, float objeto[][2], int n, Posicao pos);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
if (key == GLFW_KEY_LEFT) pos.xc = pos.xc - 0.01;
if (key == GLFW_KEY_RIGHT) pos.xc = pos.xc + 0.01;
if (key == GLFW_KEY_UP) pos.yc = pos.yc + 0.01;
if (key == GLFW_KEY_DOWN) pos.yc = pos.yc - 0.01;
}

int main(void)
{
    Velocidade* velAtual = (Velocidade*) malloc(sizeof(Velocidade));
    velAtual -> vel = 0.001;
    velAtual -> velx = velAtual -> vel;
    velAtual -> vely = velAtual -> vel;
    int nVertices = 3;
    float triangulo [nVertices][2] = {{-0.4, -0.4},
                                      { 0.0,  0.3},
                                      { 0.4, -0.4}};
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(800, 600, "Atividade00", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);


    if (glewInit()!= GLEW_OK) {
        using namespace std;
        cout << "Erro ao iniciar GLEW";
        return 0;
    }

    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0, 0, 1);
        glBegin(GL_TRIANGLES);
            glColor3f(0, 0, 1);
            glVertex2f(pos.xc + triangulo[0][0], pos.yc + triangulo[0][1]);
            glColor3f(0, 1, 0);
            glVertex2f(pos.xc + triangulo[1][0], pos.yc + triangulo[1][1]);
            glColor3f(1, 0, 0);
            glVertex2f(pos.xc + triangulo[2][0], pos.yc + triangulo[2][1]);
        glEnd();

        velAtualizada3(velAtual, triangulo,nVertices, pos);
        pos.xc = pos.xc + velAtual -> velx;
        pos.yc = pos.yc + velAtual -> vely;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    free(velAtual);
    glfwTerminate();
    return 0;
}

float maxPontos (float objeto[][2], int n, char eixo){
    int i = 0, eixoInt = 0;
    float x = 0;
    (eixo == 'x') ? eixoInt = 0 : eixoInt = 1;
    for(; i < n; i++){
        if(objeto[i][eixoInt] > x)
            x = objeto[i][eixoInt];
    }
    return x;
}

float minPontos (float objeto[][2], int n, char eixo){
    int i = 0, eixoInt = 0;
    float x = 0;
    (eixo == 'x') ? eixoInt = 0 : eixoInt = 1;
    for(; i < n; i++){
        if(objeto[i][eixoInt] < x)
            x = objeto[i][eixoInt];
    }
    return x;
}

void velAtualizada1(Velocidade* velAtual, float objeto[][2], int nVertices, Posicao pos){
    if(pos.xc >= 1 - maxPontos(objeto, nVertices, 'x')){
        velAtual -> velx = - (velAtual -> vel);
    }
    if(pos.xc <= - 1 - minPontos(objeto, nVertices, 'x')){
        velAtual -> velx = velAtual -> vel;
    }
    velAtual -> vely = 0;
}

void velAtualizada2(Velocidade* velAtual, float objeto[][2], int nVertices, Posicao pos){
    if(pos.yc >= 1 - maxPontos(objeto, nVertices, 'y')){
         velAtual -> vely = - (velAtual -> vel);
    }
    if(pos.yc <= - 1 - minPontos(objeto, nVertices, 'y')){
        velAtual -> vely = velAtual -> vel;
    }
    velAtual -> velx = 0;
}

void velAtualizada3(Velocidade* velAtual, float objeto[][2], int nVertices, Posicao pos){
    if(pos.xc >= 1 - maxPontos(objeto, nVertices, 'x')){
        velAtual -> velx = - (velAtual -> vel);
    }
    if(pos.xc <= - 1 - minPontos(objeto, nVertices, 'x')){
        velAtual -> velx = velAtual -> vel;
    }
    if(pos.yc >= 1 - maxPontos(objeto, nVertices, 'y')){
         velAtual -> vely = - (velAtual -> vel);
    }
    if(pos.yc <= - 1 - minPontos(objeto, nVertices, 'y')){
        velAtual -> vely = velAtual -> vel;
    }
}
