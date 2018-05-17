// Simulation.h: interface for the CBehaviorSimulation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(BEHAVIORSIMULATION_H)
#define BEHAVIORSIMULATION_H

#include <qgl.h>
#include "Agent.h"
#include "Environment.h"

class CBehaviorSimulation  
{
public:
	void SetV0();
	void Display();
	void SimulationStep(float deltaT);
	void CreateAgents(int num);
	void SetGoal(vec2& goal);
	CBehaviorSimulation();
	virtual ~CBehaviorSimulation();

	CEnvironment env;
	int type;
};

#endif // !defined(SIMULATION_H)
