#include "fgraph.h"

void draw_axises(float cx, float cy)
{
    glColor3f(1.0, 0.0, 1.0);

    glVertex2f(cx -10,cy);
    glVertex2f(cx + 10, cy);
    glVertex2f(cx + 10, cy);
    glVertex2f(cx + 9.5, cy + 0.5);
    glVertex2f(cx + 10, cy);
    glVertex2f(cx + 9.5, cy -0.5);

    glVertex2f(cx, cy - 10);
    glVertex2f(cx, cy + 10);
    glVertex2f(cx, cy + 10);
    glVertex2f(cx + 0.5, cy + 9.5);
    glVertex2f(cx, cy + 10);
    glVertex2f(cx - 0.5, cy + 9.5);


}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);

}

void draw_function(float a, float b, float (*func)(float))
{
    float h = (b - a) / 1000;
    for(a = a; a < b; a+=h)
        glVertex2f(a, func(a));
        //glVertex2f(a+h, func(a+h));
}

void timer(int k)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
    
}