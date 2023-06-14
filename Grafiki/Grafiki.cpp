// Hypocycloids & deltoid


#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <array>

struct Position {
    float x, y;
};

struct Figure {
    Position pos;
    bool isRight;
    float health;
};

Figure f = { 0, 0, false, 100 };

std::array<Position, 100> deltoid;
std::array<Position, 100> hypocycloids;


void initGraph();
void plotAxes();
void plotGraph();
void initGraph2();
void plotAxes2();
void plotGraph2();

void initGraph() {
    Position p;

    float x = 0.0;
    float xf = 2 * M_PI;
    float h = (xf - x) / deltoid.size();
    int i = 0;

    while (x < xf) {
        p.x = 2 * cos(x) + cos(2 * x);
        p.y = 2 * sin(x) - sin(2 * x);
        deltoid[i] = p;
        x = x + h;
        i++;
    }
};

void plotAxes() {
    glBegin(GL_LINE_STRIP);
    glColor3ub(19, 38, 18);
    glVertex2f(0, 0);
    glVertex2f(3, 0);
    glColor3ub(0, 0, 1);
    glVertex2f(0, 0);
    glVertex2f(0, 3);
};

void plotGraph() {
    glPushMatrix();
    glScalef(0.1, 0.1, 1);
    glTranslatef(5, 0, 0);


    glBegin(GL_LINE_STRIP);
    glColor3ub(19, 38, 18);
    for (int i = 0; i < deltoid.size(); i++)
        glVertex2f(deltoid[i].x, deltoid[i].y);
    glEnd();
    glPopMatrix();
};

void initGraph2() {
    Position p;

    float x = 0.0;
    float xf = 2 * M_PI;
    float h = (xf - x) / hypocycloids.size();
    int i = 0;

    while (x < xf) {
        p.x = cos(x) + (cos(5 * x) / 5);
        p.y = sin(x) - (sin(5 * x) / 5);
        hypocycloids[i] = p;
        x = x + h;
        i++;
    }
};

void plotAxes2() {
    glBegin(GL_LINE_STRIP);
    glColor3ub(19, 38, 18);
    glVertex2f(0, 0);
    glVertex2f(3, 0);
    glColor3ub(0, 0, 1);
    glVertex2f(0, 0);
    glVertex2f(0, 3);
};

void plotGraph2() {
    glPushMatrix();
    glScalef(0.2, 0.2, 1);
    glTranslatef(-3, 0, 0);


    glBegin(GL_LINE_STRIP);
    glColor3ub(19, 38, 18);
    for (int i = 0; i < hypocycloids.size(); i++)
        glVertex2f(hypocycloids[i].x, hypocycloids[i].y);
    glEnd();
    glPopMatrix();
};

void background() {
    glBegin(GL_QUADS);
    glColor3ub(194, 194, 194);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
}

void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    background();


    plotGraph2();
    plotGraph();


    glutSwapBuffers();
}

int main(int argc, char** argv){
    initGraph();
    initGraph2();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(2560, 1600);
    glutCreateWindow("Drawing Graphs");
    glutDisplayFunc(renderScene);
    glutMainLoop();

    return 1;
}
