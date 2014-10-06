//
//  BFSMove.h
//  0270Asst1
//
//  Created by Haibin Lin on 30/9/14.
//  Copyright (c) 2014 Haibin Lin. All rights reserved.
//

#ifndef ___270Asst1__BFSMove__
#define ___270Asst1__BFSMove__

#include <stdio.h>
#include "Move.h"

class BFSMove : public Move{

public:
    BFSMove(State state_obj): Move(state_obj){};
    void add_to_queue();
};



#endif /* defined(___270Asst1__BFSMove__) */
