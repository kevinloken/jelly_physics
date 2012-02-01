//
//  World.m
//  jelly
//
//  Created by Kevin Loken on 12-02-01.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "JellyPhysics/JellyPhysics.h"
#import "Opaque.h"

#import "World.h"

@implementation World

@synthesize cpp = _cpp;

-(id)init
{
    self = [super init];
    if ( self != nil ) {
        self.cpp = new JPWorldOpaque( new JellyPhysics::World() );
    }
    return self;
}

-(void)update:(float)dt
{
    self.cpp->world->update(dt);
}

-(void)dealloc
{
    delete _cpp;
    _cpp = NULL;
    
    [super dealloc];
}

@end
