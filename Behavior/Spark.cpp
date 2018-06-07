// Spark.cpp: implementation of the CSpark class.
//
//////////////////////////////////////////////////////////////////////

#include "Spark.h"
#include <math.h>

#ifndef GRAVITY
#define GRAVITY 9.8f
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSpark::CSpark(float* color): CParticleSystem(8)
{
	memcpy(this->color, color, sizeof(float)*3);
	//coefficients of restitution equals 0.6
	COR = 0.6f;
}

CSpark::~CSpark()
{

}

void CSpark::SetInitialState(float *value)
{
	memcpy(state, value, sizeof(float) * dim);
}

void CSpark::Display()
{
	if (!dead){
		float s = 1.0;
		if (state[7] < 10){
			s = state[7] / 10.0f;
		}
		glColor3f(color[0] * s, color[1] * s, color[2] * s);
		glPushMatrix();
		glBegin(GL_POLYGON);
		float angle;
		float x = state[0];
		float y = state[1];
		float r = 2.0;
		for (int i = 0; i < 20; i++){
			angle = float(i) / 20 * 2 * 3.14159f;
			glVertex2f(x + r * cos(angle), y + r * sin(angle));
		}
		glEnd();
		glPopMatrix();
	}
}

void CSpark::EulerStep(float deltaT)
{
	this->deltaT = deltaT;
	ComputeForce();
	FindDeriv();
	UpdateState();
}

/*
 *	ComputeForce() computes the forces applied to this spark
 *  In this fucntion, you need to set the correct value for state[6] and state[7], 
 *  which are forces along X and Y axis.
 */
void CSpark::ComputeForce(){
//Add your code here
}

/*
 *	FindDeriv() computes the derivative of the state vector.
 *  Remeber to subtract its life counts.
 */
void CSpark::FindDeriv(){
//Add your code here
	deriv[0] = state[2];
	deriv[1] = state[3];
	deriv[2] = state[4] / state[6];
	deriv[3] = state[5] / state[6];
	deriv[7] = -1;
}

/*
 *	UpdateState() updates the state vector using derivative vector.
 *  In this function, state[i] should get correct value using the value from derive[i].
 *  You should consider the situation when the spark bounce onto the ground. 
 *  You should model its boucing using the given COR(coefficients of restitution).
 *  Remember to set it to dead when its life count falls below 0;
 */
void CSpark::UpdateState(){
//Add your code here	
	state[0] += deriv[0] * deltaT;
	state[1] += deriv[1] * deltaT;

	state[2] += deriv[2] * deltaT;
	state[3] += deriv[3] * deltaT;

	state[7] += deriv[7] * deltaT;

	if (state[7] <= 0.0f)
	{
		dead = true;
		return;
	}
	if (state[1] <= 0.0f && state[3] < 0.0f)
	{
		state[3] *= -1.0f*COR;
		state[2] *= 1.0f*COR;
	}
}



















