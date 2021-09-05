#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main( void )
{
    GLFWwindow *window;
    
    // Initialize the library
    if ( !glfwInit( ) )
    {
        return -1;
    }
    
    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL );
    
    if ( !window )
    {
        glfwTerminate( );
        return -1;
    }
    
    // Make the window's context current
    glfwMakeContextCurrent( window );
    
    glViewport( 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT ); 
    glMatrixMode( GL_PROJECTION ); 
    glLoadIdentity( ); 
    glOrtho( 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1 );
    glMatrixMode( GL_MODELVIEW ); 
    glLoadIdentity( );
    
    GLfloat pointVertex[] = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
    GLfloat pointVertex2[] = { SCREEN_WIDTH * 0.75, SCREEN_HEIGHT / 2 };
    
    // Loop until the user closes the window
    while ( !glfwWindowShouldClose( window ) )
    {
        glClear( GL_COLOR_BUFFER_BIT );
        
        // Render OpenGL here
        glEnable( GL_POINT_SMOOTH ); // make the point circular
        glEnableClientState( GL_VERTEX_ARRAY ); // tell OpenGL that you're using a vertex array for fixed-function attribute
        glPointSize( 50 ); // must be added before glDrawArrays is called
        glVertexPointer( 2, GL_FLOAT, 0, pointVertex ); // point to the vertices to be used
        glDrawArrays( GL_POINTS, 0, 1 ); // draw the vertixes
        glDisableClientState( GL_VERTEX_ARRAY ); // tell OpenGL that you're finished using the vertex arrayattribute
        glDisable( GL_POINT_SMOOTH ); // stop the smoothing to make the points circular
        
        glEnableClientState( GL_VERTEX_ARRAY ); // tell OpenGL that you're using a vertex array for fixed-function attribute
        glVertexPointer( 2, GL_FLOAT, 0, pointVertex2 ); // point to the vertices to be used
        glPointSize( 10 ); // must be added before glDrawArrays is called
        glDrawArrays( GL_POINTS, 0, 1 ); // draw the vertixes
        glDisableClientState( GL_VERTEX_ARRAY ); // tell OpenGL that you're finished using the vertex arrayattribute
        
        // Swap front and back buffers
        glfwSwapBuffers( window );
        
        // Poll for and process events
        glfwPollEvents( );
    }
    
    glfwTerminate( );
    
    return 0;
}