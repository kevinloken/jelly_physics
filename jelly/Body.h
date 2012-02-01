//
//  Body.h
//  jelly
//
//  Created by Kevin Loken on 12-02-01.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@class World;
@class ClosedShape;

struct JPBodyOpaque;

@interface Body : NSObject
{
    struct JPBodyOpaque *_cpp;
}

@property (nonatomic, assign) struct JPBodyOpaque* cpp;

-(id)initWithWorld:(World*) world;
-(id)initWithWorld:(World*) world 
             shape:(ClosedShape*)shape 
      massPerPoint:(float)massPerPoint 
          position:(CGPoint)position 
    angleInRadians:(float)angleInRadians
             scale:(CGPoint)scale
         kinematic:(BOOL)kinematic;


@end
