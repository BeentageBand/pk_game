#pragma once

namespace gameplay
{
  class Battle;
  class Command
  {
    public:
    virtual ~Command(void){}
    virtual void execute(Battle & battle) {};
  };
}
