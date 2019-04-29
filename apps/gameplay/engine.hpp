#pragma once
#include <memory>

namespace gameplay
{
  class Option;
  class Battle;

  class Engine
  {
    public:
    virtual ~Engine(void) {}
    virtual Option && build_options(Battle & battle) = 0;
    virtual Decider && build_decider(void) = 0;
  };
}
