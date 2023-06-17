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

#define MAX_DEPTH 3
int alphabeta(State *state, int depth, int alpha, int beta);
/**
 * @brief Player picks the largest score, opponent picks the smallest score
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Alphabeta::get_move(State *state, int depth){
    int Alpha = INT_MIN, Beta = INT_MAX;
    alphabeta(state, depth, Alpha, Beta);
    return state->evalMove;
}

int alphabeta(State *state, int depth, int alpha, int beta){

    if(depth==0){
        if(state->evaluate()){
            auto actions = state->legal_actions;
            state->evalMove = actions[(rand()+depth)%actions.size()];
        }
        return 0;
    }
    State *curS = state;
    int self = state->player;
    // Minimizing
    if(self){
        if(!state->legal_actions.size()) state->get_legal_actions();
        for(auto it: state->legal_actions){
            int val = alphabeta(curS->next_state(it), depth-1, alpha, beta);
            if(val<beta){
                if(depth==0) state->evalMove = it;
                beta = val;
            }
            if(alpha>=beta) break;
        }
        return beta;        
    }
    // Maximizing
    else{
        if(!state->legal_actions.size()) state->get_legal_actions();
        for(auto it: state->legal_actions){
            int val = alphabeta(curS->next_state(it), depth-1, alpha, beta);
            if(val>alpha){
                if(depth==0) state->evalMove = it;
                alpha = val;
            }
            if(alpha>=beta) break;
        }
        return alpha;
    }
}