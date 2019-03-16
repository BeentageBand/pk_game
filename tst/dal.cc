#include <gmock/gmock.h>
#include <iostream>
#include <string>
#include "data-access/dal.hpp"
#include "data-access/pkm-dal.hpp"

TEST(PkmDAL, get_metadata)
{
  
  dal::DAL dal;

  dal::PkmDAL pkm_dal(dal);

  pkm::Metadata pkm_metadata = pkm_dal.get_metadata("pikachu");

  std::cout << "name : " << pkm_metadata.get_name << std::endl;

  return 0;
}
