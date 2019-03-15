#pragma once
#include "command.hpp"
#include "engine.hpp"
#include "option.hpp"
#include "pkm/trainer.hpp"

namespace gameplay
{
  class Battle
  {
    public:
    enum Status
    {
      CONTINUES = 0,
      STALE,
      WIN,
      LOSE
    };

    Engine * engine;
    pkm::Trainer * trainer;
    pkm::Trainer * opponent;

    public:
    Battle(Engine & engine, pkm::Trainer & trainer, pkm::Trainer & opponent)
      : engine(engine) options(&options), trainer(&trainer), opponent(&opponent)
    {}

    inline pkm::Trainer & get_trainer(void) {return this->trainer;}
    inline pkm::Trainer & get_opponent(void) {return this->opponent_pokemon;}
    inline Engine & get_engine(void) { return this->engine;}

    void play(void)
    {
      uint8_t status;
      do
      {
        std::shared_ptr<Options> options = this->engine->build_options(*this);
        std::shared_ptr<Command> trainer_command = options->build(*this->trainer);
        std::shared_ptr<Command> opponent_command = options->build(*this->opponent);

        if(trainer_command)
          trainer_command->execute(*this);
        if(opponent_command)
          opponent_command->execute(*this);

        status = this->evaluate();
      }while(status == CONTINUES);
    }

    uint8_t evaluate(void)
    {
      return 0;//TODO fix gameplay status
    }
  };
}
