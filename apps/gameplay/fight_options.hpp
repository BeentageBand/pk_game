#pragma once
#include <iostream>
#include <memory>
#include <set>
#include "move_command.hpp"
#include "option.hpp"
#include "pkm/pokemon.hpp"
#include "pkm/trainer.hpp"

namespace gameplay
{
    class FightOptions : public Option
    {
      public:
      FightOptions(void)
        : Option("Fight")
      {}
      
      void display(pkm::Pokemon & pokemon, std::set<std::string> & moveset)
      {
        for(uint8_t i = 0; i < 4; ++i)
        {
          std::cout << pokemon.get_moveset()[i]<< " " << pokemon.get_pp()[i] << std::endl;
          moveset.insert(pokemon.get_moveset()[i]);
        }
      }

      std::shared_ptr<Command> build(pkm::Trainer & trainer) 
      {
        std::set<std::string>  moveset;
        std::shared_ptr<Command> command;

        pkm::Pokemon & pokemon = trainer.get_pokemon_team().get_pokemon(0);

        do{

          this->display(pokemon, moveset);
          std::string input;
          std::cin >> input;

          auto found_move = moveset.find(input);

          if(found_move != moveset.end())
          {
            command.reset(new MoveCommand(found_move, pokemon));
            return command;
          }
          
        } while(true);
      }
    };
}
