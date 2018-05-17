// ParticleSystem.h: interface for the CParticleSystem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(PARTICLESYSTEM_H)
#define PARTICLESYSTEM_H

#include <qgl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class CParticleSystem
{
public:
//Member functions:
	//Constructor
	CParticleSystem(int dim);
	//Deconstructor
	virtual ~CParticleSystem();
	//Get the state vector
	float* GetState();
	//Set the state vector
	void SetState(float* value);
//Virtual functions:
	//Compute forces on this particle
	virtual void ComputeForce() = 0;
	//Find the derivative of the state vector
	virtual void FindDeriv() = 0;
	//Update the state vector with the derivative vector and perform other necessary calculations
	virtual void UpdateState() = 0;
	//One Euler step of the simulation of this particle
	virtual void EulerStep(float deltaT) = 0;

//Member variables
	//Dimension of the state vector
	int dim;
	//State vector
	float* state;
	//Derivative of the state vector
	float* deriv;
	//Delta time of one simulation step
	float deltaT;
	//Indicate if the particle is dead or not
	bool dead;
};

#endif // !defined(PARTICLESYSTEM_H)
