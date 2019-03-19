#pragma once
#include <fstream>
#include <string>
#include "json/json.h"

namespace dal
{
  class DAL
  {

    public:
    DAL(void)
    {}

    virtual ~DAL(void) {}

    Json::Value get_json(std::string const & filename)
    {
      std::ifstream ifs;
      ifs.open(filename, std::fstream::in);
      Json::Value json;
      ifs >> json;
      ifs.close();
      return json;
    }

    void put_json(Json::Value const & json, std::string const & filename)
    {
      std::ofstream ofs;
      ofs.open(filename, std::ofstream::out | std::ofstream::app);
      ofs << json;
      ofs.close();
    }
  };
}
