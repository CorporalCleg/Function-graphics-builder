#include "fgraph.h"

void display(); 
void reshape(int, int);
void timer(int);
void processNormalKeys(unsigned char key, int x, int y);

float rx = 0;
float ry = 0;
float scx = 1;
float scy = 1;

float a;

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0f);
}
float xq(float t){
    return pow(a * t, 1.5);///1 * pow(t, 1.5);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    scanf("%f", &a);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(500, 500);

    glutCreateWindow("win-1");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(processNormalKeys);
    
    init();

    glutMainLoop();
    return 0;
}


void display()
{    
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPointSize(2.0);
    //draw
    glTranslated(rx, ry, 0);
    glScalef(scx, scy, 1);

    glBegin(GL_LINES);
    draw_axises(0,0);
    glEnd();

    glBegin(GL_POINTS);
    int i;
    glColor3f(1.0, 0.9, 0.0);
    for(i = -1 * b; i < b; i++)
    {
        glVertex2f(0, i);
        glVertex2f(i, 0);
    }
    glEnd();

    glColor3f(0.3, 0.9, 0.0);
    glBegin(GL_LINE_STRIP);
    draw_function(0, xq);
    glEnd();

/*
    glBegin(GL_TRIANGLES);

    glVertex2f(0, 3);
    glVertex2f(1, 0);
    glVertex2f(-1, 0);

    glEnd();*/

    /*glBegin(GL_POINTS);
    drawline(0, 0, 8, 8);
    drawline(0, 0, 1, 2);
    drawline(1, 2, 8, 8);
    glEnd();*/

    
    glFlush();
}


void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 'a')
		rx+=1;
    else if (key == 'd')
		rx-=1;
    else if (key == 's')
		ry+=1;
    else if (key == 'w')
		ry-=1;
    else if (key == '+')
    {
		scx*=2;
        scy*=2;
    }
    else if (key == '-')
    {
		scx*=0.5;
        scy*=0.5;
    }
    else
        exit(0);
    glutPostRedisplay();
}


