// Agent.h: interface for the CAgent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AGENT_H)
#define AGENT_H

#include <qgl.h>
#include "Transformation.h"
#include "AgentDisplay.h"
#include "Environment.h"
#include <vector>

using namespace std;

/*
 *	State Vector: 4 dimensions
 *  0 : position in local coordinates. Useless.
 *  1 : orientation angle in global coordinates.
 *  2 : velocity in local coordinates.
 *  3 : angular velocity in global coordinates.
 */

/*
 *	Input Vector: 2 dimensions
 *  0 : force
 *  1 : torque
 */

#ifndef BEHAVIORTYPE
#define BEHAVIORTYPE
enum BehavoirType{SEEK, FLEE, ARRIVAL, DEPARTURE, WANDER, AVOID, SEPARATION, ALIGNMENT, COHESION, FLOCKING, LEADER, FLOCKINGPLUS};
#endif

class CAgent  
{
public:
    //Member functions:
    CAgent();
    virtual ~CAgent();
    //Constructor
    CAgent(float* color, CEnvironment* env);
    //Initiate the states
    void SetInitState(float pos[2], float angle);
    //Display the agent
    void Display();
    //Sense the environment according to different behaviors
    void Sense(int type);
    //Agent control
    void Control();
    //Agent act: performing EulerStep for this particle
    void FindDeriv();
    void UpdateState();
    void Act(float deltaT);

    //Initiate values for agent properties and other settings
    static void InitValues();
    void SetVTheta(vec2& V);
    void SetV0();
    vec2 LocalToWorld(vec2& l);
    vec2 WorldToLocal(vec2& w);

    //Behaviors
    vec2 Leader();
    vec2 Flocking();
    vec2 Cohesion();
    vec2 Alignment();
    vec2 Separation();
    vec2 Avoid();
    vec2 Wander();
    vec2 Departure();
    vec2 Arrival();
    vec2 Flee();
    vec2 Seek();
    vec2 FlockingPlus();

    //Member variables:
    //Current frame number of the animation
    int frameNum;
    //Agent color
    float color[3];
    //Simulation time step
    float deltaT;
    //Environment information
    CEnvironment* env;
    //Show leader indicator
    bool showLeader;

    //State vector dimension: 4
    /*
  *	State Vector: 4 dimensions
  *  0 : position in local coordinates. Useless.
  *  1 : orientation angle in global coordinates.
  *  2 : velocity in local coordinates.
  *  3 : angular velocity in global coordinates.
  */
    int dimState;
    //Input vector dimension: 2
    /*
  *	Input Vector: 2 dimensions
  *  0 : force
  *  1 : torque
  */
    int dimInput;

    //State vector
    float state[4];
    //Input vector
    float input[2];
    //Derivative vector
    float deriv[4];

    //Control inputs:
    //Desired velocity
    float vd;
    //Desired orientation
    float thetad;

    //Agent global position
    vec2 GPos;
    //Goal position
    vec2 goal;

    //Needed in Wander behavior
    //Wander velocity
    vec2 vWander;
    //Nominal velocity
    vec2 v0;

    //Static function and variables:
    //Clear the agent list
    static void ClearAgents();
    //Agent list
    static vector<CAgent*> agents;
    //Radius of the bounding sphere of every agent
    static float radius;
    //Debug mode indicator
    static bool debug;
    //Mass of every agent
    static float Mass;
    //Moment of inertia of every agent
    static float Inertia;
    //Maximum velocity
    static float MaxVelocity;
    //Maximum force
    static float MaxForce;
    //Maximum torque
    static float MaxTorque;
    //Maximum angular velocity
    static float MaxAngVel;
    //Velocity control: f = m * Kv0 * (vd - v)
    static float Kv0;
    //Heading control: tau = I * ( -Kv1 * thetaDot - Kp1 * theta + Kp1 * thetad)
    static float Kp1;
    static float Kv1;
    //Behavior settings. See comments in cpp file for details
    static float KArrival;
    static float KDeparture;
    static float KNoise;
    static float KWander;
    static float KAvoid;
    static float TAvoid;
    static float RNeighborhood;
    static float KSeparate;
    static float KAlign;
    static float KCohesion;
};

inline void Truncate(float& value, float minV, float maxV){
    if (value < minV)
        value = minV;
    else
        if (value > maxV)
            value = maxV;
}
#endif // !defined(AGENT_H)





















