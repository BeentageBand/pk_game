#pragma once
#include <string>
#include "pokemon_team.hpp"

namespace pkm {
  class Trainer
  {
    public:
      class Builder
      {
        std::string name;
        PokemonTeam pokemon_team;
        Builder(void){}

        friend class Trainer;
        public:
        inline void with_name(std::string const & name) {this->name = name;}
        inline void with_pokemon_team(PokemonTeam & pokemon_team) {this->pokemon_team = pokemon_team;}
        inline Trainer  build(void){ return Trainer(this->name, this->pokemon_team);}
      };

    private:
    std::string const name;
    PokemonTeam * pokemon_team;

    public:
    Trainer(std::string const & name, PokemonTeam & pokemon_team)
      : name(name), pokemon_team(&pokemon_team)
    {}

    static Builder builder(void)
    {
      static Builder builder;
      return builder;
    }

    inline std::string const & get_name(void) {return this->name;}
    inline PokemonTeam & get_pokemon_team(void) {return *this->pokemon_team;}
  };
} // namespace pkm
