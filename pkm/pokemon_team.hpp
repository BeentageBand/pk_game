#pragma once
#include <algorithm>
#include <cstdint>
#include <deque>
#include "pokemon.hpp"
#include "meta/nullable.hpp"

namespace pkm {
  class PokemonTeam
  {
    enum {MAX_PARTY = 6};
    std::deque<Pokemon *> team;

    public:
    void push_pokemon(Pokemon & pokemon)
    {
      if((MAX_PARTY > this->team.size()) 
          && (this->team.end() == std::find(this->team.begin(), this->team.end(), &pokemon)))
        this->team.push_back(&pokemon);
    }

    inline Pokemon & at(uint8_t const i) { return (i < this->team.size())? *this->team.at(i) : *this->team.at(this->team.size() -1); }

    void switch_first(uint8_t const i)
    {
      Pokemon & pokemon = *this->team.at(i);
      this->team.erase(this->team.begin() + i);
      this->team.push_front(pokemon);
    }
  };
  
} // namespace pkm
