#include "gmock/gmock.h"
#include "meta/lru.hpp"


TEST(LRU, put_int)
{
  meta::LRU<int, int> lru(5);
  lru.put(5, 5);
  lru.put(5, 5);
  lru.put(25, 25);

  meta::Nullable<int> result = lru.get(5);
  ASSERT_TRUE(result.is_present());
  ASSERT_EQ(5, result.get());
}

TEST(LRU, put_string)
{
  meta::LRU<std::string, std::string> lru(5);
  lru.put("pikachu", "raichu");
  lru.put("eevee","umbreon");
  lru.put("pikachu", "raichu");

  meta::Nullable<std::string> result = lru.get("eevee");
  ASSERT_TRUE(result.is_present());
  ASSERT_TRUE("umbreon" == result.get());
}
