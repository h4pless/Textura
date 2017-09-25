#include <windows.h>
#include <gl/glut.h>
#include <iostream>
#include <vector>
#include "texture.h"

/**
 *  reorganizar a função de printar o dino pra ficar mais leve
 *
 *
 *
 *
 */

using namespace std;

struct p{
    int x, y;
};

vector<p> points;

int size_x = 800;
int size_y = 480;
int pixel_size = 15;

float toRGBf(int x);
void draw();
void init();
void makeGrid();
void makeAxes();
void drawLines();
void AlteraTamanhoJanela(int w, int h);
void drawTexture(Texture *t1);


float toRGBf(int x){
    return (float)x/255;
}

void draw(){

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    /*
    glColor3f(1.0, 1.0, 1.0);
    makeGrid();

    glLineWidth(3);
    glColor3f(0.0, 0.0, 0.0);

    makeAxes();
    glLineWidth(1);
    */

    glColor3f(0.0, 0.0, 0.0);


    Texture *t1 = new Texture();
    for(int i = 0; i < size_x; i+=155){
        for(int j = 0; j < size_y; j+=130){
            glViewport(0+i, 0+j, 150, 120);
            drawTexture(t1);
        }
    }
    glFlush();
}

void init(){

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0 , size_x, 0, size_y);
    glClearColor(toRGBf(85), toRGBf(125), toRGBf(145), 1.0f);
}

void makeGrid(){

    for(int i = 0; i<=size_x; i+=pixel_size){
        glBegin(GL_LINES);
            glVertex2i(i, 0);
            glVertex2i(i, size_y);
        glEnd();
        glFlush();
    }
    for(int j = 0; j<=size_y; j+=pixel_size){
        glBegin(GL_LINES);
            glVertex2i(0, j);
            glVertex2i(size_x, j);
        glEnd();
        glFlush();
    }
}


void makeAxes(){

    glBegin(GL_LINES);
        glVertex2i(3*pixel_size, 0);
        glVertex2i(3*pixel_size, size_y);
        glVertex2i(0, 3*pixel_size);
        glVertex2i(size_x, 3*pixel_size);
    glEnd();
    glFlush();
}

void drawLines(){

    glBegin(GL_LINE_STRIP);
        for(int i = 0; i<points.size(); i++)
            glVertex2i(points.at(i).x, points.at(i).y);
    glEnd();
    glFlush();

}

void drawTexture(Texture *t1){

    int nucleos = t1->retornaPontos().at(0).at(0);
    int x = 1;
    for(int i = 0; i < nucleos ; i++){
        glBegin(GL_LINE_STRIP);
        for(int j = 0 ; j < t1->retornaPontos().at(x).at(0); j++){
            glVertex2i(t1->retornaPontos().at(x+j+1).at(0), t1->retornaPontos().at(x+j+1).at(1));
        }
        glEnd();
        glFlush();
        glBegin(GL_LINE_STRIP);
        for(int k = 0; k < t1->retornaPontos().at(x).at(0); k++){
            glVertex2i(size_x - t1->retornaPontos().at(x+k+1).at(0), size_y - t1->retornaPontos().at(x+k+1).at(1));
        }
        glEnd();
        glFlush();
        x+=t1->retornaPontos().at(x).at(0)+1;
        //cout << "x: " << x << endl;
    }

}



void AlteraTamanhoJanela(int w, int h){

    draw();
    //size_x = w;
    //size_y = h;
}

int main(void){


    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(size_x,size_y);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Função Gauss");

    glutDisplayFunc(draw);
    glutReshapeFunc(AlteraTamanhoJanela);



    init();





    glutMainLoop();
}

