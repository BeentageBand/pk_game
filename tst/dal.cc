#include "gmock/gmock.h"
#include <fstream>
#include <iostream>
#include <string>
#include "data-access/dal.hpp"

static std::string filename("dal/data-access/pokedex.json");

TEST(Filename, is_good)
{
  std::ifstream ifs(filename);
  ASSERT_TRUE(ifs.good());
  ifs.close();
}

TEST(DAL, get_json)
{
  dal::DAL dal;
  Json::Value json_root = dal.get_json(filename);

  ASSERT_TRUE(nullptr == json_root);

}
