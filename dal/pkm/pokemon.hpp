#pragma once
#include "attributes.hpp"
#include "metadata.hpp"
#include "battle/stats.hpp"

namespace pkm 
{
  class Pokemon
  {
    public:
    class Builder
    {
      Attributes attributes;
      battle::Stats stats;
      Metadata metadata;

    public:
      Builder(void)
    : attributes(Attributes::builder().build()),
	  stats(battle::Stats::builder().build()),
	  metadata(Metadata::builder().build())
    {}

      inline Builder & with_attributes(Attributes const & attributes) { this->attributes = attributes; return *this;}
      inline Builder & with_stats(battle::Stats const & stats) { this->stats = stats; return *this;}
      inline Builder & with_metadata(Metadata const & metadata) { this->metadata = metadata; return *this;}
      inline Pokemon build(void){return Pokemon(this->attributes, this->stats, this->metadata);}
    };

    private:
    Attributes attributes;
    battle::Stats stats;
    Metadata metadata;

    public:
    Pokemon(Attributes const & attributes, battle::Stats const & stats, Metadata const & metadata)
      : attributes(attributes), stats(stats), metadata(metadata)
    {}

    static Builder builder(void)
    {
      static Builder builder;
      return builder;
    }

    inline Attributes const & get_attributes(void) const { return this->attributes;}
    inline battle::Stats const & get_stats(void) const { return this->stats;}
    inline Metadata const & get_metadata(void) const { return this->metadata;}

    inline bool operator==(Pokemon const & pokemon) const
    {
      if(this == &pokemon) return true;
      return pokemon.get_attributes() == this->get_attributes() &&
             pokemon.get_metadata() == this->get_metadata() &&
             pokemon.get_stats() == this->get_stats();
    }
  };
}
