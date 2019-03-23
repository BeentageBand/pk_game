#include "gmock/gmock.h"
#include "data-access/dal.hpp"

class DALMock : public dal::DAL
{
  public:
  MOCK_METHOD1(get_json, Json::Value (std::string const &));
  MOCK_METHOD2(put_json, void (Json::Value, std::string const &));
};
