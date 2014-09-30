//
//  State.h
//  0270Asst1
//
//  Created by Haibin Lin on 29/9/14.
//  Copyright (c) 2014 Haibin Lin. All rights reserved.
//

#ifndef ___270Asst1__State__
#define ___270Asst1__State__

#include <stdio.h>
#include <string>
#include <map>
#include <queue>

using namespace std;

#define DEBUG_MODE true
#define UNINFORMED_BFS_MODE 1
#define IDS_MODE 2
#define A_MISTILE_MODE 3
#define A_MANHATTAN_MODE 4

#if (DEBUG_MODE)
#define DEBUG_PRINT(str) std::cout << str
#else
#define DEBUG_PRINT(str) ;
#endif


class State {
    
    int current_state[3][3];
    int steps;
    int x;
    int y;
    
public:
    static int goal_state[3][3];
    int key;
    
    void swap_array(int, int, int, int);
    State();
    State(int [][3], int = 0);
    bool check_goal_state();
    void generate_candidate(int = 0);
    int get_steps();
    string get_id();
    int get_x(){return x;};
    int get_y(){return y;};
    void increase_step(){ this->steps ++;};
    void update_position(int new_x,int new_y);
};

extern queue<State> state_queue;
extern string ArrayToString(int [][3]);
extern map<string, bool> visit_map;


#endif /* defined(___270Asst1__State__) */
