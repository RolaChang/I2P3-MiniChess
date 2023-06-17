#include <cstdlib>

#include "../state/state.hpp"
#include "./minimax.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <cassert>
#include <cstdint>
#include <limits.h>

#define MAX_DEPTH 3
int minimax(State *state, int depth);
/**
 * @brief Player picks the largest score, opponent picks the smallest score
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Minimax::get_move(State *state, int depth){
    minimax(state, depth);
    return state->evalMove;
}

int minimax(State *state, int depth){

    if(depth==0){
        if(state->evaluate()){
            auto actions = state->legal_actions;
            state->evalMove = actions[(rand()+depth)%actions.size()];
        }
        return 0;
    }
    State* curS = state;
    int self = curS->player;
    int largest = INT_MIN, smallest = INT_MAX;
    Move nxtmove; 
    // Minimizing
    if(self){
        if(!state->legal_actions.size()) state->get_legal_actions();
        for(auto it: state->legal_actions){
            int val = minimax(curS->next_state(it), depth-1);
            if(val<smallest){
                smallest = val;
                nxtmove = it;
            }
        }
        state->evalMove = nxtmove;
        return largest;        
    }
    // Maximizing
    else{
        if(!state->legal_actions.size()) state->get_legal_actions();
        for(auto it: state->legal_actions){
            int val = minimax(curS->next_state(it), depth-1);
            if(val>largest){
                largest = val;
                nxtmove = it;
            }
        }
        state->evalMove = nxtmove;
        return largest;
    }
}