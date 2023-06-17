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

int minimax(State *s, int depth, bool self);
/**
 * @brief Player picks the largest score, opponent picks the smallest score
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Minimax::get_move(State *state, int depth){
    minimax(state, depth, true);
    return state->evalMove;
}

int minimax(State *state, int depth, bool self){

    if(depth==0){
        return state->evaluate(self);
    }
    int largest = INT_MIN, smallest = INT_MAX;
    State *curS = state;
    Move nxtMove;
    // Maximizing
    if(self){
        if(!state->legal_actions.size()) state->get_legal_actions();
        for(auto it: state->legal_actions){
            int val = minimax(curS->next_state(it), depth-1, false);
            if(val>largest){
                largest = val;
                nxtMove = it;
            }
            state->evalMove = nxtMove;
        }
        return largest;       
    }
    // Minimizing
    else{
        if(!state->legal_actions.size()) state->get_legal_actions();
        for(auto it: state->legal_actions){
            int val = minimax(curS->next_state(it), depth-1, true);
            if(val<smallest){
                smallest = val;
                nxtMove = it;
            }
            state->evalMove = nxtMove;
        }
        return smallest; 
    }
}

/*
int minimax(State *state, int depth){

    if(depth==0){
        return state->evaluate();
    }
    int largest = INT_MIN, smallest = INT_MAX;
    State *curS = state;
    Move nxtMove;
    // Maximizing
    if(state->player){
        if(!state->legal_actions.size()) state->get_legal_actions();
        for(auto it: state->legal_actions){
            int val = minimax(curS->next_state(it), depth-1);
            if(val>largest){
                largest = val;
                nxtMove = it;
            }
            state->evalMove = nxtMove;
        }
        return largest;       
    }
    // Minimizing
    else{
        if(!state->legal_actions.size()) state->get_legal_actions();
        for(auto it: state->legal_actions){
            int val = minimax(curS->next_state(it), depth-1);
            if(val<smallest){
                smallest = val;
                nxtMove = it;
            }
            state->evalMove = nxtMove;
        }
        return smallest; 
    }
}
*/