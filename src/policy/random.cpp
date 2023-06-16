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
}
 */

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
  if(state->evaluate()){
    auto actions = state->legal_actions;
    return actions[(rand()+depth)%actions.size()];
  }
  return state->evalMove;
}