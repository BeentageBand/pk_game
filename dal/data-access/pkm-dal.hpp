#pragma once
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
      std::shared_ptr<pkm::Metadata> pkm_metadata = this->lru.get(name);
      
      if(pkm_metadata) return pkm_metadata;

      Json::Value json = this->dal->get_json(this->JSON_FILE);

      Json::Value json_metadata = json[name];

      if(nullptr == json_metadata) return pkm_metadata;

      pkm::Metadata::Builder builder = pkm::Metadata::builder();

      if(nullptr == jsom_metadata["attack"]) builder.with_atk(json_metadata["attack"].asInt());
      if(nullptr == jsom_metadata["defense"]) builder.with_atk(json_metadata["defense"].asInt());
      if(nullptr == jsom_metadata["sp_atk"]) builder.with_atk(json_metadata["sp_atk"].asInt());
      if(nullptr == jsom_metadata["sp_def"]) builder.with_atk(json_metadata["sp_def"].asInt());
      if(nullptr == jsom_metadata["spd"]) builder.with_atk(json_metadata["spd"].asInt());

      pkm_metadata.reset(new pkm::Metadata(builder.build()));
      this->lru.put(name, pkm_metadata);

      return pkm_metadata;
    }
  };
}
