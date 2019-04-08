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
        battle::Stats stats;
        public:
        Builder(void)
        : name(), types(), stats(battle::Stats::builder().build())
        {}

        inline Builder & with_name(std::string const & name) {this->name = name; return *this;}
        inline Builder & with_types(std::vector<std::string> const & types) {this->types = types; return *this;}
        inline Builder & with_stats(battle::Stats const & stats) { this->stats = stats; return *this;}

        inline Metadata build(void) 
        {
          return Metadata(this->name, this->types, this->stats);
        }
      };

    static Builder builder(void)
    {
        static Builder builder;
        return builder;
    }

    private:
    std::string name;
    std::vector<std::string> types;
    battle::Stats stats;
    
    public:
    Metadata(std::string const & name, std::vector<std::string> const & types, battle::Stats const & stats)
      :name(name), types(types), stats(stats)
    {}

    inline std::string const & get_name(void) const{return this->name;}
    inline std::vector<std::string> const & get_types(void) const {return this->types;}
    inline battle::Stats const & get_stats(void) const {return this->stats;}

    inline bool operator==(Metadata const & metadata) const
    {
      if(this == &metadata) return true;
      return metadata.get_name() == this->get_name() &&
             metadata.get_stats() == this->get_stats() &&
             metadata.get_types() == this->get_types();
    }
  };
} // namespace pkm
