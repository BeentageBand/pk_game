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
    
    std::shared_ptr<pkm::Metadata> get_metadata(std::string const & name)
    {
      std::shared_ptr<pkm::Metadata> pkm_metadata = this->lru.get(name);
      
      if(pkm_metadata) return pkm_metadata;
      //else...

      Json::Value json = this->dal->get_json(this->JSON_FILE);

      Json::Value json_metadata = json[name];

      if(nullptr == json_metadata) return pkm_metadata; //no metadata, not found

      pkm::Metadata::Builder builder = pkm::Metadata::builder();

      builder.with_

      pkm_metadata.reset(new pkm::Metadata(builder.build()));
      this->lru.put(name, pkm_metadata);

      return pkm_metadata;
    }
  };
}
