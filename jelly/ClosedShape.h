//
//  ClosedShape.h
//  jelly
//
//  Created by Kevin Loken on 12-02-01.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

struct JPClosedShapeOpaque;

@interface ClosedShape : NSObject
{
    struct JPClosedShapeOpaque* _cpp;
}

@property (nonatomic, assign) struct JPClosedShapeOpaque* cpp;

-(void)begin;
-(void)addVertex:(CGPoint)vertex;
-(void)finish;

-(void)log;
-(CGPoint)vertex:(int)vertex;

@end
