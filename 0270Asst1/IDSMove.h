//
//  IDSMove.h
//  0270Asst1
//
//  Created by Haibin Lin on 30/9/14.
//  Copyright (c) 2014 Haibin Lin. All rights reserved.
//

#ifndef ___270Asst1__IDSMove__
#define ___270Asst1__IDSMove__

#include <stdio.h>
#include "Move.h"

class IDSMove : public Move{
    int depth;
public:
    IDSMove(State state_obj, int depth): Move(state_obj){ this->depth = depth;};
    void add_to_queue();
    bool is_legal(int, int);
};



#endif /* defined(___270Asst1__IDSMove__) */
