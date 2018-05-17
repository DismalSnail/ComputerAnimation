// Simulation.h: interface for the CSimulation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(SIMULATION_H)
#define SIMULATION_H

#include <vector>
#include "Rocket.h"
#include "Spark.h"
using namespace std;

class CSimulation  
{
public:
//Member functions:
	//Constructor
	CSimulation();
	//Deconstructor
	virtual ~CSimulation();
	//Display all the particles
	void Display();
	//Calculate total number of particles
	int GetParticleNum();
	//One Euler step of the simulation
	void EulerStep();
	//When a rocket reaches its top height, it explodes and calls this function to generate sparks
	void Explode(float posx, float posy, float RocketSpeed, float* color);
	//When a key is pressed, Simulation calls this function to generate a rocket
	void FireRocket(float pos, float* color);	
	
//Member variables:
	//Vector of CRocket. Rockets in this vector are either still flying or generating sparks
	vector<CRocket*> rockets;
	//Vector of CSpark.
	vector<CSpark*> sparks;
	//Delta time for a Euler step.
	float deltaT;
};

#endif // !defined(SIMULATION_H)
