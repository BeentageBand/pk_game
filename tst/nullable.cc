#include "meta/nullable.hpp"
#include <iostream>

using namespace meta;
using namespace std;

void print_i(int const i) { cout << "integer" << i << endl;}

int main(void)
{
  int i = 5;
  Nullable<int> nullable_i = Nullable<int>::of(i);

  while(i--)
    nullable_i.if_present(print_i);

  Nullable<int> empty_i = Nullable<int>::empty();

  cout << "empty print" << endl;
  empty_i.if_present(print_i);
  ++i;
  print_i(empty_i.or_else(i));

  return 0;
}
