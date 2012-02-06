//
//  FallingBody.cpp
//  jelly
//
//  Created by Kevin Loken on 12-02-01.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "FallingBody.h"

namespace JellyPhysics 
{
    
/*
 PressureBody(World* w, const ClosedShape& s, float mpp,
 float gasPressure, float shapeK, float shapeD,
 float edgeK, float edgeD,
 const Vector2& pos, float angleInRadians, const Vector2& scale,
 bool kinematic) 
 */
FallingBody::FallingBody(World* w, ClosedShape& s, 
            float massPerPoint,
            float gasPressure,
            float shapeK, float shapeD,
            float edgeSpringK, float edgeSpringDamp, 
            Vector2 pos, float angle, Vector2 scale,
            bool kinematic)
: PressureBody(w,s,massPerPoint,gasPressure, shapeK, shapeD, edgeSpringK, edgeSpringDamp, pos, angle, scale, kinematic)
{
}

void FallingBody::accumulateExternalForces()
{
    SpringBody::accumulateExternalForces();
    
    // gravity!
    for (int i = 0; i < mPointMasses.size(); i++)
        mPointMasses[i].Force += Vector2(0.f, -9.81f * mPointMasses[i].Mass);
}

}