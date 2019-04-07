#pragma once
#include <cstdint>
#include <string>
#include <vector>

namespace pkm
{
  class Attributes
  {
    public:
    class Builder
    {
      public:
      std::string nickname;
      uint8_t level;
      std::vector<std::string> moveset;

      inline Builder & with_nickname(std::string const & nickname) {this->nickname = nickname; return *this;}
      inline Builder & with_level(uint8_t const level) {this->level = level; return *this;}
      inline Builder & with_moveset(std::vector<std::string> const & moveset) {this->moveset = moveset; return *this;}

      Attributes build(void)
      {
        return Attributes(this->nickname, this->level, this->moveset);
      }
    };

    std::string nickname;
    uint8_t level;
    std::vector<std::string> moveset;
    
    public:
    Attributes(std::string const & nickname, uint8_t const level, std::vector<std::string> const & moveset)
      : nickname(nickname), level(level), moveset()
    {
      if(moveset.size() > 4)
      {
        this->moveset.assign(moveset.begin(), moveset.begin() + 4);
      }
      else
      {
        this->moveset.assign(moveset.begin(), moveset.end());
      }
    }

    static Builder builder(void)
    {
      static Builder builder;
      return builder;
    }

    inline std::string const & get_nickname(void) {return this->nickname;}
    inline uint8_t get_level(void) { return this->level;}
    inline std::string const & get_move(uint8_t const i)
    {
      if(this->moveset.size() > i)
      {
        return this->moveset[i];
      }
      else
      {
        static std::string empty;
        return empty;
      }
    }
  };
}