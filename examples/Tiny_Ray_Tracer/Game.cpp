#include <iostream>

#include "Game.h"
#include "PlayState.h"

Game::Game()
   : mPlayState()
   , mFSM()
{

}

bool Game::initialize()
{
   // Create the FSM
   mFSM = std::make_shared<FiniteStateMachine>();

   // Initialize the states
   std::unordered_map<std::string, std::shared_ptr<State>> mStates;

   mPlayState = std::make_shared<PlayState>(mFSM);

   mStates["play"] = mPlayState;

   // Initialize the FSM
   mFSM->initialize(std::move(mStates), "play");

   return true;
}

void Game::update()
{
   mFSM->updateCurrentState();
}
