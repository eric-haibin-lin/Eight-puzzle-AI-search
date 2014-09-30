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
    DEBUG_PRINT("Generaing all moves..\n");
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

bool Move::is_legal(int x, int y){
    if (x >= 0 & x <=2 & y >=0 & y <=2) return true;
    else return false;
}


