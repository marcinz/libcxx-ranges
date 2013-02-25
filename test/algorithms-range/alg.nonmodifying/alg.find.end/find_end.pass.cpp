//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<ForwardIterator Iter1, ForwardIterator Iter2>
//   requires HasEqualTo<Iter1::value_type, Iter2::value_type>
//   Iter1
//   find_end(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2);

#include <algorithm-range>
#include <cassert>

#include "test_ranges.h"

template <class Range1, class Range2>
void
test()
{
    int ia[] = {0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 0, 1, 2, 3, 0, 1, 2, 0, 1, 0};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    int b[] = {0};
    assert(std::find_end(Range1(std::make_iter_range(ia, ia+sa)), Range2(std::make_iter_range(b, b+1))) == Range1(std::make_iter_range(ia+sa-1, ia+sa)));
    int c[] = {0, 1};
    assert(std::find_end(Range1(std::make_iter_range(ia, ia+sa)), Range2(std::make_iter_range(c, c+2))) == Range1(std::make_iter_range(ia+18, ia+sa)));
    int d[] = {0, 1, 2};
    assert(std::find_end(Range1(std::make_iter_range(ia, ia+sa)), Range2(std::make_iter_range(d, d+3))) == Range1(std::make_iter_range(ia+15, ia+sa)));
    int e[] = {0, 1, 2, 3};
    assert(std::find_end(Range1(std::make_iter_range(ia, ia+sa)), Range2(std::make_iter_range(e, e+4))) == Range1(std::make_iter_range(ia+11, ia+sa)));
    int f[] = {0, 1, 2, 3, 4};
    assert(std::find_end(Range1(std::make_iter_range(ia, ia+sa)), Range2(std::make_iter_range(f, f+5))) == Range1(std::make_iter_range(ia+6, ia+sa)));
    int g[] = {0, 1, 2, 3, 4, 5};
    assert(std::find_end(Range1(std::make_iter_range(ia, ia+sa)), Range2(std::make_iter_range(g, g+6))) == Range1(std::make_iter_range(ia, ia+sa)));
    int h[] = {0, 1, 2, 3, 4, 5, 6};
    assert(std::find_end(Range1(std::make_iter_range(ia, ia+sa)), Range2(std::make_iter_range(h, h+7))) == Range1(std::make_iter_range(ia+sa, ia+sa)));
    assert(std::find_end(Range1(std::make_iter_range(ia, ia+sa)), Range2(std::make_iter_range(b, b))) == Range1(std::make_iter_range(ia+sa, ia+sa)));
    assert(std::find_end(Range1(std::make_iter_range(ia, ia)), Range2(std::make_iter_range(b, b+1))) == Range1(std::make_iter_range(ia, ia)));
}

int main()
{
    test<forward_range<std::iter_range<const int*> >, forward_range<std::iter_range<const int*> > >();
    test<forward_range<std::iter_range<const int*> >, bidirectional_range<std::iter_range<const int*> > >();
    test<forward_range<std::iter_range<const int*> >, random_access_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, forward_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, bidirectional_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, random_access_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> >, forward_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> >, bidirectional_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> >, random_access_range<std::iter_range<const int*> > >();
}
