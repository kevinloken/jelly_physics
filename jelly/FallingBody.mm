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
       gasPressure:(float)gasPressure 
            shapeK:(float)shapeK 
            shapeD:(float)shapeD 
       edgeSpringK:(float)edgeSpringK 
    edgeSpringDamp:(float)edgeSpringDamp
          position:(CGPoint)position
    angleInRadians:(float)angleInRadians
             scale:(CGPoint)scale
         kinematic:(BOOL)kinematic
{
    self = [super init];
    if ( self != nil ) {
        self.cpp = new JPFallingBodyOpaque( new JellyPhysics::FallingBody( world.cpp->world, 
                                                            *(shape.cpp->shape),
                                                            massPerPoint,
                                                            gasPressure,
                                                            shapeK, shapeD,
                                                            edgeSpringK, edgeSpringDamp,
                                                            Vector2(position.x, position.y),
                                                            angleInRadians,
                                                            Vector2(scale.x, scale.y), kinematic ) 
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

-(CGPoint)vertex:(int)index
{
    NSAssert(index >= 0, @"invalid vertex index");
    NSAssert(index < self.cpp->body->getPointMassCount(), @"invalid vertex index");
    
    Vector2 position = self.cpp->body->getPointMass(index)->Position;
    return CGPointMake(position.X, position.Y);
}

-(int)vertexCount
{
    return self.cpp->body->getPointMassCount();
}
@end
