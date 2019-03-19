#pragma once
#include <memory>

#include "dal.hpp"
#include "meta/lru.hpp"
#include "pkm/metadata.hpp"

namespace dal
{
  class PkmDAL
  {
    int const LRU_SIZE = 50;
    std::string const JSON_FILE = "pokedex.json"
    DAL * dal;
    meta::LRU<pkm::Metadata> lru;

    public:
    PkmDAL(DAL & dal)
      : dal(&dal), lru(LRU_SIZE)
    {}
    
    pkm::Metadata get_metadata(std::string const & name)
    {
      meta::Nullable<pkm::Metadata> cached_metadata = this->lru.get(name);
      if(cached_metadata.if_present())
        return cached_metadata.get();

      Json::Value json_pokedex = this->dal->get_json(this->JSON_FILE);
      Json::Value json_metadata = json_pokedex[name];

      pkm::Metadata::Builder builder = pkm::Metadata::builder();

      builder.with_name(name);

      std::vector<std::string> pkm_types;
      Json::Value json_types = json_metadata["types"];

      for(int i = 0; i < json_types.size(); ++i)
        pkm_types.push_back(json_types[i])

      builder.with_types(pkm_types);

      battle::Stats battle_stats = this->get_battle_stats(name, json_pokedex);
      builder.with_stats(battle_stats);

      pkm::Metadata pkm_metadata =  builder.build();
      this->lru.put(name, pkm_metadata);

      return pkm_metadata;
    }


    battle::Stats get_battle_stats(std::string const & name, Json::Value & json = this->dal->get_json(this->JSON_FILE))
    {
      meta::Nullable<pkm::Metadata> cached_metadata = this->lru.get(name);
      if(cached_metadata.is_present())
        return cached_metadata.get().get_battle_stats();

      battle::Stats::Builder builder = battle::Stats::builder();

      Json::Value json_pokedex = this->dal->get_json(this->JSON_FILE);
      Json::Value json_metadata = json_pokedex[name];
      Json::Value json_stats = json_metadata["stats"];

      builder.with_atk(json_stats["atk"].asInt());
      builder.with_def(json_stats["def"].asInt());
      builder.with_spd(json_stats["spd"].asInt());
      builder.with_sp_atk(json_stats["sp_atk"].asInt());
      builder.with_sp_def(json_stats["sp_def"].asInt());
      return builder.build();
    }
  }; 
}
