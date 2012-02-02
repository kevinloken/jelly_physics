//
//  FallingBody.h
//  jelly
//
//  Created by Kevin Loken on 12-02-01.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef jelly_FallingBody_h
#define jelly_FallingBody_h

#include "PressureBody.h"
#include "Vector2.h"

namespace JellyPhysics 
{
    class FallingBody : public PressureBody
    {
    public:
        FallingBody(World* w, ClosedShape& s, 
                    float massPerPoint,
                    float gasPressure,
                    float shapeK, float shapeD,
                    float edgeSpringK, float edgeSpringDamp, 
                    Vector2 pos, float angle, Vector2 scale,
                    bool kinematic);
        
        virtual void accumulateExternalForces();
    };
}

#endif
