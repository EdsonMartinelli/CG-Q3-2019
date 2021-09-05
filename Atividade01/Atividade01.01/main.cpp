#define GLEW_STATIC
#define GLFW_INCLUDE_NONE

#include <iostream>

#include <fstream>
#include <sstream>

#include <GLFW/glfw3.h>
#include <GL/glew.h>

struct vertex {
    float x, y, r, g, b;
};

using namespace std;

string readFile(string filename) {
    ifstream t(filename);
    stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

int main( void )
{
    GLFWwindow *window;
    
    // Initialize the library
    if ( !glfwInit( ) )
    {
        return -1;
    }
    
    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow( 640, 480, "Hello World", NULL, NULL );
    
    if ( !window )
    {
        glfwTerminate( );
        return -1;
    }
    
    // Make the window's context current
    glfwMakeContextCurrent( window );
    
    if (glewInit() != GLEW_OK) {
        cout << "Erro ao iniciar GLEW";
		return -1;
	}

    vertex v[] = {
                    {+0.0, +0.5, 1.0, 0.0, 0.0},
                    {-0.5, -0.5, 0.0, 1.0, 0.0},
                    {+0.5, -0.5, 0.0, 0.0, 1.0}
                };

    GLuint VBO1;
    glGenBuffers(1, &VBO1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(v), v, GL_STATIC_DRAW);
    glVertexPointer(2, GL_FLOAT, 0, nullptr);
    glEnableClientState(GL_VERTEX_ARRAY);


    string vss = readFile("vertex.sdr");
    string fss = readFile("fragment.sdr");
    const char *vertexShaderText = vss.c_str();
    const char *fragmentShaderText= fss.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderText, nullptr);
    glCompileShader(vertexShader);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderText, nullptr);
    glCompileShader(fragmentShader);
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    glVertexAttribPointer(0,2,GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0);
    glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)(sizeof(float)*2));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    while ( !glfwWindowShouldClose( window ) )
    {
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        /* Código de renderização OpenGL vai aqui */
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        // Render OpenGL here
        
        // Swap front and back buffers
        glfwSwapBuffers( window );
        
        // Poll for and process events
        glfwPollEvents( );
    }
    
    glfwTerminate( );
    
    return 0;
}


