//
//  AStarMistileMove.h
//  0270Asst1
//
//  Created by Haibin Lin on 1/10/14.
//  Copyright (c) 2014 Haibin Lin. All rights reserved.
//

#ifndef ___270Asst1__AStarMistileMove__
#define ___270Asst1__AStarMistileMove__

#include <stdio.h>
#include "Move.h"

class AStarMistileMove : public Move{
    int depth;
public:
    AStarMistileMove(State state_obj): Move(state_obj){};
    void add_to_queue();
    int do_calculate(int, int, State);
    bool is_legal(int, int);
};


#endif /* defined(___270Asst1__AStarMistileMove__) */
