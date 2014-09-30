//
//  BFSMove.cpp
//  0270Asst1
//
//  Created by Haibin Lin on 30/9/14.
//  Copyright (c) 2014 Haibin Lin. All rights reserved.
//

#include "BFSMove.h"


void BFSMove::add_to_queue(){
    DEBUG_PRINT("Preparing for adding new child..\n");
    string key = current_state_obj.get_id();
    if (visit_map.count(key)) {
        DEBUG_PRINT("Child exists! Abort adding\n");
        return;
    }
    State new_state = current_state_obj;
    new_state.increase_step();
    state_queue.push(new_state);
    DEBUG_PRINT("New child added.\n");
}

int BFSMove::do_calculate(int x, int y){
    return 1;
}
