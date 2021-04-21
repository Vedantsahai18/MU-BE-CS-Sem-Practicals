#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double xmin=50, ymin=50, xmax=100,ymax=100; //window boundaries
double xvmin=200,yvmin=200,xvmax=300, yvmax=300; //viewport boundaries

int lessbit(double given, double window)
{
    if(given < window){
        return 1;
    }
    else{
        return 0;
    }
}

int greaterbit(double given, double window)
{
    if(window < given){
        return 1;
    }
    else{
        return 0;
    }
}

void cohensutherland(double x0,double y0,double x1,double y1)
{
    int b1[4], b2[4];
    double m = (y1-y0)/(x1-x0);
    double xn1, xn2, yn1, yn2;

    b1[0] = lessbit(x0, xmin);
    b1[1] = greaterbit(x0, xmax);
    b1[2] = lessbit(y0, ymin);
    b1[3] = greaterbit(y0, ymax);

    b2[0] = lessbit(x1, xmin);
    b2[1] = greaterbit(x1, xmax);
    b2[2] = lessbit(y1, ymin);
    b2[3] = greaterbit(y1, ymax);


    for(int i = 0; i < 4; i++){
        if(b1[i] == 1){
            if(i == 0){
                xn1 = xmin;
                yn1 = y0 + m*(xn1 - x0);
            }
            if(i == 1){
                xn1 = xmax;
                yn1 = y0 + m*(xn1 - x0);
            }
            if(i == 2){
                yn1 = ymin;
                xn1 = x0 + (1/m)*(yn1 - y0);
            }
            if(i == 3){
                yn1 = ymax;
                xn1 = x0 + (1/m)*(yn1 - y0);
            }
        }
    }

        for(int i = 0; i < 4; i++){
        if(b2[i] == 1){
            if(i == 0){
                xn2 = xmin;
                yn2 = y0 + m*(xn2 - x0);
            }
            if(i == 1){
                xn2 = xmax;
                yn2 = y0 + m*(xn2 - x0);
            }
            if(i == 2){
                yn2 = ymin;
                xn2 = x0 + (1/m)*(yn2 - y0);
            }
            if(i == 3){
                yn2 = ymax;
                xn2 = x0 + (1/m)*(yn2 - y0);
            }
        }
    }

    //window to viewport mappings
            double sx= (xvmax-xvmin)/(xmax-xmin);// scale parameters
            double sy= (yvmax-yvmin)/(ymax-ymin);
            double vx0= xvmin+(xn1-xmin)*sx;
            double vy0= yvmin+(yn1-ymin)*sy;
            double vx1= xvmin+(xn2-xmin)*sx;
            double vy1= yvmin+(yn2-ymin)*sy;
// draw a red colored viewport
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(xvmin,yvmin);
        glVertex2f(xvmax,yvmin);
        glVertex2f(xvmax,yvmax);
        glVertex2f(xvmin,yvmax);
        glEnd();
        glColor3f(0.0,0.0,1.0); //draw blue colored clip line
        glBegin(GL_LINES);
        glVertex2f(vx0,vy0);
        glVertex2f(vx1,vy1);
        glEnd();

}
void display()
{
    double x0=50,y0=25,x1=90,y1=120;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);          //draw a line with red color
    glBegin(GL_LINES);
    glVertex2d(x0,y0);
    glVertex2d(x1,y1);
    glEnd();
    glColor3f(0.0,0.0,1.0);     //draw a blue color window
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin,ymin);
    glVertex2f(xmax,ymin);
    glVertex2f(xmax,ymax);
    glVertex2f(xmin,ymax);
    glEnd();
    cohensutherland(x0,y0,x1,y1);
    glFlush();
}
void myinit()
{    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,499.0,0.0,499.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Cohen Sutherland");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
