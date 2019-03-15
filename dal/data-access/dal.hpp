#pragma once
#include <fstream>

namespace dal
{
  class DAL
  {
    std::string const root;
    public:
    DAL(std::string const & root)
      : root(root)
    {}

  };
}
