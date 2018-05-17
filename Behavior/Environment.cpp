// Environment.cpp: implementation of the CEnvironment class.
//
//////////////////////////////////////////////////////////////////////

#include "Environment.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEnvironment::CEnvironment()
{
    groundSize = 1000.0;
    obstaclesNum = 0;
    obstacles = NULL;
    colors = NULL;
}

CEnvironment::~CEnvironment()
{
    if(obstacles)
        delete[] obstacles;
    if (colors)
        delete[] colors;
}

void CEnvironment::GenerateObstacles(int n)
{
    int i;
    if (obstacles)
        delete[] obstacles;
    if (colors)
        delete[] colors;
    obstaclesNum = n;
    obstacles = new vec3[n];
    colors = new float[4 * n];
    int delta = int(groundSize * 0.8);
    for (i = 0; i < n; i++){
        obstacles[i][0] = float(rand() % delta * 2 - delta);
        obstacles[i][1] = float(rand() % delta * 2 - delta);
        obstacles[i][2] = float(rand() % 100 + 60);
        colors[i * 4] = float(rand() % 250) / 255.0;
        colors[i * 4 + 1] = float(rand() % 250) / 255.0;
        colors[i * 4 + 2] = float(rand() % 250) / 250.0;
        colors[i * 4 + 3] = 1.0;
    }
}

void CEnvironment::Display()
{
    for (int i = 0; i < obstaclesNum; i++){
        glPushMatrix();
        glTranslated(obstacles[i][0], 0.0, obstacles[i][1]);
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, &colors[i * 4]);
        glutSolidSphere(obstacles[i][2], 24, 24);
        glPopMatrix();
    }
}
