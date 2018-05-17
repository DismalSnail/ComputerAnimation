// Simulation.cpp: implementation of the CBehaviorSimulation class.
//
//////////////////////////////////////////////////////////////////////

#include "BehaviorSimulation.h"
#include <QDebug>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBehaviorSimulation::CBehaviorSimulation()
{
	env.goal = vec2(0.0, 0.0);
	CAgent::InitValues();
}

CBehaviorSimulation::~CBehaviorSimulation()
{
	CAgent::ClearAgents();
}

void CBehaviorSimulation::SetGoal(vec2 &goal)
{
	env.goal = goal;
	if (type == WANDER)
		SetV0();
}

void CBehaviorSimulation::CreateAgents(int num)
{
	CAgent* tmp;
	CAgent::ClearAgents();
	float color[3];
	float pos[2];
	float angle;
	for (int i = 0; i < num; i++){
		color[0] = float(rand() % 250) / 255.0;
		color[1] = float(rand() % 250) / 255.0;
		color[2] = float(rand() % 250) / 250.0;
		tmp = new CAgent(color, &env);
		pos[0] = float(rand() % int(env.groundSize * 2) - env.groundSize);
		pos[1] = float(rand() % int(env.groundSize * 2) - env.groundSize);
		angle = float(rand() % 360 - 180) / 180.0 * M_PI;
		tmp->SetInitState(pos, angle);
	}
}

void CBehaviorSimulation::SimulationStep(float deltaT)
{
	//Sense:
	int s = CAgent::agents.size();
	int i;
	for (i = 0; i < s; i++){
		CAgent::agents[i]->Sense(type);
	}

	//Control:
	for (i = 0; i < s; i++){
		CAgent::agents[i]->Control();
	}

	//Act:
	for (i = 0; i < s; i++){
		CAgent::agents[i]->Act(deltaT);
	}
}

void CBehaviorSimulation::Display()
{
	if (type == AVOID)
		env.Display();	
	for(unsigned int i = 0; i < CAgent::agents.size(); i++){
		CAgent::agents[i]->Display();
	}
//        qDebug() << CAgent::agents.size();
}

void CBehaviorSimulation::SetV0()
{
	for (unsigned int i = 0; i < CAgent::agents.size(); i++){
		CAgent::agents[i]->SetV0();
	}
}
