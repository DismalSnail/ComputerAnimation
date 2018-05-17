// Rocket.h: interface for the CRocket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(ROCKET_H)
#define ROCKET_H

#include "ParticleSystem.h"

/*
 *	State vector:
 *  0 : position x
 *  1 : position y
 *  2 : orientation x
 *  3 : orientation y
 *  4 : velocity x
 *  5 : velocity y
 *  6 : force x
 *  7 : force y
 *  8 : mass
 */

// Rocket mode
enum ROCKETMODE {FLYING, EXPLOSION, DEAD};
//Number of times this rocket will explode before it dies
#define TOTALEXPLOSION 5

class CRocket : public CParticleSystem  
{
public:
//Member functions:
	//Constructor
	CRocket(float* color);
	//Deconstructor
	virtual ~CRocket();
	//Set the initial state vector
	void SetInitialState(float* value);
	//Display the Rocket
	void Display();
	//One Euler step in simulation
	void EulerStep(float deltaT);
	//Compute the forces on this rocket
	void ComputeForce();
	//Compute the derivative of the state vector
	void FindDeriv();
	//Update the state vector using derivative vector and perform other necessary calculations
	void UpdateState();

//Member variables
	//Color of the rocket
	float color[3];
	//Current explosion	
	int explode;
	//Current mode of the rocket, see enum ROCKETMODE {FLYING, EXPLOSION, DEAD};
	int mode;	
};

#endif // !defined(ROCKET_H)
