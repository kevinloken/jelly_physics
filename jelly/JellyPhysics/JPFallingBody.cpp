//
//  FallingBody.cpp
//  jelly
//
//  Created by Kevin Loken on 12-02-01.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "JPFallingBody.h"

namespace JellyPhysics 
{
    

FallingBody::FallingBody(World* w, ClosedShape& s, 
            float massPerPoint,
            float edgeSpringK, float edgeSpringDamp, 
            Vector2 pos, float angle, Vector2 scale)
: SpringBody(w,s,massPerPoint,edgeSpringK, edgeSpringDamp, pos, angle, scale, false)
{
}

void FallingBody::accumulateExternalForces()
{
    SpringBody::accumulateExternalForces();
    
    // gravity!
    for (int i = 0; i < mPointMasses.size(); i++)
        mPointMasses[i].Force += Vector2(0.f, -9.8f * mPointMasses[i].Mass);
}

}