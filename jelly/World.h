//
//  World.h
//  jelly
//
//  Created by Kevin Loken on 12-02-01.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

struct JPWorldOpaque;

@interface World : NSObject
{
    struct JPWorldOpaque *_cpp;
}

@property (nonatomic, assign) struct JPWorldOpaque* cpp;

-(void)update:(float)dt;

@end
