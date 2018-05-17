#include "AgentDisplay.h"

AgentJoint::AgentJoint(const unsigned int& id, const vec3& offset)
{
        m_id = id;
        m_offset = offset;
}

void AgentJoint::AttachAgentJoints(AgentJoint* pParent, AgentJoint* pChild)
{
        // Set the new parent
        pChild->m_pParent = pParent;
        // Add child to new parent's children list
        pParent->m_pChildren.push_back(pChild);
}

enum{eHips, eRightUpLeg, eRightLeg, eRightFoot, eRightToes,
                        eSpine, eChest, eNeck, eHead,
                                                        eLeftShoulder, eLeftArm, eLeftForeArm, eLeftHand,
                                                        eRightShoulder, eRightArm, eRightForeArm, eRightHand,
                        eLeftUpLeg, eLeftLeg, eLeftFoot, eLeftToes};

GLuint AgentDisplay::listNames = 0;

void AgentDisplay::CreateSkeleton(vector<AgentJoint*>& pAgentJointList)
{
        // Assume pAgentJointList is empty
        AgentJoint* pAgentJoint;
        // Hips
        pAgentJoint = new AgentJoint(eHips, vec3(-29.0441f, 98.1845f, -101.233f));
        pAgentJoint->m_pParent = NULL;
        pAgentJointList.push_back(pAgentJoint);
        // RightUpLeg
        pAgentJoint = new AgentJoint(eRightUpLeg, vec3(-8.9458f, -8.66707f, 0.101652f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eHips], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // RightLeg
        pAgentJoint = new AgentJoint(eRightLeg, vec3(0.0f, -44.4227f, 1.3727f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eRightUpLeg], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // RightFoot
        pAgentJoint = new AgentJoint(eRightFoot, vec3(0.253549f, -42.0924f, -1.46059f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eRightLeg], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // RightToes
        pAgentJoint = new AgentJoint(eRightToes, vec3(0.04f, -4.41509f, 8.4991f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eRightFoot], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // Spine
        pAgentJoint = new AgentJoint(eSpine, vec3(0.0f, 11.8905f, 0.0f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eHips], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // Chest
        pAgentJoint = new AgentJoint(eChest, vec3(0.0f, 25.6574f, 0.127663f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eSpine], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // Neck
        pAgentJoint = new AgentJoint(eNeck, vec3(0.0f, 8.73416f, 0.011341f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eChest], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // Head
        pAgentJoint = new AgentJoint(eHead, vec3(-0.29f, 12.7742f, 2.51395f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eNeck], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // LeftShoulder
        pAgentJoint = new AgentJoint(eLeftShoulder, vec3(8.99f, -0.362252f, -0.22f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eChest], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // LeftArm
        pAgentJoint = new AgentJoint(eLeftArm, vec3(10.2827f, -0.00338f, 0.322123f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eLeftShoulder], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // LeftForeArm
        pAgentJoint = new AgentJoint(eLeftForeArm, vec3(32.7669f, 0.099144f, -1.42434f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eLeftArm], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // LeftHand
        pAgentJoint = new AgentJoint(eLeftHand, vec3(27.5643f, 0.0853619f, 1.02217f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eLeftForeArm], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // RightShoulder
        pAgentJoint = new AgentJoint(eRightShoulder, vec3(-8.99f, -0.362252f, -0.22f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eChest], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // RightArm
        pAgentJoint = new AgentJoint(eRightArm, vec3(-10.2827f, -0.00338f, 0.322123f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eRightShoulder], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // RightForeArm
        pAgentJoint = new AgentJoint(eRightForeArm, vec3(-32.8971f, 0.099144f, -1.42434f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eRightArm], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // RightHand
        pAgentJoint = new AgentJoint(eRightHand, vec3(-27.4921f, 0.0853621f, 1.02217f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eRightForeArm], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // LeftUpLeg
        pAgentJoint = new AgentJoint(eLeftUpLeg, vec3(8.9458f, -8.66707f, 0.101652f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eHips], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // LeftLeg
        pAgentJoint = new AgentJoint(eLeftLeg, vec3(0.0f, -44.4227f, 1.3727f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eLeftUpLeg], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // LeftFoot
        pAgentJoint = new AgentJoint(eLeftFoot, vec3(-0.253549f, -42.0924f, -1.46059f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eLeftLeg], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
        // LeftToes
        pAgentJoint = new AgentJoint(eLeftToes, vec3(-0.04f, -4.41509f, 8.4991f));
        AgentJoint::AttachAgentJoints(pAgentJointList[eLeftFoot], pAgentJoint);
        pAgentJointList.push_back(pAgentJoint);
}

void AgentDisplay::DrawBodyParts(AgentJoint* pAgentJoint, float* pAgentJointAngles)
{

        glPushMatrix();
        // Draw limb
        vec3 v = pAgentJoint->m_offset;
        float l = v.Length();
        v /= l;
        float dx = v[VY] * v[VY] + v[VZ] * v[VZ];
        float dy = v[VX] * v[VX] + v[VZ] * v[VZ];
        float dz = v[VX] * v[VX] + v[VY] * v[VY];
        unsigned int eAxis;
        vec3 axis;
        float angle;
        if (dx >= dy && dx >= dz)
        {
                eAxis = VX;
                axis = axisX.Cross(v);
                angle = acos(v * axisX) * Rad2Deg;
        }
        else if (dy >= dx && dy >= dz)
        {
                eAxis = VY;
                axis = axisY.Cross(v);
                angle = acos(v * axisY) * Rad2Deg;
        }
        else
        {
                eAxis = VZ;
                axis = axisZ.Cross(v);
                angle = acos(v * axisZ) * Rad2Deg;
        }
        glPushMatrix();
        glTranslatef(pAgentJoint->m_offset[VX]/2.0f, pAgentJoint->m_offset[VY]/2.0f, pAgentJoint->m_offset[VZ]/2.0f);
        glRotatef(angle, axis[0], axis[1], axis[2]);
        switch(eAxis)
        {
        case VX:
                glScalef(l / 2.0f, 6.0f, 6.0f);
                break;
        case VY:
                glScalef(6.0f, l / 2.0f, 6.0f);
                break;
        case VZ:
                glScalef(6.0f, 6.0f, l / 2.0f);
                break;
        }
        glutSolidSphere (1.0, 12, 12);
        glScalef(1.0f, 1.0f, 1.0f);
        glPopMatrix();
        // Draw AgentJoint
        glTranslatef(pAgentJoint->m_offset[VX], pAgentJoint->m_offset[VY], pAgentJoint->m_offset[VZ]);
        glRotatef(pAgentJointAngles[pAgentJoint->m_id * 3], 0.0f, 0.0f, 1.0f);
        glRotatef(pAgentJointAngles[pAgentJoint->m_id * 3 + 1], 1.0f, 0.0f, 0.0f);
        glRotatef(pAgentJointAngles[pAgentJoint->m_id * 3 + 2], 0.0f, 1.0f, 0.0f);
        glutSolidSphere(6.0, 12, 12);
        if (pAgentJoint->m_pChildren.size() > 0)
        {
                // Iterator all children AgentJoints
                for (vector<AgentJoint*>::const_iterator iter = pAgentJoint->m_pChildren.begin(); iter != pAgentJoint->m_pChildren.end(); iter++)
                        DrawBodyParts(*iter, pAgentJointAngles);
        }
        glPopMatrix();
}



void AgentDisplay::DrawSkeleton(AgentJoint* pRootAgentJoint, float* pAgentJointAngles)
{
        glPushMatrix();
        // Draw root AgentJoint
        glRotatef(pAgentJointAngles[pRootAgentJoint->m_id * 3], 0.0f, 0.0f, 1.0f);
        glRotatef(pAgentJointAngles[pRootAgentJoint->m_id * 3 + 1], 1.0f, 0.0f, 0.0f);
        glRotatef(pAgentJointAngles[pRootAgentJoint->m_id * 3 + 2], 0.0f, 1.0f, 0.0f);
        // Iterator all children AgentJoints
        for (vector<AgentJoint*>::const_iterator iter = pRootAgentJoint->m_pChildren.begin(); iter != pRootAgentJoint->m_pChildren.end(); iter++)
                DrawBodyParts(*iter, pAgentJointAngles);
        glPopMatrix();
}

void AgentDisplay::CreateDrawList()
{
        vector<AgentJoint*> m_AgentJointList;
        CreateSkeleton(m_AgentJointList);
        float AgentJointAngles[] = {-0.78f, -5.06f, -17.38f, -10.38f, -27.08f, -7.74f, -0.12f, 57.31f, 7.02f, -1.00f, -6.80f, -0.16f, 0.05f, 0.00f, 0.66f, -1.20f, 1.84f, -2.73f, 0.54f, 3.65f, -5.50f, 5.27f, -3.51f, 12.52f, -1.91f, 15.91f, 13.29f, -14.30f, 0.73f, -7.89f, -34.63f, -20.13f, 8.41f, 9.55f, 35.32f, -38.09f, 1.43f, 9.83f, -6.44f, 27.71f, 2.21f, 15.79f, 33.80f, -15.56f, -16.28f, -9.81f, 47.20f, 25.31f, -5.16f, 9.37f, 9.42f, 1.29f, -12.12f, 9.92f, 0.89f, 39.35f, 11.00f, -4.38f, -21.65f, -0.43f, 0.18f, -0.19f, 0.00,
                -0.56f, -5.07f, -19.22f, -8.85f, -29.10f, -7.71f, -0.01f, 48.39f, 8.69f, -0.49f, -7.00f, -0.16f, 0.05f, 0.00f, 0.66f, -0.18f, 1.77f, -3.03f, 1.44f, 3.49f, -5.88f, 3.72f, -2.68f, 13.58f, -2.56f, 15.45f, 14.13f, -14.72f, 1.18f, -7.33f, -32.87f, -19.95f, 7.32f, 9.34f, 34.37f, -39.86f, 3.02f, 9.68f, -6.63f, 26.46f, 1.92f, 15.05f, 32.47f, -19.13f, -17.08f, -9.00f, 48.85f, 23.67f, -4.17f, 9.52f, 8.37f, -0.41f, -9.97f, 9.03f, 1.00f, 38.83f, 13.75f, -5.37f, -23.39f, -0.63f, -0.00f, 0.00f, -0.00,
                -0.25f, -4.59f, -21.06f, -6.65f, -31.30f, -6.93f, -0.03f, 39.32f, 8.42f, 0.69f, -6.81f, -0.17f, 0.05f, 0.00f, 0.66f, 0.74f, 1.50f, -3.18f, 2.08f, 2.96f, -6.03f, 2.96f, -1.63f, 14.35f, -3.75f, 14.86f, 15.12f, -14.31f, 1.54f, -6.76f, -31.92f, -20.67f, 6.87f, 8.75f, 33.15f, -41.43f, 3.25f, 9.68f, -5.72f, 25.67f, 1.92f, 14.54f, 31.07f, -22.06f, -18.10f, -8.15f, 49.82f, 22.08f, -3.20f, 9.67f, 6.40f, -2.19f, -8.30f, 7.90f, 1.13f, 38.47f, 16.81f, -6.58f, -25.27f, -0.91f, 0.00f, -0.00f, 0.00,
                0.36f, -3.96f, -21.99f, -4.66f, -34.85f, -5.91f, -0.15f, 33.79f, 5.68f, 1.36f, -8.46f, -0.17f, 0.05f, 0.00f, 0.66f, 1.39f, 1.20f, -3.44f, 2.67f, 2.33f, -6.48f, 1.77f, -1.65f, 15.01f, -4.06f, 15.00f, 15.55f, -14.11f, 1.77f, -5.80f, -31.31f, -21.67f, 6.59f, 7.58f, 31.40f, -43.25f, 1.97f, 9.80f, -4.18f, 24.23f, 1.89f, 13.99f, 30.37f, -23.96f, -19.05f, -7.14f, 50.31f, 20.55f, -2.11f, 9.79f, 4.77f, -4.19f, -7.02f, 6.31f, 1.23f, 38.51f, 19.43f, -7.74f, -27.38f, -1.24f, 0.00f, -0.00f, 0.00,
                0.95f, -3.29f, -22.21f, -2.95f, -38.99f, -4.92f, -0.32f, 31.38f, 1.42f, 3.18f, -12.64f, -0.06f, 0.05f, 0.00f, 0.66f, 1.71f, 0.84f, -3.76f, 3.19f, 1.60f, -7.03f, 1.78f, -1.53f, 15.45f, -5.58f, 15.07f, 16.39f, -13.71f, 1.96f, -5.19f, -31.23f, -21.50f, 6.42f, 7.46f, 30.89f, -44.72f, 1.59f, 9.84f, -3.15f, 23.66f, 1.88f, 13.44f, 28.98f, -25.57f, -20.20f, -6.17f, 51.43f, 18.83f, -0.84f, 9.89f, 3.58f, -6.02f, -5.26f, 4.79f, 1.29f, 37.69f, 21.33f, -8.51f, -29.15f, -1.51f, 0.00f, -0.00f, 0.01,
                1.51f, -2.85f, -21.75f, -1.68f, -42.25f, -4.37f, -0.52f, 30.54f, -3.50f, 7.30f, -19.57f, 0.53f, 0.05f, 0.00f, 0.66f, 1.98f, 0.66f, -4.13f, 3.88f, 1.21f, -7.70f, 1.31f, -1.72f, 15.88f, -6.37f, 14.51f, 16.71f, -13.66f, 2.15f, -4.99f, -31.70f, -21.68f, 6.09f, 7.43f, 30.69f, -45.40f, 1.08f, 9.87f, -3.85f, 22.99f, 1.70f, 12.79f, 27.83f, -27.16f, -20.80f, -5.29f, 52.96f, 16.78f, -0.51f, 9.91f, 3.29f, -7.41f, -2.94f, 3.85f, 1.30f, 36.37f, 22.26f, -8.99f, -30.75f, -1.73f, -0.00f, -0.00f, -0.00,
                2.23f, -2.21f, -20.74f, -1.04f, -44.31f, -3.80f, -0.64f, 30.24f, -6.42f, 11.67f, -23.83f, 1.43f, 0.05f, 0.00f, 0.66f, 2.29f, 0.53f, -4.50f, 4.59f, 0.92f, -8.40f, 0.83f, -3.08f, 16.23f, -6.88f, 14.95f, 16.95f, -13.81f, 2.30f, -4.56f, -32.21f, -20.75f, 5.38f, 7.20f, 30.12f, -46.91f, 0.75f, 9.89f, -3.52f, 21.93f, 1.46f, 12.26f, 27.42f, -27.78f, -21.09f, -4.35f, 53.72f, 15.10f, 0.31f, 9.97f, 3.09f, -8.46f, -1.15f, 3.57f, 1.27f, 35.55f, 21.77f, -9.01f, -32.66f, -1.89f, -0.00f, -0.00f, -0.00,
                2.72f, -2.18f, -19.08f, -1.12f, -44.76f, -3.57f, -0.62f, 30.27f, -5.86f, 6.92f, -20.60f, 0.55f, 0.05f, 0.00f, 0.66f, 2.51f, 0.55f, -4.90f, 5.19f, 0.93f, -9.14f, 0.34f, -3.86f, 16.18f, -7.24f, 14.77f, 16.84f, -14.27f, 2.51f, -4.29f, -32.57f, -19.74f, 5.19f, 7.79f, 29.99f, -49.58f, 1.07f, 9.87f, -2.98f, 20.87f, 1.25f, 11.67f, 27.40f, -28.04f, -21.30f, -3.23f, 53.92f, 13.26f, 0.42f, 9.97f, 2.92f, -9.10f, 1.35f, 3.82f, 1.19f, 35.13f, 19.83f, -8.56f, -35.04f, -1.97f, -0.00f, -0.00f, 0.01,
                3.10f, -2.51f, -16.63f, -2.13f, -43.54f, -3.79f, -0.48f, 30.90f, -2.43f, 1.91f, -17.93f, -0.07f, 0.05f, 0.00f, 0.66f, 2.64f, 0.67f, -5.42f, 5.75f, 1.11f, -10.14f, -0.38f, -4.53f, 16.00f, -7.40f, 14.66f, 16.44f, -14.70f, 2.71f, -4.12f, -33.26f, -18.25f, 5.00f, 8.31f, 29.85f, -51.92f, 1.21f, 9.87f, -2.49f, 19.85f, 1.06f, 11.23f, 27.85f, -28.24f, -21.19f, -1.90f, 53.90f, 10.76f, -0.10f, 9.94f, 2.90f, -8.95f, 4.98f, 4.75f, 1.05f, 33.81f, 16.63f, -7.90f, -37.15f, -1.96f, 0.07f, 0.00f, 0.03,
                3.71f, -2.62f, -13.46f, -3.56f, -41.10f, -4.40f, -0.35f, 32.09f, 0.77f, -0.83f, -19.79f, -0.34f, 0.05f, 0.00f, 0.66f, 2.63f, 0.57f, -5.90f, 6.12f, 0.88f, -11.11f, -0.64f, -5.26f, 15.81f, -7.98f, 15.40f, 16.13f, -15.00f, 2.90f, -3.82f, -34.82f, -16.23f, 4.26f, 8.55f, 29.84f, -52.68f, 1.39f, 9.85f, -3.02f, 19.52f, 0.79f, 10.37f, 28.26f, -28.47f, -20.36f, 0.07f, 54.39f, 6.75f, 0.07f, 9.95f, 3.42f, -7.97f, 9.07f, 6.34f, 0.81f, 31.73f, 10.87f, -6.11f, -37.02f, -1.45f, -0.99f, -2.10f, 0.12,
                3.63f, -2.83f, -10.19f, -4.10f, -39.92f, -4.80f, -0.33f, 33.93f, 1.55f, -3.01f, -12.38f, -0.33f, 0.05f, 0.00f, 0.66f, 3.28f, 0.25f, -6.42f, 7.21f, 0.16f, -12.04f, -1.95f, -5.01f, 16.28f, -8.37f, 16.31f, 15.70f, -16.69f, 3.18f, -3.37f, -36.58f, -13.61f, 3.29f, 9.20f, 30.76f, -50.97f, 1.75f, 9.82f, -4.76f, 19.05f, 0.65f, 10.31f, 28.60f, -28.66f, -18.98f, 3.80f, 55.42f, -0.79f, 0.45f, 9.99f, 4.13f, -5.61f, 10.85f, 7.53f, 0.60f, 33.71f, 5.47f, -3.71f, -30.76f, -0.61f, -2.92f, -11.24f, -0.36,
                2.85f, -3.51f, -8.14f, -3.79f, -38.67f, -4.07f, -0.31f, 36.55f, 2.13f, -2.00f, -4.45f, -0.09f, -1.64f, -4.27f, 0.99f, 3.75f, -0.13f, -6.63f, 8.08f, -0.63f, -12.28f, -2.98f, -4.10f, 16.57f, -7.86f, 17.14f, 14.94f, -17.88f, 3.22f, -2.54f, -38.65f, -10.95f, 3.86f, 9.64f, 31.67f, -48.93f, 2.58f, 9.74f, -5.69f, 19.10f, 0.54f, 9.29f, 28.38f, -28.20f, -19.03f, 3.79f, 57.71f, -0.97f, 1.36f, 10.04f, 3.41f, -2.56f, 12.98f, 8.68f, 0.39f, 36.54f, 0.19f, -4.15f, -26.92f, -0.58f, 0.97f, -11.89f, 0.13,
                1.74f, -5.09f, -7.33f, -2.92f, -36.26f, -3.58f, -0.30f, 39.75f, 2.67f, -1.72f, -0.64f, -0.02f, 0.36f, -5.61f, 0.47f, 4.15f, 0.15f, -6.36f, 8.67f, -0.06f, -11.58f, -3.62f, -4.39f, 16.38f, -7.13f, 17.95f, 14.13f, -18.75f, 2.97f, -2.42f, -40.68f, -9.66f, 5.59f, 8.93f, 31.80f, -46.33f, 3.15f, 9.67f, -6.40f, 19.76f, 0.72f, 9.30f, 28.09f, -28.33f, -18.69f, 3.72f, 58.87f, -0.94f, 2.19f, 10.08f, 2.88f, 0.86f, 14.40f, 10.22f, 0.19f, 41.64f, -4.50f, -4.64f, -20.70f, -0.43f, 1.53f, -13.12f, -0.07,
                0.52f, -6.29f, -5.81f, -1.96f, -33.30f, -3.70f, -0.31f, 42.51f, 2.70f, -1.66f, -2.97f, -0.07f, 0.90f, -3.79f, 0.64f, 4.60f, 0.40f, -6.13f, 8.99f, 0.48f, -10.92f, -4.09f, -4.05f, 15.65f, -6.40f, 17.55f, 13.18f, -19.17f, 2.33f, -2.25f, -43.18f, -8.62f, 6.76f, 9.08f, 33.04f, -42.81f, 2.76f, 9.70f, -7.03f, 20.65f, 0.88f, 9.81f, 28.03f, -28.42f, -18.80f, 1.53f, 58.51f, 2.38f, 1.91f, 10.08f, 3.64f, 5.52f, 12.90f, 11.42f, 0.00f, 49.76f, -8.13f, -2.46f, -12.76f, -0.05f, 0.21f, -9.81f, -0.00,
                -0.61f, -7.02f, -3.66f, -0.86f, -30.13f, -3.81f, -0.38f, 43.97f, 1.31f, -1.33f, -6.77f, -0.16f, 0.81f, -2.94f, 0.65f, 4.97f, 0.55f, -5.80f, 8.84f, 0.86f, -10.04f, -3.17f, -3.74f, 13.74f, -6.68f, 17.47f, 12.15f, -19.02f, 1.49f, -2.58f, -45.62f, -7.45f, 7.63f, 10.56f, 35.89f, -39.55f, 1.90f, 9.78f, -6.74f, 21.60f, 0.82f, 10.26f, 28.14f, -28.44f, -19.58f, -2.44f, 56.91f, 8.93f, 0.22f, 9.98f, 5.67f, 9.99f, 8.68f, 11.10f, -0.08f, 58.86f, -9.06f, 0.20f, -3.95f, 0.00f, -1.11f, -1.88f, 0.05,
                -1.56f, -7.38f, -1.95f, 0.34f, -26.87f, -3.73f, -0.46f, 43.88f, -0.16f, -0.92f, -9.59f, -0.20f, 0.72f, -2.82f, 0.65f, 5.03f, 0.61f, -5.07f, 7.99f, 1.09f, -8.50f, -1.90f, -3.54f, 11.42f, -6.31f, 18.13f, 10.83f, -18.80f, 0.63f, -3.14f, -46.92f, -6.88f, 8.91f, 11.32f, 38.39f, -36.34f, 0.86f, 9.88f, -6.72f, 23.13f, 0.86f, 10.74f, 28.50f, -28.54f, -19.69f, -4.81f, 53.46f, 13.73f, -1.14f, 9.86f, 6.73f, 12.95f, 2.86f, 10.23f, 0.07f, 66.61f, -7.08f, 0.51f, 7.66f, -0.13f, -0.19f, 0.01f, 0.01,
                -1.76f, -7.62f, -1.11f, 0.74f, -23.78f, -4.06f, -0.47f, 43.31f, -0.49f, -0.95f, -11.90f, -0.24f, 1.08f, -2.62f, 0.66f, 4.80f, 0.77f, -4.00f, 6.68f, 1.49f, -6.41f, -1.14f, -3.33f, 9.08f, -5.79f, 18.37f, 9.41f, -19.26f, -0.18f, -3.48f, -47.07f, -7.50f, 10.25f, 11.42f, 40.46f, -33.03f, -0.33f, 10.00f, -6.83f, 23.77f, 1.03f, 11.67f, 29.90f, -28.46f, -18.69f, -6.10f, 49.73f, 17.01f, -2.77f, 9.68f, 7.96f, 14.12f, -3.00f, 9.88f, 0.36f, 72.35f, -4.97f, -1.48f, 12.96f, 0.17f, 0.02f, 0.01f, -0.00,
                -1.83f, -7.72f, -0.66f, 0.96f, -21.15f, -4.50f, -0.47f, 42.94f, -0.50f, -1.07f, -14.09f, -0.28f, 1.29f, -2.54f, 0.67f, 4.23f, 0.90f, -2.64f, 4.72f, 1.84f, -3.76f, 0.32f, -2.77f, 6.33f, -5.41f, 18.02f, 7.95f, -18.38f, -0.72f, -4.24f, -47.19f, -8.89f, 11.96f, 11.54f, 42.27f, -30.66f, -1.71f, 10.11f, -5.66f, 25.68f, 1.49f, 12.41f, 30.34f, -27.59f, -17.36f, -6.77f, 45.55f, 19.74f, -3.65f, 9.57f, 8.73f, 14.73f, -8.42f, 10.13f, 0.19f, 75.99f, -6.61f, -1.24f, 8.96f, 0.11f, 0.00f, -0.00f, -0.00,
                -1.88f, -8.17f, -0.64f, 1.16f, -18.77f, -4.81f, -0.45f, 43.51f, -0.04f, -1.37f, -16.60f, -0.34f, 1.12f, -1.96f, 0.67f, 3.54f, 1.32f, -1.23f, 2.85f, 2.69f, -1.08f, 1.47f, -2.68f, 3.85f, -4.76f, 17.50f, 6.61f, -17.64f, -1.14f, -4.76f, -46.54f, -10.69f, 13.41f, 11.55f, 43.97f, -29.02f, -3.39f, 10.20f, -4.31f, 27.54f, 2.41f, 13.72f, 29.69f, -26.71f, -15.80f, -6.98f, 41.58f, 22.27f, -4.31f, 9.48f, 9.28f, 15.27f, -13.09f, 11.06f, -0.37f, 77.37f, -9.66f, 0.67f, 2.36f, -0.09f, 0.00f, -0.00f, -0.00,
                -2.13f, -8.41f, -0.98f, 1.79f, -17.25f, -4.43f, -0.44f, 44.98f, 0.49f, -1.76f, -19.32f, -0.43f, 0.21f, -0.94f, 0.66f, 2.66f, 1.83f, 0.22f, 1.00f, 3.70f, 1.53f, 3.29f, -3.52f, 1.56f, -4.40f, 17.12f, 5.64f, -16.10f, -1.53f, -5.15f, -45.99f, -12.00f, 14.55f, 11.74f, 45.73f, -28.21f, -4.45f, 10.24f, -3.35f, 29.75f, 3.64f, 15.28f, 27.79f, -25.75f, -13.96f, -7.56f, 39.49f, 25.19f, -5.50f, 9.32f, 9.68f, 16.28f, -17.70f, 12.58f, -0.79f, 76.69f, -12.14f, 0.84f, -3.31f, -0.03f, 0.00f, -0.00f, -0.00,
                -2.47f, -8.65f, -1.46f, 2.80f, -16.06f, -3.46f, -0.45f, 46.95f, 0.55f, -2.11f, -22.24f, -0.55f, 0.05f, 0.00f, 0.66f, 1.80f, 2.29f, 1.52f, -0.40f, 4.56f, 3.78f, 4.28f, -4.94f, -0.22f, -3.79f, 17.30f, 4.65f, -15.34f, -1.76f, -5.54f, -45.01f, -12.17f, 15.66f, 11.98f, 47.32f, -27.86f, -5.49f, 10.26f, -2.48f, 30.44f, 4.56f, 16.34f, 26.25f, -24.77f, -11.61f, -7.88f, 38.17f, 27.60f, -6.19f, 9.21f, 10.27f, 17.74f, -21.85f, 14.61f, -0.82f, 73.94f, -13.39f, -0.03f, -7.59f, 0.03f, 0.00f, -0.00f, 0.00,
                -2.64f, -8.78f, -1.03f, 3.16f, -14.55f, -3.44f, -0.46f, 48.33f, 0.63f, -2.25f, -25.01f, -0.64f, 0.05f, 0.00f, 0.66f, 0.90f, 2.70f, 2.24f, -1.42f, 5.36f, 4.83f, 4.41f, -6.06f, -1.37f, -2.83f, 16.92f, 3.82f, -15.41f, -2.04f, -5.01f, -43.94f, -12.51f, 16.20f, 12.24f, 49.18f, -27.58f, -5.93f, 10.25f, -1.79f, 30.22f, 5.50f, 17.56f, 24.49f, -24.83f, -9.08f, -8.48f, 37.91f, 29.71f, -6.84f, 9.14f, 10.08f, 18.52f, -25.42f, 16.19f, -0.63f, 68.21f, -13.93f, 0.08f, -10.09f, 0.05f, 0.00f, -0.00f, 0.00,
                -2.65f, -7.99f, -0.50f, 3.32f, -13.08f, -3.69f, -0.45f, 47.84f, 0.62f, -2.33f, -26.81f, -0.71f, 0.05f, 0.00f, 0.66f, -0.11f, 2.56f, 2.98f, -2.25f, 5.05f, 5.90f, 4.52f, -6.42f, -2.80f, -2.17f, 16.63f, 2.84f, -15.35f, -2.16f, -4.49f, -43.08f, -13.92f, 16.74f, 12.49f, 51.56f, -27.25f, -6.44f, 10.22f, -1.02f, 30.03f, 6.06f, 17.78f, 23.00f, -25.59f, -7.07f, -8.94f, 37.97f, 30.87f, -7.71f, 9.05f, 9.68f, 18.48f, -28.27f, 17.44f, -0.40f, 58.79f, -13.52f, -0.69f, -11.13f, 0.03f, 0.00f, -0.00f, 0.00,
                -2.45f, -6.95f, -0.28f, 3.24f, -11.00f, -3.84f, -0.44f, 45.82f, 0.53f, -2.27f, -27.93f, -0.73f, 0.05f, 0.00f, 0.65f, -1.18f, 2.09f, 3.62f, -2.94f, 4.10f, 6.88f, 4.66f, -6.26f, -3.88f, -1.80f, 17.03f, 2.13f, -14.58f, -2.27f, -3.70f, -42.88f, -16.68f, 17.53f, 11.94f, 53.73f, -26.17f, -7.75f, 10.15f, 0.78f, 29.84f, 6.38f, 17.62f, 21.99f, -26.67f, -5.81f, -9.41f, 38.17f, 31.80f, -8.81f, 8.96f, 9.15f, 17.38f, -29.81f, 17.55f, -0.16f, 46.75f, -11.27f, -1.20f, -10.39f, 0.02f, -0.00f, -0.00f, 0.00,
                -2.26f, -5.72f, -0.15f, 2.95f, -8.85f, -4.16f, -0.40f, 43.80f, 1.00f, -2.33f, -29.27f, -0.78f, 0.05f, 0.00f, 0.65f, -1.85f, 1.50f, 3.89f, -3.10f, 2.92f, 7.28f, 4.08f, -5.97f, -4.04f, -1.27f, 17.49f, 1.52f, -13.74f, -2.16f, -2.97f, -43.23f, -19.26f, 18.85f, 10.25f, 54.47f, -24.21f, -8.96f, 10.14f, 1.41f, 29.02f, 6.42f, 17.23f, 21.53f, -27.07f, -4.75f, -8.97f, 36.88f, 33.02f, -8.74f, 9.06f, 7.79f, 16.19f, -32.11f, 15.99f, 0.03f, 36.60f, -7.92f, -1.50f, -9.02f, 0.02f, -0.00f, -0.00f, 0.00,
                -2.41f, -4.53f, 0.02f, 2.96f, -6.46f, -4.70f, -0.37f, 41.50f, 1.28f, -2.22f, -30.55f, -0.80f, 0.05f, 0.00f, 0.65f, -2.12f, 1.05f, 3.97f, -3.41f, 2.03f, 7.32f, 4.72f, -5.89f, -4.09f, -1.52f, 16.99f, 1.31f, -12.14f, -2.12f, -2.68f, -44.45f, -19.88f, 20.04f, 8.77f, 53.99f, -22.84f, -10.35f, 10.17f, 1.39f, 28.79f, 6.36f, 16.90f, 21.07f, -26.69f, -3.71f, -8.85f, 35.86f, 34.84f, -8.17f, 9.21f, 6.43f, 16.48f, -36.39f, 14.80f, 0.16f, 32.47f, -4.99f, -2.35f, -9.57f, 0.00f, -0.00f, -0.00f, 0.00,
                -2.72f, -3.60f, -0.05f, 2.97f, -4.08f, -5.25f, -0.33f, 39.64f, 1.85f, -2.10f, -31.97f, -0.81f, 0.05f, 0.00f, 0.64f, -2.12f, 0.88f, 4.00f, -3.59f, 1.68f, 7.26f, 4.38f, -6.80f, -3.68f, -1.03f, 16.58f, 0.96f, -11.25f, -2.07f, -2.55f, -45.77f, -18.49f, 20.58f, 7.82f, 52.72f, -22.34f, -10.83f, 10.29f, 0.33f, 28.28f, 6.36f, 16.91f, 20.57f, -25.68f, -2.82f, -9.07f, 35.05f, 37.36f, -8.06f, 9.29f, 5.34f, 17.20f, -40.33f, 15.26f, 0.32f, 31.30f, -0.97f, -4.08f, -17.04f, -0.25f, -0.00f, -0.00f, 0.00,
                -3.06f, -3.31f, -0.51f, 2.66f, -1.50f, -5.92f, -0.24f, 38.74f, 3.78f, -2.63f, -33.82f, -0.99f, 0.05f, 0.00f, 0.62f, -2.08f, 1.08f, 4.11f, -3.63f, 2.07f, 7.37f, 4.52f, -8.92f, -3.48f, -2.10f, 17.34f, 1.07f, -11.06f, -2.01f, -2.43f, -47.20f, -15.36f, 20.30f, 7.38f, 50.63f, -22.60f, -10.75f, 10.38f, -0.61f, 27.26f, 6.27f, 16.89f, 20.18f, -24.27f, -1.75f, -9.67f, 34.57f, 40.31f, -8.18f, 9.33f, 4.50f, 17.77f, -42.12f, 15.96f, 0.50f, 30.97f, 3.30f, -9.08f, -25.19f, -1.30f, -0.00f, -0.00f, 0.00,
                -3.45f, -3.09f, -0.68f, 2.62f, 0.86f, -6.25f, -0.19f, 38.34f, 4.97f, -2.93f, -35.92f, -1.14f, -0.04f, 0.00f, 0.58f, -2.02f, 1.29f, 4.13f, -3.71f, 2.50f, 7.33f, 4.64f, -10.30f, -3.19f, -2.32f, 17.07f, 1.00f, -10.99f, -1.95f, -2.38f, -48.25f, -12.14f, 19.77f, 7.42f, 48.04f, -23.28f, -10.93f, 10.50f, -1.74f, 26.70f, 6.22f, 16.81f, 19.64f, -23.27f, -1.10f, -10.18f, 34.09f, 43.01f, -8.56f, 9.35f, 3.83f, 17.60f, -43.21f, 16.14f, 0.64f, 30.92f, 6.83f, -6.52f, -21.68f, -0.70f, -0.00f, -0.00f, 0.00,
                -4.11f, -2.40f, -1.52f, 2.54f, 3.07f, -6.52f, -0.10f, 37.42f, 6.81f, -3.42f, -37.73f, -1.34f, 1.11f, 0.00f, 0.51f, -1.86f, 1.24f, 4.29f, -3.67f, 2.40f, 7.56f, 4.83f, -11.06f, -2.84f, -1.79f, 16.78f, 0.90f, -10.91f, -1.93f, -2.13f, -48.51f, -11.19f, 19.28f, 7.64f, 46.93f, -23.73f, -9.85f, 10.45f, -1.75f, 26.67f, 6.33f, 17.06f, 19.14f, -22.70f, -1.15f, -10.57f, 33.81f, 44.87f, -9.17f, 9.33f, 3.57f, 17.86f, -43.61f, 16.75f, 0.71f, 31.38f, 8.45f, -2.35f, -16.40f, -0.10f, -0.00f, -0.00f, 0.00,
                -4.47f, -1.88f, -3.18f, 1.29f, 5.38f, -7.33f, 0.05f, 36.82f, 10.11f, -4.12f, -37.00f, -1.51f, 1.71f, -2.61f, 0.47f, -1.93f, 1.05f, 4.59f, -4.01f, 2.00f, 8.14f, 4.66f, -11.17f, -2.35f, 0.53f, 16.56f, 0.51f, -10.95f, -2.03f, -1.74f, -47.23f, -13.55f, 19.24f, 7.52f, 47.55f, -23.31f, -8.44f, 10.37f, -1.69f, 27.26f, 6.58f, 17.42f, 19.59f, -22.29f, -1.40f, -10.62f, 33.81f, 45.01f, -9.99f, 9.25f, 3.86f, 17.53f, -41.93f, 17.18f, 0.69f, 32.42f, 7.98f, -2.39f, -16.66f, -0.11f, -0.00f, -0.00f, 0.00,
                -4.04f, -1.53f, -5.18f, -1.28f, 6.97f, -8.04f, 0.20f, 37.12f, 13.46f, -4.44f, -31.15f, -1.29f, 1.86f, -10.40f, 0.80f, -2.48f, 0.60f, 5.11f, -5.11f, 1.04f, 9.13f, 5.39f, -10.97f, -2.68f, 2.07f, 17.14f, 0.66f, -11.31f, -2.43f, -1.64f, -44.09f, -19.19f, 19.77f, 7.44f, 51.46f, -21.95f, -6.91f, 10.33f, -2.33f, 28.35f, 6.88f, 17.54f, 21.50f, -21.71f, -1.70f, -11.20f, 35.45f, 42.31f, -10.84f, 9.00f, 5.92f, 16.23f, -40.35f, 16.70f, 0.60f, 33.86f, 5.55f, 1.73f, -13.14f, 0.15f, 0.00f, -0.00f, 0.00,
                -2.68f, -0.85f, -6.18f, -4.40f, 8.23f, -8.57f, 0.30f, 37.94f, 15.51f, -5.86f, -27.55f, -1.37f, 3.54f, -11.38f, 1.08f, -3.20f, -0.15f, 5.19f, -6.30f, -0.48f, 9.20f, 5.88f, -10.49f, -3.33f, 3.23f, 18.04f, 0.73f, -12.20f, -2.69f, -1.24f, -41.59f, -22.30f, 20.26f, 7.79f, 53.77f, -21.30f, -6.87f, 10.31f, -2.09f, 29.54f, 6.96f, 17.14f, 23.62f, -21.13f, -2.50f, -12.13f, 37.77f, 39.50f, -12.14f, 8.75f, 7.30f, 13.62f, -39.94f, 14.18f, 0.53f, 34.51f, 3.65f, 3.22f, -5.62f, -0.04f, 0.00f, -0.00f, 0.00,
                -1.25f, -0.97f, -6.12f, -7.36f, 9.72f, -8.60f, 0.38f, 39.75f, 17.04f, -4.80f, -23.49f, -0.97f, 0.67f, -10.15f, 0.71f, -3.87f, -0.51f, 5.00f, -7.56f, -1.21f, 8.70f, 7.23f, -10.38f, -4.05f, 3.44f, 18.42f, 0.77f, -12.45f, -2.57f, -1.78f, -40.64f, -22.20f, 20.40f, 8.95f, 54.66f, -22.34f, -7.07f, 10.28f, -1.41f, 30.70f, 6.66f, 16.46f, 26.11f, -21.55f, -4.35f, -10.83f, 37.81f, 36.20f, -12.15f, 8.59f, 8.93f, 11.33f, -38.98f, 12.61f, 0.51f, 36.80f, 2.83f, 0.89f, -2.48f, -0.04f, 0.00f, -0.00f, 0.00,
                -0.20f, -1.55f, -6.26f, -9.95f, 9.96f, -8.38f, 0.45f, 43.77f, 17.75f, -4.66f, -17.85f, -0.67f, -0.05f, -9.55f, 0.65f, -4.31f, -0.40f, 4.60f, -8.25f, -0.98f, 7.79f, 7.93f, -10.46f, -3.79f, 3.78f, 18.10f, 0.99f, -13.03f, -2.38f, -2.65f, -40.54f, -20.44f, 19.99f, 10.05f, 53.20f, -23.91f, -7.77f, 10.28f, -0.88f, 31.39f, 6.09f, 16.21f, 28.65f, -22.12f, -5.99f, -9.82f, 37.95f, 33.31f, -10.88f, 8.69f, 9.42f, 10.18f, -37.08f, 13.05f, 0.47f, 39.32f, 1.73f, -1.63f, -2.87f, 0.07f, 0.00f, -0.00f, 0.00,
                0.31f, -2.49f, -7.94f, -12.42f, 8.14f, -7.34f, 0.50f, 50.13f, 17.45f, -5.12f, -10.92f, -0.34f, 0.62f, -5.55f, 0.61f, -4.45f, -0.13f, 4.38f, -8.11f, -0.40f, 7.22f, 7.63f, -9.87f, -2.82f, 4.19f, 17.49f, 1.57f, -14.22f, -2.42f, -2.95f, -40.36f, -18.97f, 19.05f, 10.87f, 51.76f, -25.13f, -7.77f, 10.29f, -1.14f, 31.97f, 5.64f, 16.32f, 30.74f, -22.05f, -7.25f, -9.79f, 39.32f, 30.86f, -9.51f, 8.84f, 9.58f, 9.69f, -34.36f, 14.08f, 0.49f, 41.78f, 1.80f, -0.95f, -5.27f, 0.04f, 0.00f, -0.00f, 0.00,
                1.14f, -2.96f, -9.53f, -14.40f, 4.03f, -6.06f, 0.41f, 57.19f, 14.67f, -5.16f, -2.46f, 0.10f, 0.23f, -0.65f, 0.65f, -4.67f, 0.10f, 3.86f, -7.80f, 0.12f, 6.13f, 6.97f, -8.76f, -1.28f, 4.13f, 16.64f, 2.66f, -16.00f, -2.40f, -3.08f, -40.04f, -17.89f, 17.67f, 11.58f, 50.06f, -26.26f, -6.57f, 10.32f, -2.42f, 32.43f, 5.39f, 16.65f, 32.06f, -21.22f, -8.29f, -10.90f, 42.05f, 29.56f, -8.17f, 9.01f, 9.46f, 7.84f, -31.56f, 13.21f, 0.58f, 42.39f, 3.49f, -1.03f, -7.84f, 0.03f, 0.00f, -0.00f, 0.00,
                1.29f, -3.56f, -10.28f, -14.35f, -0.51f, -4.68f, 0.08f, 63.28f, 9.53f, -2.58f, 5.47f, 0.21f, 0.05f, 0.06f, 0.66f, -4.69f, 0.26f, 3.10f, -7.09f, 0.51f, 4.63f, 6.14f, -7.30f, 0.36f, 4.25f, 16.36f, 3.30f, -17.47f, -1.98f, -3.67f, -39.46f, -17.11f, 16.34f, 12.34f, 48.22f, -27.66f, -5.34f, 10.25f, -2.42f, 33.02f, 4.97f, 16.50f, 33.13f, -19.86f, -9.89f, -12.29f, 45.20f, 29.06f, -6.74f, 9.22f, 8.86f, 6.43f, -28.15f, 12.12f, 0.64f, 41.83f, 4.78f, -1.20f, -10.15f, 0.02f, 0.00f, -0.00f, 0.00,
                1.02f, -3.97f, -11.35f, -13.53f, -5.47f, -3.67f, -0.23f, 68.08f, 6.31f, -0.77f, 3.73f, -0.02f, 0.04f, 0.00f, 0.66f, -4.66f, 0.55f, 2.31f, -6.21f, 1.13f, 3.15f, 6.19f, -6.40f, 2.17f, 3.36f, 16.22f, 4.35f, -18.14f, -1.55f, -4.12f, -39.03f, -16.73f, 14.33f, 13.28f, 47.15f, -29.34f, -4.11f, 10.17f, -2.25f, 33.51f, 4.52f, 16.46f, 34.09f, -18.65f, -11.24f, -13.39f, 47.94f, 28.93f, -6.11f, 9.30f, 8.50f, 5.74f, -24.78f, 11.59f, 0.69f, 40.85f, 6.06f, -1.25f, -12.16f, 0.01f, 0.00f, -0.00f, -0.00,
                0.79f, -4.33f, -12.23f, -12.85f, -10.32f, -3.81f, -0.30f, 70.48f, 5.96f, -2.50f, -1.40f, 0.01f, 0.05f, 0.00f, 0.66f, -4.45f, 0.97f, 1.39f, -5.04f, 1.99f, 1.46f, 5.52f, -6.09f, 4.39f, 2.87f, 16.00f, 5.41f, -18.80f, -1.05f, -4.59f, -38.49f, -17.19f, 12.15f, 13.79f, 46.06f, -30.85f, -3.05f, 10.13f, -2.85f, 33.09f, 3.98f, 16.51f, 35.01f, -17.10f, -12.20f, -14.43f, 50.56f, 29.14f, -5.19f, 9.43f, 7.96f, 4.78f, -21.52f, 10.69f, 0.74f, 39.74f, 7.42f, -1.74f, -14.12f, -0.03f, 0.00f, -0.00f, -0.00,
                0.89f, -4.36f, -12.51f, -12.49f, -15.11f, -4.91f, -0.29f, 70.15f, 6.04f, -3.23f, -4.78f, -0.07f, 0.05f, 0.00f, 0.66f, -4.10f, 1.28f, 0.26f, -3.95f, 2.62f, -0.52f, 4.91f, -5.76f, 6.44f, 2.10f, 15.67f, 6.54f, -18.95f, -0.57f, -5.14f, -37.94f, -17.82f, 9.99f, 14.21f, 45.14f, -32.53f, -3.10f, 10.15f, -3.32f, 32.01f, 3.30f, 16.38f, 36.01f, -15.79f, -12.82f, -15.32f, 53.24f, 29.43f, -4.40f, 9.52f, 7.64f, 3.35f, -19.00f, 9.22f, 0.81f, 38.81f, 9.10f, -1.83f, -15.68f, -0.05f, 0.00f, -0.00f, -0.00,
                0.46f, -4.79f, -12.40f, -11.50f, -18.86f, -6.19f, -0.34f, 67.37f, 5.22f, -1.92f, -6.61f, -0.15f, 0.05f, 0.00f, 0.66f, -3.34f, 1.77f, -0.91f, -2.57f, 3.60f, -2.54f, 4.44f, -5.55f, 8.18f, 1.18f, 15.16f, 7.68f, -18.58f, -0.14f, -5.82f, -37.76f, -18.35f, 7.92f, 14.26f, 44.01f, -34.03f, -2.12f, 10.10f, -4.07f, 30.69f, 2.67f, 16.24f, 36.67f, -15.49f, -13.36f, -15.26f, 54.84f, 29.10f, -3.99f, 9.57f, 7.52f, 2.80f, -16.51f, 8.60f, 0.84f, 38.62f, 9.95f, -0.61f, -17.17f, 0.04f, 0.00f, -0.00f, -0.00,
                0.44f, -5.15f, -12.83f, -11.11f, -22.51f, -7.56f, -0.28f, 62.70f, 5.29f, -1.53f, -8.11f, -0.18f, 0.05f, 0.00f, 0.66f, -2.56f, 2.24f, -1.79f, -1.38f, 4.50f, -3.96f, 3.74f, -5.83f, 9.61f, 0.46f, 14.80f, 8.62f, -18.32f, 0.25f, -6.28f, -37.16f, -18.17f, 5.45f, 13.99f, 42.61f, -35.40f, -1.21f, 10.05f, -4.81f, 29.29f, 2.05f, 15.89f, 36.93f, -16.35f, -13.74f, -14.61f, 55.42f, 28.31f, -3.64f, 9.61f, 7.11f, 1.85f, -14.25f, 8.18f, 0.90f, 38.54f, 11.23f, -0.80f, -19.01f, 0.02f, 0.00f, -0.00f, -0.00};

        listNames = glGenLists(totalFrames);
        glMatrixMode(GL_MODELVIEW);
        for (unsigned int i = 0; i < totalFrames; i++)
        {
                glNewList(listNames + i, GL_COMPILE);
                DrawSkeleton(m_AgentJointList[0], AgentJointAngles + i * 63);
                glEndList();
        }

        for (vector<AgentJoint*>::const_iterator iter = m_AgentJointList.begin(); iter != m_AgentJointList.end(); iter++)
                delete *iter;
        m_AgentJointList.clear();
}
