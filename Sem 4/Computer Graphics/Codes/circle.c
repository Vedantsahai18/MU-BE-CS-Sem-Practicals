/*
 * circle.c
 *
 *  Created on: 28-Jan-2019
 *      Author: 8340
 */
#include<stdio.h>
#include<stdlib.h>
#include<GLUT/glut.h>



void circle(){
    glBegin(GL_POINTS);
    float x1, y1, p, r, x, y;
    printf("Enter radius of circle\n");
    scanf("%f", &r);
    printf("Enter center of circle\n");
    scanf("%f%f", &x1, &y1);
    x = 0;
    y = r;
    p = 5/4 - r;

    do{
        glVertex2f(x1 + x, y1 + y);
        glVertex2f(y1 + y,x1 + x);
        glVertex2f(x1 - x,y1 + y);
        glVertex2f(y1 + y,x1 - x);
        glVertex2f(x1 - x,y1 - y);
        glVertex2f(y1 - y,x1 - x);
        glVertex2f(x1 + x,y1 - y);
        glVertex2f(y1 - y,x1 + x);

        if(p <= 0){
            x = x + 1;
            p = p + 2*x + 3;
        }
        else{
            x = x + 1;
            y = y - 1;
            p = p + 2*x - 2*y + 5;
        }

    }while(x <= y);


    glEnd();
}

void disp()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    circle();//Call function
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
