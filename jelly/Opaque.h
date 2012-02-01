//
//  Opaque.h
//  jelly
//
//  Created by Kevin Loken on 12-02-01.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef jelly_Opaque_h
#define jelly_Opaque_h

struct JPWorldOpaque {
public:
    JPWorldOpaque( JellyPhysics::World* w ) : world(w) {}
    ~JPWorldOpaque() { delete world; world = NULL; }
    JellyPhysics::World* world;
};

struct JPClosedShapeOpaque {
public:
    JPClosedShapeOpaque( JellyPhysics::ClosedShape* s) : shape(s) {}
    ~JPClosedShapeOpaque() { delete shape; shape = NULL; }
    
    JellyPhysics::ClosedShape* shape;
};

struct JPBodyOpaque {
public:
    JPBodyOpaque( JellyPhysics::Body* b ) : body(b) {}
    ~JPBodyOpaque() { delete body; body = NULL; }
    
    JellyPhysics::Body* body;
};

struct JPFallingBodyOpaque {
public:
    JPFallingBodyOpaque( JellyPhysics::FallingBody* b) : body(b) {}
    ~JPFallingBodyOpaque() { delete body; body = NULL; }
    
    JellyPhysics::FallingBody* body;
};

#endif
