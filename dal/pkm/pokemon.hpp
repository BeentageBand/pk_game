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
      Attributes const * attributes;
      battle::Stats const * stats;
      Metadata const * metadata;
      private:
      Builder(void)
      {}

      friend class Pokemon;
      public:
      inline Builder & with_attributes(Attributes const & attributes) { this->attributes = &attributes; return *this;}
      inline Builder & with_stats(battle::Stats const & stats) { this->stats = &stats; return *this;}
      inline Builder & with_metadata(Metadata const & metadata) { this->metadata = &metadata; return *this;}
      inline Pokemon build(void){return Pokemon(*this->attributes, *this->stats, *this->metadata);}
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

    inline Attributes & get_attributes(void) { return this->attributes;}
    inline battle::Stats && get_stats(void) { return this->stats;}
    inline Metadata && get_metadata(void) { return this->metadata;}
  };
}
