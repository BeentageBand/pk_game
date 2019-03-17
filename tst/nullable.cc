#include <gmock/gmock.h>
#include <iostream>
#include "meta/nullable.hpp"

using namespace meta;
using namespace std;

void print_i(int const i)
{
  cout << "integer" << i << endl;
}

TEST(Nullable, of)
{
  int i = 5;

  Nullable<int> ni = Nullable<int>::of(i);

  ASSERT_TRUE(ni.is_present());
  ASSERT_EQ(5, ni.get();
}

TEST(Nullable, empty)
{
  Nullable<int> ni = Nullable<int>::empty();
  ASSERT_FALSE(ni.is_present());
  ASSERT_EQ(nullptr, ni.get_pointer();
}

TEST(Nullable, of_nullable)
{
  int * i = nullptr;

  Nullable<int> ni = Nullable<int>::of_nullable(i);
  ASSERT_FALSE(ni.is_present());
  ASSERT_EQ(nullptr, ni.get_pointer();
}


