/*
  curves.c

  Bezier curve drawing program


    q - Quit the program
    c - Clear the screen
    e - Erase the curves
    b - Draw Bezier curves

*/

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void dda(float x1, float y1, float x2, float y2)
{
    glColor3f(250.0, 0.0, 0.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    float dx, dy, steps, xi, yi, x, y;

    dx = x2 - x1;
    dy = y2 - y1;
    printf("x-> %f, y-> %f\n", x1, y1);
    printf("x-> %f, y-> %f\n", x2, y2);

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

#define MAX_CPTS  25   /* fixed maximum number of control points */

int n=0; //NUMBER OF VERTICES IN POLYGON
int a[2][40]; //POLYGON ARRAY

void display()
{
       int i;
       glClearColor(1, 1, 1, 1);
       glClear(GL_COLOR_BUFFER_BIT);
       glColor3f(0,0,0);
       glBegin(GL_LINES);
       for(i=0;i<n;i++)  //DISPLAYING FUNCTION
       {
               glVertex2f(a[0][i],a[1][i]);
               if(i+1!=n)
                      glVertex2f(a[0][i+1],a[1][i+1]);
}
glEnd(); glFlush ();
}

void mouse(int button, int state, int x, int y)
{
    float x1, y1, x2, y2;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

        x = (float) x;
        y = (float) y;

       /* save the point */
       printf("\n %d %d ",x,y);
        a[0][n] = x;
        a[1][n] = y;
        n++;
       display();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("Polygon");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutInitWindowSize(300,300);
    gluOrtho2D(0,300,300,0);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(5.0);
    glEnable(GL_MAP1_VERTEX_3);
    glutMainLoop();
}
