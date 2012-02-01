//
//  ClosedShape.m
//  jelly
//
//  Created by Kevin Loken on 12-02-01.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "JellyPhysics/JellyPhysics.h"
#import "Opaque.h"

#import "ClosedShape.h"

@implementation ClosedShape

@synthesize cpp = _cpp;

-(id)init
{
    self = [super init];
    if ( self != nil ) {
        self.cpp = new JPClosedShapeOpaque( new JellyPhysics::ClosedShape() );
    }
    return self;
}

-(void)begin
{
    self.cpp->shape->begin();
}

-(void)addVertex:(CGPoint)vertex
{
    self.cpp->shape->addVertex( Vector2(vertex.x, vertex.y) );
}

-(void)finish
{
    self.cpp->shape->finish();
}

-(void)log
{
    JellyPhysics::Vector2List vertices = self.cpp->shape->getVertices();
    for ( int i = 0; i < vertices.size(); ++i ) {
        NSLog(@"vertex %d: position => %f, %f", i, vertices[i].X, vertices[i].Y);
    }
}
@end
