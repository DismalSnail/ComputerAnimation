// Simulation.cpp: implementation of the CSimulation class.
//
//////////////////////////////////////////////////////////////////////

#include "Simulation.h"
#include <stdlib.h>
#include <math.h>

#ifndef RAD
#define PI 3.14159265358979f
#define RAD (PI / 180.0f)
#endif
#ifndef GRAVITY
#define GRAVITY 9.8f
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSimulation::CSimulation()
{
	deltaT = 0.3f;
}

CSimulation::~CSimulation()
{
	for (vector<CSpark*>::iterator sparkIter = sparks.begin(); sparkIter != sparks.end(); sparkIter++)
		delete *sparkIter;
	for (vector<CRocket*>::iterator rocketIter = rockets.begin(); rocketIter != rockets.end(); rocketIter++)
		delete *rocketIter;
	rockets.clear();
	sparks.clear();
}

void CSimulation::Display()
{
	for (vector<CSpark*>::iterator sparkIter = sparks.begin(); sparkIter != sparks.end(); sparkIter++)
		(*sparkIter)->Display();
	for (vector<CRocket*>::iterator rocketIter = rockets.begin(); rocketIter != rockets.end(); rocketIter++)
		(*rocketIter)->Display();
}

int CSimulation::GetParticleNum()
{
	return sparks.size() + rockets.size();
}

/*
 *	FireRocket is called by CParticleView::OnKeyDown() function, when user presses a key.
 *  Input:	float posx. X value of the launch position of the rocket. Y position is always set to 0.
 *			float* color. color[0], color[1] and color[2] are the RGB color of this rocket.
 *                        It changes according to posx and it is provided for you.
 *  In this function, you want to generate a CRocket object and push_back it into rockets.
 *  The initial state of the CRocket object follows the constraints below:
 *  Position is posx and posy.
 *  Orientation is a random unit vector from 45degree to 135degree, assuming X axis is 0 degree.
 *  Speed is a random number from 60 to 120.
 *  Force is only GRAVITY.
 *  Mass is 1. 
 */
void CSimulation::FireRocket(float posx, float* color)
{
	float posy = 0.0f;
//Add your code here
}

/*
 *	Explode is called in CSimulation::EulerStep() when a rocket reaches its top height. 
 *  It is called CRocket::totalExplosion times to generate a series of rings of sparks.
 *  Input: float posx. X position where a ring of sparks are generated.
 *		   float posy. Y position where a ring of sparks are generated.
 *         float RocketSpeed. Rocket speed in X direction at the time of explosion.
 *         float* color. color[0], color[1] and color[2] are the RGB color of the rocket.
 *                       It will also be the color of the sparks it generates.
 *  In this function, you want to generate a number of sparks which forms a ring at [posx, posy]
 *  and push_back them into sparks.
 *  The initial state vector of each spark follows the constraints below:
 *  Number of sparks generated is a random number between 10 and 60. They evenly distribute on a ring.
 *  Position of explosion is posx and posy.
 *  The explosion gives every spark one same random velocity between 20 and 40.
 *         However, the real velocity of each spark is also affected by its shooting angle 
 *         and the velocity of rocket when it generates the explosion.
 *  Force on every spark is just the gravity.
 *  Mass of every spark is 1
 *  Total life of every spark is 20.         
 */
void CSimulation::Explode(float posx, float posy, float RocketSpeed, float* color)
{
//Add your code here
}

/*
 *	One Euler step of simulation. Please follow the instructions
 */
void CSimulation::EulerStep()
{
	//Step 1. Iterate through every CSpark in sparks. If the spark is dead(life is 0), erase it from sparks.
	//        Code is given. It is also an example of erasing an element from a vector.
	CSpark* spark;
	for (vector<CSpark*>::iterator sparkIter = sparks.begin(); sparkIter != sparks.end(); )
	{
		spark = *sparkIter;
		if (spark->dead)
		{
			sparkIter = sparks.erase(sparkIter);
			delete spark;
		}else
		{
			sparkIter++;
		}
	}
	
	//Step 2. Iterate through every CRocket in rockets. If the rocket is dead, erase it from rockets.
	//        If the rockets is in explosion mode generate a ring of sparks.
	CRocket* rocket;
	for (vector<CRocket*>::iterator rocketIter = rockets.begin(); rocketIter != rockets.end(); )
	{
	//Add your code here
	}

	//Step 3. Euler steps for valid sparks and rockets.
	//        Code is given.
	for (vector<CSpark*>::iterator sparkIter = sparks.begin(); sparkIter != sparks.end(); sparkIter++)
		(*sparkIter)->EulerStep(deltaT);
	for (vector<CRocket*>::iterator rocketIter = rockets.begin(); rocketIter != rockets.end(); rocketIter++)
		(*rocketIter)->EulerStep(deltaT);

}






















