//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<ForwardIterator Iter, class T>
//   requires OutputIterator<Iter, Iter::reference>
//         && OutputIterator<Iter, const T&>
//         && HasEqualTo<Iter::value_type, T>
//   void
//   replace(Iter first, Iter last, const T& old_value, const T& new_value);

#include <algorithm-range>
#include <cassert>

#include "test_ranges.h"

template <class Range>
void
test()
{
    int ia[] = {0, 1, 2, 3, 4};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    std::replace(Range(std::make_iter_range(ia, ia+sa)), 2, 5);
    assert(ia[0] == 0);
    assert(ia[1] == 1);
    assert(ia[2] == 5);
    assert(ia[3] == 3);
    assert(ia[4] == 4);
}

int main()
{
    test<forward_range<std::iter_range<int*>> >();
    test<bidirectional_range<std::iter_range<int*>> >();
    test<random_access_range<std::iter_range<int*>> >();
}
