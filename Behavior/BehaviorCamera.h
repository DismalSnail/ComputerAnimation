// BehaviorCamera.h: interface for the BehaviorCamera class.
// Author: Liming Zhao
// University of Pennsylvania
//////////////////////////////////////////////////////////////////////

#pragma once


#include <qgl.h>
#include <GL/Glu.h>
#include <math.h>
#include "Transformation.h"

class BehaviorCamera
{
public:
	BehaviorCamera(void);
	~BehaviorCamera(void);

	const vec3& GetEye(void) const;
	const vec3& GetCenter(void) const;
	const vec3& GetFrontVector(void) const;
	const vec3& GetRightVector(void) const;
	const vec3& GetUpVector(void) const;
	void SetBehaviorCamera(const vec3& eye, const vec3& center);
	void Zoom(float dx);
	void RotateCenter(float dx, float dy);
	void MoveSWD(float dx, float dy);
	void LookAt();
	void Reset();
	void DrawFloor() const;
	void Perspective(void);

	void UpdateAll(void);
	float m_fovy, m_nearP, m_farP;
	vec3 m_eye, m_center;		
	vec3 m_upVec, m_frontVec, m_rightVec;
	float m_dist;
};
