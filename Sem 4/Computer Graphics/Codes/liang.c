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

int cliptest(double p,double q,double *t1,double *t2)
{      // p is denominator in division and q is numerator
// t1 is t entering and t2 is t leaving
    double t=q/p;
    if(p<0.0)        //potentially entry point ,update te
    {    if(t>*t1) *t1=t;
        if(t>*t2) return(0); //line portion is outside as in line no 2 where t(entering)
                                       // has become more than t(leaving)
    }
    else if(p>0.0) //potentially leaving point ,update tl
        {
        if(t<*t2) *t2=t;
            if(t<*t1) return(0); //line portion is outside
        }
        else if(p==0.0)
            { if(q<0.0)
                 return(0);//line parallel to edge but outside
            }
            return(1);
}

void liangbaraskylineclipanddraw(double x0,double y0,double x1,double y1)
{
    double dx= x1-x0,dy=y1-y0, te=0.0,tl=1.0;

    if(cliptest(-dx,x0-xmin,&te,&tl))// inside test wrt left edge
// t for the left edge is t=(xmin-x0) /dx .... order of numerator is reversed and you get -dx
    if(cliptest(dx,xmax-x0,&te,&tl))// inside test wrt right edge
// t for the right edge is t=(xmax-x0)/dx.... first parameter becomes q and second p then t=q/p
    if(cliptest(-dy,y0-ymin,&te,&tl))// inside test wrt bottom edge
// same story numerator by demoninator to find t
    if(cliptest(dy,ymax-y0,&te,&tl))// inside test wrt top edge
// in one way cohen sutherland and liang barasky are similar
    {
        if(tl<1.0)
        {
            x1=x0+tl*dx;
            y1=y0+tl*dy;
        }
        if(te>0.0)
        {
            x0=x0+te*dx;
            y0=y0+te*dy;
        }
    }
    //window to viewport mappings
            double sx= (xvmax-xvmin)/(xmax-xmin);// scale parameters
            double sy= (yvmax-yvmin)/(ymax-ymin);
            double vx0= xvmin+(x0-xmin)*sx;
            double vy0= yvmin+(y0-ymin)*sy;
            double vx1= xvmin+(x1-xmin)*sx;
            double vy1= yvmin+(y1-ymin)*sy;
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
        glVertex2d(vx0,vy0);
        glVertex2f(vx1,vy1);
        glEnd();

}
void display()
{
    double x0=60,y0=20,x1=80,y1=120;
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
    liangbaraskylineclipanddraw(x0,y0,x1,y1);
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
    glutCreateWindow("liang barsky line clipping algorithm");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
