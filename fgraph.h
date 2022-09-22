#include <GL/freeglut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>

void draw_axises(float cx, float cy);
void reshape(int w, int h);
void timer(int k);
void draw_function(float a, float b, float (*func)(float));