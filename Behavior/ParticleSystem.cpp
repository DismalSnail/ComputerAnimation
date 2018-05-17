// ParticleSystem.cpp: implementation of the CParticleSystem class.
//
//////////////////////////////////////////////////////////////////////

#include "ParticleSystem.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CParticleSystem::CParticleSystem(int dim)
{
	this->dim = dim;
	deriv = new float[dim];
	state = new float[dim];	
	dead = false;
}

CParticleSystem::~CParticleSystem()
{
	delete[] deriv;
	delete[] state;
}

void CParticleSystem::SetState(float *value)
{
	memcpy(state, value, sizeof(float) * dim);
}

float* CParticleSystem::GetState()
{
	return state;
}
