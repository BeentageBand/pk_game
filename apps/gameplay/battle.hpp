#pragma once
#include <cstdint>
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
      STALE = 0x00U,
      LOSE = 0x01U,
      WIN = 0x02U,
      CONTINUES = 0x03
    };

    static uint8_t const EVALUATION_MASK;

    Engine * engine;
    pkm::Trainer trainer;
    pkm::Trainer opponent;

    public:
    Battle(Engine & engine, pkm::Trainer const & trainer, pkm::Trainer const & opponent)
      : engine(&engine), trainer(trainer), opponent(opponent)
    {}

    inline pkm::Trainer & get_trainer(void) {return this->trainer;}
    inline pkm::Trainer & get_opponent(void) {return this->opponent;}
    inline Engine & get_engine(void) { return *this->engine;}

    uint8_t play(void)
    {
        Option && options = this->get_engine().build_options(*this);
        Command && trainer_command = options.build(this->trainer);
        Command && opponent_command = options.build(this->opponent);

        trainer_command.execute(*this);
        opponent_command.execute(*this);

        return this->evaluate();
    }

    uint8_t evaluate(void)
    {
        Decider && decider = this->get_engine().build_decider();
        bool can_trainer_continue = decider.evaluate(this->trainer);
        bool can_opponent_continue = decider.evaluate(this->opponent);

        uint8_t evaluation = 0x01U << (EVALUATION_MASK & evaluation);
        evaluation |= (EVALUATION_MASK & can_opponent_continue);
        return evaluation;
    }
  };

  uint8_t const Battle::EVALUATION_MASK = 0x01U;
}
