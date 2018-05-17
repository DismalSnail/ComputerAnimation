// Spark.h: interface for the CSpark class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(SPARK_H)
#define SPARK_H

#include "ParticleSystem.h"

/*
 *	State vector:
 *  0 : position x
 *  1 : position y
 *  2 : velocity x
 *  3 : velocity y
 *  4 : force x
 *  5 : force y
 *  6 : mass
 *  7 : life
 */

class CSpark : public CParticleSystem  
{
public:
//Member functions:
	//Constructor
	CSpark(float* color);
	//Deconstructor
	virtual ~CSpark();
	//Set the initial state vector
	void SetInitialState(float* value);
	//Display the spark
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
	//Spark color
	float color[3];
	//Coefficients of restitution
	float COR;
};

#endif // !defined(SPARK_H)
