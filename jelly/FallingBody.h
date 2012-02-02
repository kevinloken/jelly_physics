//
//  FallingBody.h
//  jelly
//
//  Created by Kevin Loken on 12-02-01.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@class World;
@class ClosedShape;

struct JPFallingBodyOpaque;

@interface FallingBody : NSObject
{
    struct JPFallingBodyOpaque *_cpp;
}

@property (nonatomic, assign) struct JPFallingBodyOpaque* cpp;

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
         kinematic:(BOOL)kinematic;

-(void)addInternalSpring:(int)a pointB:(int)pointB springK:(float)springK damping:(float)damping;

-(void)log;
-(CGPoint)position;
-(CGPoint)vertex:(int)index;

@end
