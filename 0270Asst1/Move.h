//
//  Move.h
//  0270Asst1
//
//  Created by Haibin Lin on 29/9/14.
//  Copyright (c) 2014 Haibin Lin. All rights reserved.
//

#ifndef ___270Asst1__Move__
#define ___270Asst1__Move__

#include <iostream>
#include "State.h"
using namespace std;

class Move{
    State current_state_obj;
    
public:
    Move(State);
    
    void generate_all_move();
    int calculate_distance();
    int do_calculate(int, int);
    void add_to_queue();
    bool is_legal(int x, int y);
};

extern queue<State> state_queue;
extern string ArrayToString(int [][3]);

extern map<string, bool> visit_map;
    
#endif /* defined(___270Asst1__Move__) */
