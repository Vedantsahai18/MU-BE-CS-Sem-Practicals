/*
 * dda.c
 *
 *  Created on: 14-Jan-2019
 *      Author: 8340
 */

#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

void dda()
{
    glBegin(GL_POINTS);
    float x1, y1, x2, y2, dx, dy, steps, xi, yi, x, y;

    printf("Enter co-ordinates of first point\n");
    scanf("%f%f", &x1, &y1);
    printf("Enter co-ordinates of second point\n");
    scanf("%f%f", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    if(abs(dx) > abs(dy)){
        steps = abs(dx);
    }
    else{
        steps = abs(dy);
    }

    xi = dx/steps;
    yi = dy/steps;
    x = x1;
    y = y1;
    glVertex2f(x,y);

    for(float i = 1; i < steps; i++){
        x = x + xi;
        y = y + yi;
        glVertex2f(x,y);
    }
    printf("x-> %f, y-> %f", x, y);
    glEnd();
}


void disp()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    dda(); //Call function
    glFlush();
}


int main(int argv,char **argc)
{
    glutInit(&argv,argc);
    glutInitWindowSize(300,300);
    glutCreateWindow("window");
    gluOrtho2D(0,300,0,300);
    glutDisplayFunc(disp);
    glutMainLoop();
    return 0;
}
