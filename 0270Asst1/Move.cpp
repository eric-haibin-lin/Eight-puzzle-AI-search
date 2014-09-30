//
//  Move.cpp
//  0270Asst1
//
//  Created by Haibin Lin on 29/9/14.
//  Copyright (c) 2014 Haibin Lin. All rights reserved.
//

#include "Move.h"

Move::Move(State new_state){
    current_state_obj = new_state;
    DEBUG_PRINT("Initializing move object..\n");
}

void Move::generate_all_move(){
    int x = current_state_obj.get_x();
    int y = current_state_obj.get_y();
    
    if (is_legal(x+1,y)) {
        current_state_obj.swap_array(x, y, x+1, y);
        add_to_queue();
        current_state_obj.swap_array(x, y, x+1, y);
    }
    if (is_legal(x-1,y)) {
        current_state_obj.swap_array(x, y, x-1, y);
        add_to_queue();
        current_state_obj.swap_array(x, y, x-1, y);
    }
    if (is_legal(x,y+1)) {
        current_state_obj.swap_array(x, y, x, y+1);
        add_to_queue();
        current_state_obj.swap_array(x, y, x, y+1);
    }
    if (is_legal(x,y-1)) {
        current_state_obj.swap_array(x, y, x, y-1);
        add_to_queue();
        current_state_obj.swap_array(x, y, x, y-1);
    }
    return;
}

int Move::calculate_distance(){
    int total_distance;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            total_distance += do_calculate(i,j);
    return total_distance;
}

int Move::do_calculate(int x, int y){
    return 1;
}

void Move::add_to_queue(){
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


bool Move::is_legal(int x, int y){
    if (x >= 0 & x <=2 & y >=0 & y <=2) return true;
    else return false;
}


