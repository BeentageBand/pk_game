#pragma once
#include <string>
#include <vector>
#include "battle/stats.hpp"

namespace pkm {
  class Metadata 
  {
    public:
      class Builder
      {
        std::string name;
        std::vector<std::string> types;
        battle::Stats const * stats;
        public:
        Builder(void) {}

        inline Builder & with_name(std::string const & name) {this->name = name; return *this;}
        inline Builder & with_stats(battle::Stats const & stats) {this->stats = &stats; return *this;}
        inline Builder & with_types(std::vector<std::string> const & types) {this->types = types; return *this;}
        inline Metadata build(void) {return Metadata(this->name, this->types, *this->stats);}
      };
    private:
    std::string const name;
    std::vector<std::string> const types;
    battle::Stats stats;
    
    public:
    Metadata(std::string const & name, std::vector<std::string> const & types, battle::Stats const & stats)
      :name(name), types(types), stats(stats)
    {}

    inline std::string const & get_name(void){return this->name;}
    inline std::vector<std::string> const & get_types(void) {return this->types;}
    inline battle::Stats const & get_stats(void) {return this->stats;}
  };
} // namespace pkm
