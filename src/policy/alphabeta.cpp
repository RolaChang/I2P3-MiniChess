#include <cstdlib>

#include "../state/state.hpp"
#include "./alphabeta.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <cassert>
#include <cstdint>
#include <limits.h>

int alphabeta(State *state, int depth, int alpha, int beta, bool self);
/**
 * @brief Player picks the largest score, opponent picks the smallest score
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Alphabeta::get_move(State *state, int depth){
    int Alpha = INT_MIN, Beta = INT_MAX;
    alphabeta(state, depth, Alpha, Beta, true);
    return state->evalMove;
}

int alphabeta(State *state, int depth, int alpha, int beta, bool self){

    if(depth==0){
        if(self) return state->evaluate(state->player);
        else return state->evaluate(1-state->player);
    }
    State *curS = state;
    Move nxtMove;
    // Maximizing
    if(self){
        if(!state->legal_actions.size()) state->get_legal_actions();
        for(auto it: state->legal_actions){
            int val = alphabeta(curS->next_state(it), depth-1, alpha, beta, false);
            if(val>alpha){
                alpha = val;
                nxtMove = it;
            }
            state->evalMove = nxtMove;
            if(alpha>=beta) break;
        }
        return alpha;       
    }
    // Minimizing
    else{
        if(!state->legal_actions.size()) state->get_legal_actions();
        for(auto it: state->legal_actions){
            int val = alphabeta(curS->next_state(it), depth-1, alpha, beta, true);
            if(val<beta){
                beta = val;
                nxtMove = it;
            }
            state->evalMove = nxtMove;
            if(alpha>=beta) break;
        }
        return beta; 
    }
}