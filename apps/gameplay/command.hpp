#pragma once

namespace gameplay
{
  class Battle;
  class Command
  {
    public:
    class DoNothing
    {
      public:
      ~DoNothing(void){}
      void execute(Battle & battle) {}

    };
    public:
    virtual ~Command(void){}
    virtual void execute(Battle & battle) {};
  };
}
