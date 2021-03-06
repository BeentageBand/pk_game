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
      public:

      inline Builder & with_atk(uint16_t const atk){this->atk = atk; return *this;}
      inline Builder & with_def(uint16_t const def){this->def = def; return * this;}
      inline Builder & with_sp_atk(uint16_t const sp_atk){this->sp_atk = sp_atk; return * this;}
      inline Builder & with_sp_def(uint16_t const sp_def){this->sp_def = sp_def; return * this;}
      inline Builder & with_spd(uint16_t const spd){this->spd = spd; return * this;}

      Stats build(void){ return Stats(this->atk, this->def, this->sp_atk, this->sp_def, this->spd);}
    };

    private:
      uint16_t atk;
      uint16_t def;
      uint16_t sp_atk;
      uint16_t sp_def;
      uint16_t spd;

    public:
    static Builder builder(void)
    {
      static Builder builder;
      return builder;
    }

    Stats(uint16_t const atk, uint16_t const def, uint16_t const sp_atk, uint16_t const sp_def, uint16_t const spd)
      : atk(atk), def(def), sp_atk(sp_atk), sp_def(sp_def), spd(spd)
    {}

    inline uint16_t get_atk(void) const { return this->atk;}
    inline uint16_t get_def(void) const { return this->def;}
    inline uint16_t get_sp_atk(void) const {return this->sp_atk;}
    inline uint16_t get_sp_def(void) const {return this->sp_def;}
    inline uint16_t get_spd(void) const {return this->spd;}

    inline void set_atk(uint16_t const atk){this->atk = atk;}
    inline void set_def(uint16_t const def){this->def = def;}
    inline void set_sp_atk(uint16_t const sp_atk){this->sp_atk = sp_atk;}
    inline void set_sp_def(uint16_t const sp_def){this->sp_def = sp_def;}
    inline void set_spd(uint16_t const spd){this->spd = spd;}

    inline bool operator==(Stats const & stats) const
    {
      if (this == &stats) return true;
      return stats.get_atk() == this->get_atk() &&
             stats.get_def() == this->get_def() &&
             stats.get_sp_atk() == this->get_sp_atk() &&
             stats.get_sp_def() == this->get_sp_def() &&
             stats.get_spd() == this->get_spd();
    }
  };
} // namespace battle