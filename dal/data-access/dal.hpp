#pragma once
#include <fstream>
#include <jsoncpp/json/json.h>

namespace dal
{
  class DAL
  {
    std::string const root;
    public:
    DAL(std::string const & root)
      : root(root)
    {}

    virtual ~DAL(void) {}

  };
}
