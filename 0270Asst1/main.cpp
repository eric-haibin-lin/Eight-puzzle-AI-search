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
#include <stack> 
#include <vector>

using namespace std;

//Functions
string ArrayToString(int arr[][3]);
void read_default_state();
int read_search_mode();
int run_search(int );
int run_uninformed_bfs();
int run_interactive_deepening_search();
int run_a_star_search(int);

//Global variables
//int init_state_for_test[3][3]  = {1,2,3,0,4,5,6,7,8};
int init_state_for_test[3][3] = {7,2,4,5,0,6,8,3,1};
int State::goal_state[][3] = {0,1,2,3,4,5,6,7,8};
int init_state[3][3];
map<string, bool> visit_map;
queue<State> state_queue;
stack<State> state_stack;
priority_queue<State, std::vector<State>, GreaterThanByCost > state_priority_queue;



int main(int argc, const char * argv[]) {
    read_default_state();
    int mode = read_search_mode();
    cout << "Number of steps used: " << run_search(mode) << endl;
    return 0;
    
}

string ArrayToString(int arr[][3]){
    string str;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j<3; j++)
            str += to_string(arr[i][j]);
    return str;
}

void read_state(){
    cout << "Please input 9 numbers as the initial state (empty denoted as 0):\n";
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            cin >> init_state[i][j];
}

void read_default_state(){
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++){
            init_state[i][j] = init_state_for_test[i][j];
            DEBUG_PRINT(init_state[i][j]);
        }
    cout << endl;
}

int read_search_mode(){
    int mode;
    cout << "Please select a programme to run" <<endl;
    cout << "1: Uninformed breadth-first search" << endl;
    cout << "2: Iterative Deepening search" << endl;
    cout << "3: A* with misplacement as heuristic" << endl;
    cout << "4: A* with Manhattan distance as heuristic" << endl;
    cout << "I choose: ";
    cin >> mode;
    return mode;
}

int run_search(int mode){
    switch (mode) {
        case UNINFORMED_BFS_MODE: {return run_uninformed_bfs();}
        case IDS_MODE: {return run_interactive_deepening_search();}
        case A_MISTILE_MODE: {return run_a_star_search(A_MISTILE_MODE);}
        case A_MANHATTAN_MODE: {return run_a_star_search(A_MANHATTAN_MODE);}
        default: return 0;
    }
    
}

int run_uninformed_bfs(){
    State init_state_object = State(init_state);
    state_queue.push(init_state_object);
    
    while (!state_queue.empty()){
        State current_state_obj = state_queue.front();
        state_queue.pop();
        
        if (current_state_obj.check_goal_state() == true)
            return current_state_obj.get_steps();
        else{
            visit_map[current_state_obj.get_id()] = true;
            current_state_obj.generate_candidate(UNINFORMED_BFS_MODE);
        }
    }
    DEBUG_PRINT("Queue exhausted..\n");
    return 0;
}

int run_interactive_deepening_search(){

    int depth = 1;
    while (true){
        State init_state_object = State(init_state);
        state_stack.push(init_state_object);
        
        while (!state_stack.empty()){
            State current_state_obj = state_stack.top();
            state_stack.pop();
            
            if (current_state_obj.check_goal_state() == true)
                return current_state_obj.get_steps();
            else{
                visit_map[current_state_obj.get_id()] = true;
                current_state_obj.generate_candidate(IDS_MODE, depth);
            }
        }
        visit_map.clear();
        depth++;
        DEBUG_PRINT("current depth:");
        DEBUG_PRINT(depth);
        DEBUG_PRINT(endl);
    }
    
    DEBUG_PRINT("Stack exhausted..\n");
    return 0;
}
int run_a_star_search(int search_mode){
    int checked = 0;
    State init_state_object = State(init_state);
    state_priority_queue.push(init_state_object);
    
    while (!state_priority_queue.empty()){
        checked ++;
        State current_state_obj = state_priority_queue.top();
        state_priority_queue.pop();
        DEBUG_PRINT("New state object from priority queue with cost: ");
        DEBUG_PRINT(current_state_obj.get_cost());
        DEBUG_PRINT(endl);
        
        if (current_state_obj.check_goal_state() == true){
            DEBUG_PRINT("Number of nodes checked:");
            DEBUG_PRINT(checked);
            DEBUG_PRINT(endl);
            
            return current_state_obj.get_steps();
            
        }
        
        else{
            visit_map[current_state_obj.get_id()] = true;
            current_state_obj.generate_candidate(search_mode);
        }
    }
    DEBUG_PRINT("Queue exhausted..\n");
    return 0;
};
