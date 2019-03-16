#pragma once
#include <cstdint>

namespace battle {

  class Stats
  {

    public:
    class Builder
    {
      uint16_t atk;
      uint16_t def;
      uint16_t sp_atk;
      uint16_t sp_def;
      uint16_t spd;
      uint16_t agility;
      public:
      Builder(void){}

      inline Builder & with_atk(uint16_t const atk){this->atk = atk; return *this;}
      inline Builder & with_def(uint16_t const def){this->def = def; return * this;}
      inline Builder & with_sp_atk(uint16_t const sp_atk){this->sp_atk = sp_atk; return * this;}
      inline Builder & with_sp_def(uint16_t const sp_def){this->sp_def = sp_def; return * this;}
      inline Builder & with_spd(uint16_t const spd){this->spd = spd; return * this;}
      inline Builder & with_agility(uint16_t const agility){this->agility = agility; return * this;}

      Stats build(void){ return Stats(this->atk, this->def, this->sp_atk, this->sp_def, this->spd, this->agility);}
    };

    private:
      uint16_t atk;
      uint16_t def;
      uint16_t sp_atk;
      uint16_t sp_def;
      uint16_t spd;
      uint16_t agility;

    public:
    static Builder builder(void)
    {
      static Builder builder;
      return builder;
    }

    Stats(uint16_t const atk, uint16_t const def, uint16_t const sp_atk, uint16_t const sp_def, uint16_t const spd,
          uint16_t const agility)
      : atk(atk), def(def), sp_atk(sp_atk), sp_def(sp_def), spd(spd), agility(agility)
    {}
    inline uint16_t get_atk(void){ return this->atk;}
    inline uint16_t get_def(void){ return this->def;}
    inline uint16_t get_sp_atk(void){return this->sp_atk;}
    inline uint16_t get_sp_def(void){return this->sp_def;}
    inline uint16_t get_spd(void){return this->spd;}
    inline uint16_t get_agility(void){return this->agility;}

    inline void set_atk(uint16_t const atk){this->atk = atk;}
    inline void set_def(uint16_t const def){this->def = def;}
    inline void set_sp_atk(uint16_t const sp_atk){this->sp_atk = sp_atk;}
    inline void set_sp_def(uint16_t const sp_def){this->sp_def = sp_def;}
    inline void set_spd(uint16_t const spd){this->spd = spd;}
    inline void set_agility(uint16_t const agility){this->agility = agility;}
  };
} // namespace battle
