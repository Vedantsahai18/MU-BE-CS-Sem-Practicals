#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

void ellipse()
{
	glBegin(GL_POINTS);
	float rx,ry,xc,yc,p1,p2,x,y;
	printf("Enter rx ,ry :");
	scanf("%f%f",&rx,&ry);
	printf("Enter the centre of the ellipse :");
	scanf("%f%f",&xc,&yc);
	x = 0;
	y = ry;
	p1 = ry*ry - rx*rx*ry +	0.25*rx*rx;
	while(2*ry*ry*x < 2*rx*rx*y)
	{
		glVertex2f(xc+x, yc+y);
		glVertex2f(xc+x,yc-y);
		glVertex2f(xc-x,yc-y);
		glVertex2f(xc-x,yc+y);
		if (p1 < 0)
		{
			x= x + 1;
			p1 = p1 +ry*ry+2*ry*ry*x;
		}
		else{
			x = x +1;
			y = y -1;
			p1 = p1 + 2*ry*ry*x - 2*rx*rx*y + ry*ry;
		}
	}
	p2 = ((x+0.5)*(x+0.5)*ry*ry) + ((y-1)*(y-1)*rx*rx)- (rx*ry*rx*ry);
	while(y > 0)
	{
		glVertex2f(xc+x, yc+y);
		glVertex2f(xc+x,yc-y);
		glVertex2f(xc-x,yc-y);
		glVertex2f(xc-x,yc+y);
		if(p2 > 0)
		{
			y = y - 1;
			p2 = p2 + rx*rx - 2*rx*rx*y;
		}
		else
		{
			x = x + 1;
			y = y - 1;
			p2 = p2 + 2*ry*ry*x - 2*rx*rx*y + rx*rx;
		}
	}

	glEnd();
}


void disp()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	ellipse();
	glFlush();
}//disp


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
