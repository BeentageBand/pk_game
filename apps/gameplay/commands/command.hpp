#pragma once

namespace gameplay::Command
{
  class Battle;

  namespace commands {

      class Command
      {
        public:
        virtual ~Command(void){}
        virtual void execute(Battle & battle) {};
      };
  } // namespace commands
}
