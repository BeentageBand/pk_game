#include <gmock/gmock.h>
#include <iostream>
#include "meta/nullable.hpp"

using namespace meta;
using namespace std;

struct NullableUT
{
  int * i;
  bool is_i_present;
  int add_if_i_present;
};

class GivenNullable : public ::testing::TestWithParam<NullableUT>
{
  public:
  static int i;
  public:
  void SetUp(void)
  {
    GivenNullable::i = 0;
  }
};

static void add_i(int & i);

int GivenNullable::i = 0;

static NullableUT Nullable_UT[]
{
  {nullptr, false, 0},
  {&GivenNullable::i, true, 1},
};

void add_i(int & i)
{
  ++i;
}


TEST(Nullable, of)
{
  int i = 5;

  Nullable<int> ni = Nullable<int>::of(i);

  ASSERT_TRUE(ni.is_present());
  ASSERT_EQ(5, ni.get());
}

TEST(Nullable, empty)
{
  Nullable<int> ni = Nullable<int>::empty();
  ASSERT_FALSE(ni.is_present());
  ASSERT_EQ(nullptr, ni.get_pointer());
}

TEST_P(GivenNullable, of_nullable)
{
  Nullable<int> ni = Nullable<int>::of_nullable(GetParam().i);
  ASSERT_EQ(GetParam().is_i_present, ni.is_present());
}

TEST_P(GivenNullable, if_present)
{
  Nullable<int> ni = Nullable<int>::of_nullable(GetParam().i);
  ni.if_present(add_i);
  ASSERT_EQ(GetParam().is_i_present, ni.is_present());
  ASSERT_EQ(GetParam().add_if_i_present, GivenNullable::i);
}

INSTANTIATE_TEST_SUITE_P(WhenInput, GivenNullable, ::testing::ValuesIn(Nullable_UT));
