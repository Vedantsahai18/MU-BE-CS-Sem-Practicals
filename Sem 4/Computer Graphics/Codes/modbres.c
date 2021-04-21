/*
 * modbres.c
 *
 *  Created on: 28-Jan-2019
 *      Author: 8340
 */
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>


void bres(){
    glBegin(GL_POINTS);
    float x1, x2, y1, y2, p, dx, dy;
    printf("Enter start points\n");
    scanf("%f%f", &x1, &y1);
    printf("Enter end points\n");
        scanf("%f%f", &x2, &y2);
    dx = x2 - x1;
    dy = y2 - y1;

    glVertex2f(x1, y1);

    if(abs(dy) <= abs(dx)){

        p = 2*dy - dx;
        for(;x1 <= x2;){
            if(p < 0){
                x1 = x1 + 1;
                p = p + 2*dy;
            }
            else{
                x1 = x1 + 1;
                y1 = y1 + 1;
                p = p + 2*dy - 2*dx;
            }
            glVertex2f(x1, y1);
        }
    }
    else{
        p = 2*dx - dy;
        for(;x1 <= x2;){
            if(p < 0){
                y1 = y1 + 1;
                p = p + 2*dx;
            }
            else{
                x1 = x1 + 1;
                y1 = y1 + 1;
                p = p + 2*dx - 2*dy;
            }
            glVertex2f(x1, y1);
        }
    }


    glEnd();
}

void disp()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    bres();//Call function
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
