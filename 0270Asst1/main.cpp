//
//  main.cpp
//  0270Asst1
//
//  Created by Haibin Lin on 29/9/14.
//  Copyright (c) 2014 Haibin Lin. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <array>
#include "State.h"

using namespace std;

string ArrayToString(int arr[][3]);

int State::goal_state[][3] = {0,1,2,3,4,5,6,7,8};

map<string, bool> visit_map;
queue<State> state_queue;

int main(int argc, const char * argv[]) {
    bool lazy = true;

    int init_state[3][3];
    int init_state_for_test[3][3] = {7,2,4,5,0,6,8,3,1};
//    int init_state_for_test[3][3]  = {1,2,3,0,4,5,6,7,8};
    
    cout << "Please input 9 numbers as the initial state (empty denoted as 0):\n";
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            if (lazy){
                init_state[i][j] = init_state_for_test[i][j];
                cout << init_state[i][j];
            }
            else
                cin >> init_state[i][j];
    cout << endl;
    
    State init_state_object = State(init_state);

    
    state_queue.push(init_state_object);
    while (!state_queue.empty()){
        State current_state_obj = state_queue.front();
        state_queue.pop();
        
        if (current_state_obj.check_goal_state() == true)
            return current_state_obj.get_steps();
        else{
            visit_map[current_state_obj.get_id()] = true;
            current_state_obj.generate_candidate();
        }
    }
    
    DEBUG_PRINT("Queue exhausted..\n");
    return 0;
    
}

string ArrayToString(int arr[][3]){
    string str;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j<3; j++)
            str += to_string(arr[i][j]);
    return str;
}
