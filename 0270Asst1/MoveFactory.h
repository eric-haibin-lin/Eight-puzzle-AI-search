//
//  MoveFactory.h
//  0270Asst1
//
//  Created by Haibin Lin on 30/9/14.
//  Copyright (c) 2014 Haibin Lin. All rights reserved.
//

#ifndef ___270Asst1__MoveFactory__
#define ___270Asst1__MoveFactory__

#include <stdio.h>
#include "Move.h"
#include "State.h"
#include "BFSMove.h"
#include "IDSMove.h"


using namespace std;

class MoveFactory{
    int mode;
public:
    MoveFactory(int);
    Move* generate_move(State, int = 0);
};

#endif /* defined(___270Asst1__MoveFactory__) */
