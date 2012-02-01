//
//  FallingBody.h
//  jelly
//
//  Created by Kevin Loken on 12-02-01.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef jelly_FallingBody_h
#define jelly_FallingBody_h

#include "SpringBody.h"
#include "Vector2.h"

namespace JellyPhysics 
{
    class FallingBody : public SpringBody
    {
    public:
        FallingBody(World* w, ClosedShape& s, 
                    float massPerPoint,
                    float edgeSpringK, float edgeSpringDamp, 
                    Vector2 pos, float angle, Vector2 scale);
        
        virtual void accumulateExternalForces();
    };
}

#endif
