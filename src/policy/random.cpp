#include <cstdlib>

#include "../state/state.hpp"
#include "./random.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <cassert>
#include <cstdint>



/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 

Move Random::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  auto actions = state->legal_actions;
  return actions[(rand()+depth)%actions.size()];
}*/


/**
 * @brief Get a legal action by state-value
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
*/
Move Random::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  auto actions = state->legal_actions;
  int val=-1;
  Move nxtmove;
  for(auto it: actions){
      State *tmp = state->next_state(it);
      int tmpval = tmp->evaluate(true);
      if(tmpval>val){
        val = tmpval;
        nxtmove = it;
      }
  }
  state->evalMove = nxtmove;
  return state->evalMove;
} 