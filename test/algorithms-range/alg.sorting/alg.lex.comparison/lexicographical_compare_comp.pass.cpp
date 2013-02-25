//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<InputIterator Iter1, InputIterator Iter2, CopyConstructible Compare>
//   requires Predicate<Compare, Iter1::value_type, Iter2::value_type>
//         && Predicate<Compare, Iter2::value_type, Iter1::value_type>
//   bool
//   lexicographical_compare(Iter1 first1, Iter1 last1,
//                           Iter2 first2, Iter2 last2, Compare comp);

#include <algorithm-range>
#include <functional>
#include <cassert>

#include "test_ranges.h"

template <class Range1, class Range2>
void
test()
{
    int ia[] = {1, 2, 3, 4};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    int ib[] = {1, 2, 3};
    typedef std::greater<int> C;
    C c;
    assert(!std::lexicographical_compare(Range1(std::make_iter_range(ia, ia+sa)), Range2(std::make_iter_range(ib, ib+2)), c));
    assert(std::lexicographical_compare(Range1(std::make_iter_range(ib, ib+2)), Range2(std::make_iter_range(ia, ia+sa)), c));
    assert(!std::lexicographical_compare(Range1(std::make_iter_range(ia, ia+sa)), Range2(std::make_iter_range(ib, ib+3)), c));
    assert(std::lexicographical_compare(Range1(std::make_iter_range(ib, ib+3)), Range2(std::make_iter_range(ia, ia+sa)), c));
    assert(!std::lexicographical_compare(Range1(std::make_iter_range(ia, ia+sa)), Range2(std::make_iter_range(ib+1, ib+3)), c));
    assert(std::lexicographical_compare(Range1(std::make_iter_range(ib+1, ib+3)), Range2(std::make_iter_range(ia, ia+sa)), c));
}

int main()
{
    test<input_range<std::iter_range<const int*> >, input_range<std::iter_range<const int*> > >();
    test<input_range<std::iter_range<const int*> >, forward_range<std::iter_range<const int*> > >();
    test<input_range<std::iter_range<const int*> >, bidirectional_range<std::iter_range<const int*> > >();
    test<input_range<std::iter_range<const int*> >, random_access_range<std::iter_range<const int*> > >();

    test<forward_range<std::iter_range<const int*> >, input_range<std::iter_range<const int*> > >();
    test<forward_range<std::iter_range<const int*> >, forward_range<std::iter_range<const int*> > >();
    test<forward_range<std::iter_range<const int*> >, bidirectional_range<std::iter_range<const int*> > >();
    test<forward_range<std::iter_range<const int*> >, random_access_range<std::iter_range<const int*> > >();

    test<bidirectional_range<std::iter_range<const int*> >, input_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, forward_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, bidirectional_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, random_access_range<std::iter_range<const int*> > >();

    test<random_access_range<std::iter_range<const int*> >, input_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> >, forward_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> >, bidirectional_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> >, random_access_range<std::iter_range<const int*> > >();
}
