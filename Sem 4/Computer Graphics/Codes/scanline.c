

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include<stdio.h>
#include<math.h>
#include <stdlib.h>


// Program for Scanline

struct line{
    float x1, y1, x2, y2, m;
    int flag;
};
struct vertex{
    float x, y;
};



void dda(float x1, float y1, float x2, float y2)
{
    glBegin(GL_POINTS);
    float dx, dy, steps, xi, yi, x, y;


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
    glEnd();
}

void scanline(){
    int i, n, ymax = 0, ymin = 9999, j, k = 0;
    float x[10];
    struct line l[10];
    struct vertex v[10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    /*n = 6;
    v[1].x = 0;
    v[1].y = 0;
    v[2].x = 100;
    v[2].y = 100;
    v[3].x = 200;
    v[3].y = 50;
    v[4].x = 300;
    v[4].y = 100;
    v[5].x = 400;
    v[5].y = 0;
    v[6].x = 200;
    v[6].y = 100;*/

    for(i = 1;i <= n; i++){
        printf("Enter x and y co-ordinates: ");
        scanf("%f%f", &v[i].x, &v[i].y);
        if(ymax < v[i].y){
            ymax = v[i].y;
        }
        if(ymin > v[i].y){
            ymin = v[i].y;
        }
    }

    for(i = 1; i <= n; i++){
        if(i == n){
            l[i].x1 = v[i].x;
            l[i].y1 = v[i].y;
            l[i].x2 = v[n-(n-1)].x;
            l[i].y2 = v[n-(n-1)].y;
        }
        else{
            l[i].x1 = v[i].x;
            l[i].y1 = v[i].y;
            l[i].x2 = v[i+1].x;
            l[i].y2 = v[i+1].y;
        }
        l[i].m = (l[i].x2 - l[i].x1)/(l[i].y2 - l[i].y1); // We do this to find next x position (check notes)
    }

    while(ymax >=  ymin){
        j = 0;
        for(i = 1; i <= n; i++){
            if((l[i].y1 >= ymax && l[i].y2 < ymax) || (l[i].y2 >= ymax && l[i].y1 < ymax)){
                    l[i].flag = 1;
               }
            else{
                l[i].flag = 0;
            }
            if(l[i].flag == 1){
                x[j] = l[i].x1 + l[i].m * (ymax - l[i].y1); //xk+1 = 1/m + xk here m is already 1/m
                j++;
            }
        }
        for( i = 0; i < j; i+=2){
            dda(x[i], ymax, x[i+1], ymax);
        }
        ymax = ymax - 1;
    }
}

void disp()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,1);
    scanline(); //Call function
    glFlush();
}


int main(int argv,char **argc)
{
    glutInit(&argv,argc);
    glutInitWindowSize(600,600);
    glutCreateWindow("Scanline");
    gluOrtho2D(-600, 600, -600, 600);
    glutDisplayFunc(disp);
    glutMainLoop();
    return 0;
}
