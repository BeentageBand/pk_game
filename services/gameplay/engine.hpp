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
    virtual std::shared_ptr<Option> build_options(Battle & battle) = 0;
  };
}