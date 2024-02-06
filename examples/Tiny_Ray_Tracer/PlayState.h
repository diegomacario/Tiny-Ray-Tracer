#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "State.h"
#include "FSM.h"

class PlayState : public State
{
public:

   PlayState(const std::shared_ptr<FiniteStateMachine>& finiteStateMachine);
   ~PlayState() = default;

   PlayState(const PlayState&) = delete;
   PlayState& operator=(const PlayState&) = delete;

   PlayState(PlayState&&) = delete;
   PlayState& operator=(PlayState&&) = delete;

   void enter() override;
   void update() override;
   void exit() override;

private:

   std::shared_ptr<FiniteStateMachine> mFSM;
};

#endif
