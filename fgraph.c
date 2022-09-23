#include "fgraph.h"

void draw_axises(float cx, float cy)
{
    glColor3f(1.0, 0.0, 1.0);

    glVertex2f(cx - b,cy);
    glVertex2f(cx + b, cy);
    glVertex2f(cx + b, cy);
    glVertex2f(cx + b * 0.99, cy + b* 0.01);
    glVertex2f(cx + b, cy);
    glVertex2f(cx + b * 0.99, cy - b * 0.01);

    glVertex2f(cx, cy - b);
    glVertex2f(cx, cy + b);
    glVertex2f(cx, cy + b);
    glVertex2f(cx + b * 0.01, cy + b * 0.99);
    glVertex2f(cx, cy + b);
    glVertex2f(cx - b * 0.01, cy + b * 0.99);


}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);

}

void draw_function(float a, float (*func)(float))
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