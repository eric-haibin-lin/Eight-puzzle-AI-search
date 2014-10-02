//
//  AStarMistileMove.cpp
//  0270Asst1
//
//  Created by Haibin Lin on 1/10/14.
//  Copyright (c) 2014 Haibin Lin. All rights reserved.
//

#include "AStarMistileMove.h"

void AStarMistileMove::add_to_queue(){
    DEBUG_PRINT("Preparing for adding new child..\n");
    string key = current_state_obj.get_id();
    if (visit_map.count(key)) {
        DEBUG_PRINT("Child exists! Abort adding\n");
        return;
    }
    State new_state = current_state_obj;
    new_state.increase_step();
    calculate_distance(new_state);
    state_priority_queue.push(new_state);
    DEBUG_PRINT("New child added.\n");
}


bool AStarMistileMove::is_legal(int x, int y){
    if (x >= 0 & x <=2 & y >=0 & y <=2) return true;
    else return false;
}

int AStarMistileMove::do_calculate(int x, int y, State state_obj){
    if ((state_obj.current_state)[x][y] != (3*x + y)) return 1;
    else return 0;
}