#include <algorithm-range>
#include <cassert>

#include <algorithm-range>
#include <cassert>

#include "test_ranges.h"

/*

    requires r and p are subranges of some range c.
    moves the range r to the beginning of p without any additional alterations of element order in c 
    returns the range to which r was moved

*/

template<typename R>  // R is a random access range
R move_range_to(R r, R p) {
  if(r.begin() > p.begin()) return rotate(p.begin_end(r), r);
  else if (r.end() < p.begin()) return rotate(r.begin_begin(p), r.end_begin(p));
  
  return r;
}

int main() {
  int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const unsigned sa = sizeof(ia)/sizeof(ia[0]);

  std::iter_range<int*> r = move_range_to(std::make_iter_range(ia, ia+2), std::make_iter_range(ia+sa, ia+sa));
  assert(r.begin() == ia + 8);
  assert(ia[0] == 2);
  assert(ia[1] == 3);
  assert(ia[2] == 4);
  assert(ia[3] == 5);
  assert(ia[4] == 6);
  assert(ia[5] == 7);
  assert(ia[6] == 8);
  assert(ia[7] == 9);
  assert(ia[8] == 0);
  assert(ia[9] == 1);

  r = move_range_to(std::make_iter_range(ia+5, ia+7), std::make_iter_range(ia+6, ia+sa));
  assert(r.begin() == ia + 5);
  assert(ia[0] == 2);
  assert(ia[1] == 3);
  assert(ia[2] == 4);
  assert(ia[3] == 5);
  assert(ia[4] == 6);
  assert(ia[5] == 7);
  assert(ia[6] == 8);
  assert(ia[7] == 9);
  assert(ia[8] == 0);
  assert(ia[9] == 1);

  r = move_range_to(std::make_iter_range(ia+2, ia+2), std::make_iter_range(ia+6, ia+sa));
  assert(r.begin() == ia + 6);
  assert(ia[0] == 2);
  assert(ia[1] == 3);
  assert(ia[2] == 4);
  assert(ia[3] == 5);
  assert(ia[4] == 6);
  assert(ia[5] == 7);
  assert(ia[6] == 8);
  assert(ia[7] == 9);
  assert(ia[8] == 0);
  assert(ia[9] == 1);

  r = move_range_to(std::make_iter_range(ia+5, ia+7), std::make_iter_range(ia+2, ia+3));
  assert(r.begin() == ia + 4);
  assert(ia[0] == 2);
  assert(ia[1] == 3);
  assert(ia[2] == 7);
  assert(ia[3] == 8);
  assert(ia[4] == 4);
  assert(ia[5] == 5);
  assert(ia[6] == 6);
  assert(ia[7] == 9);
  assert(ia[8] == 0);
  assert(ia[9] == 1);
}
