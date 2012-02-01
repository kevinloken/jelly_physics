//
//  FallingBody.m
//  jelly
//
//  Created by Kevin Loken on 12-02-01.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#include "JellyPhysics/JellyPhysics.h"
#import "Opaque.h"

#import "FallingBody.h"
#import "World.h"
#import "ClosedShape.h"

@implementation FallingBody

@synthesize cpp = _cpp;

-(id)initWithWorld:(World*) world 
             shape:(ClosedShape*)shape 
      massPerPoint:(float)massPerPoint 
       edgeSpringK:(float)edgeSpringK 
    edgeSpringDamp:(float)edgeSpringDamp
          position:(CGPoint)position
    angleInRadians:(float)angleInRadians
             scale:(CGPoint)scale
{
    self = [super init];
    if ( self != nil ) {
        self.cpp = new JPFallingBodyOpaque( new JellyPhysics::FallingBody( world.cpp->world, 
                                                            *(shape.cpp->shape),
                                                            massPerPoint,
                                                            edgeSpringK, edgeSpringDamp,
                                                            Vector2(position.x, position.y),
                                                            angleInRadians,
                                                            Vector2(scale.x, scale.y) ) 
                                    );
    }
    return self;
}

-(void)addInternalSpring:(int)pointA pointB:(int)pointB springK:(float)springK damping:(float)damping
{
    self.cpp->body->addInternalSpring(pointA, pointB, springK, damping);
}

-(void)log
{
    Vector2 position = self.cpp->body->getDerivedPosition();
    NSLog(@"position => %f, %f", position.X, position.Y);
    
}

-(CGPoint)position
{
    Vector2 position = self.cpp->body->getDerivedPosition();
    return CGPointMake(position.X, position.Y);
}
@end
