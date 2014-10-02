//
//  MoveFactory.cpp
//  0270Asst1
//
//  Created by Haibin Lin on 30/9/14.
//  Copyright (c) 2014 Haibin Lin. All rights reserved.
//

#include "MoveFactory.h"

using namespace std;

MoveFactory::MoveFactory(int mode){
    this->mode  = mode;
};
Move* MoveFactory::generate_move(State state_obj, int depth){
    switch (mode) {
        case UNINFORMED_BFS_MODE:{
            BFSMove* move = new BFSMove(state_obj);
            return move;
        }
        case IDS_MODE:{
            IDSMove* move = new IDSMove(state_obj, depth);
            return move;
        }
        case A_MISTILE_MODE:{
            AStarMistileMove* move = new AStarMistileMove(state_obj);
            return move;
        }
        case A_MANHATTAN_MODE:{
            AStarManhattanMove* move = new AStarManhattanMove(state_obj);
            return move;
        }
        default:{
            Move* move = new Move(state_obj);
            return move;
        }
    }
}