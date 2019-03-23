#include "gmock/gmock.h"
#include "dal-mock.hpp"
#include "data-access/pkm-dal.hpp"
#include "pkm/metadata.hpp"

struct PkmDAL_UT
{
  std::string name;
  pkm::Metadata metadata;
};

using namespace ::testing;

TEST(PkmDAL, get_metadata)
{
  NiceMock<DALMock> mock_dal;
  EXPECT_CALL(mock_dal, get_json(_)).WillOnce(Return(Json::nullValue));

  dal::PkmDAL pkm_dal(mock_dal);

  pkm::Metadata metadata = pkm_dal.get_metadata("name");
}
