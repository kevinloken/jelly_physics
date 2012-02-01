//
//  Body.m
//  jelly
//
//  Created by Kevin Loken on 12-02-01.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "JellyPhysics/JellyPhysics.h"
#import "Opaque.h"

#import "Body.h"
#import "World.h"
#import "ClosedShape.h"

@implementation Body

@synthesize cpp = _cpp;

-(id)initWithWorld:(World*) world
{
    self = [super init];
    if ( self != nil ) {
        self.cpp = new JPBodyOpaque( new JellyPhysics::Body( world.cpp->world ) );
    }
    return self;
}

// Body::Body( World* w, const ClosedShape& shape, float massPerPoint, Vector2 position, float angleInRadians, Vector2 scale, bool kinematic)

-(id)initWithWorld:(World*) world 
             shape:(ClosedShape*)shape 
      massPerPoint:(float)massPerPoint 
          position:(CGPoint)position 
    angleInRadians:(float)angleInRadians
             scale:(CGPoint)scale
         kinematic:(BOOL)kinematic
{
    self = [super init];
    if ( self != nil ) {
        self.cpp = new JPBodyOpaque( new JellyPhysics::Body( world.cpp->world, 
                                                             *(shape.cpp->shape),
                                                            massPerPoint,
                                                            Vector2(position.x, position.y),
                                                            angleInRadians,
                                                            Vector2(scale.x, scale.y),
                                                            kinematic) 
                                    );
    }
    return self;
}

@end
