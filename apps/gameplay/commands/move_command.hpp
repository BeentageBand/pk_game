#pragma once
#include <iostream>
#include "battle.hpp"
#include "command.hpp"
#include "battle/move.hpp"
#include "pkm/trainer.hpp"

namespace gameplay
{
  class MoveCommand : public Command
  {
    battle::Move * move;
    pkm::Trainer * trainer;

    public:
    MoveCommand(battle::Move & move, pkm::Trainer & trainer)
      : move(&move), trainer(&trainer)
    {}

    void execute(Battle & battle)
    {
      if(this->trainer == &battle.get_trainer())
      {
        this->move->use(this->battle.get_trainers_pokemon(), this->battle.get_opponents_pokemon(), *this->move);
      }
      else
      {
        this->move->use(this->battle.get_opponents_pokemon(), this->battle.get_trainers_pokemon(), *this->move);
      }
    }
  };
} // namespace battle
