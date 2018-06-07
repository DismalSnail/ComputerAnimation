// Rocket.cpp: implementation of the CRocket class.
//
//////////////////////////////////////////////////////////////////////

#include "Rocket.h"

#include <math.h>
#include <stdlib.h>
#include <time.h>
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

CRocket::CRocket(float* color): CParticleSystem(9)
{
	explode = -1;
	memcpy(this->color, color, sizeof(float) * 3);
	mode = FLYING;
}

CRocket::~CRocket()
{

}

void CRocket::SetInitialState(float* value)
{	
	SetState(value);
}

void CRocket::Display()
{
	if (explode < 0){
		float degree;
		glPushMatrix();
		glTranslatef(state[0], state[1], 0);
		degree = atan2(state[2], state[3]);
		degree = -1.0f * degree / RAD;
		glRotatef(degree, 0.0f, 0.0f, 1.0f);
		glColor3f(color[0], color[1], color[2]);
		glBegin(GL_TRIANGLES);
		glVertex2f(-10.0f, 0.0f);
		glVertex2f(10.0f, 0.0f);
		glVertex2f(0.0f, 30.0f);
		glEnd();
		glPopMatrix();
	}
}

void CRocket::EulerStep(float deltaT)
{
	this->deltaT = deltaT;
	ComputeForce();
	FindDeriv();
	UpdateState();
}

/*
 *	ComputeForce() computes the forces applied to this rocket
 *  In this fucntion, you need to set the correct value for state[6] and state[7], 
 *      which are forces along X and Y axis.
 */
void CRocket::ComputeForce()
{
//Add your code here
}

/*
 *	FindDeriv() computes the derivative of the state vector.
 *  Remeber that the orientation of the rocket is aligned with it velocity direction.
 *  In this function you need to write correct value to each deriv[i].
 */
void CRocket::FindDeriv()
{
//Add your code here
	deriv[0] = state[4];
	deriv[1] = state[5];
	deriv[2] = 0;
	deriv[3] = 0;
	deriv[4] = state[6] / state[8];
	deriv[5] = state[7] / state[8];
	deriv[6] = 0;
	deriv[7] = 0;
}

/*
 *	UpdateState() updates the state vector using derivative vector.
 *  In this function, state[i] should get correct value using the value from derive[i].
 *  You should also determine the mode of the rocket.
 *  If it reaches its top height, mode = EXPLOSION. It prepares for explosion in the next Euler step of simulation. 
 *  If it is in EXPLOSION mode, check to see if it has completed TOTALEXPLOSION times of explosion. If so, make it dead.
 *  Remeber to modify explode and dead accordingly.
 */
void CRocket::UpdateState()
{
//Add your code here
	state[0] += deriv[0] * deltaT;
	state[1] += deriv[1] * deltaT;

	state[2] = state[4];
	state[3] = state[5];

	state[4] += deriv[4] * deltaT;
	state[5] += deriv[5] * deltaT;

	state[6] += deriv[6] * deltaT;
	state[7] += deriv[7] * deltaT;

	if (mode == EXPLOSION)
	{
		if (explode < TOTALEXPLOSION)
		{
			explode++;
		}
		else
		{
			mode = DEAD;
			dead = true;
		}
		return;
	}
	if (state[5]<=0)
	{
		mode = EXPLOSION;
		explode = 1;
	}
}