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
//   requires OutputIterator<Iter, const T&>
//   void
//   fill(Iter first, Iter last, const T& value);

#include <algorithm-range>
#include <cassert>

#include "test_ranges.h"

template <class Range>
void
test_char()
{
    const unsigned n = 4;
    char ca[n] = {0};
    std::fill(Range(std::make_iter_range((ca), (ca+n))), char(1));
    assert(ca[0] == 1);
    assert(ca[1] == 1);
    assert(ca[2] == 1);
    assert(ca[3] == 1);
}

template <class Range>
void
test_int()
{
    const unsigned n = 4;
    int ia[n] = {0};
    std::fill(Range(std::make_iter_range((ia), (ia+n))), 1);
    assert(ia[0] == 1);
    assert(ia[1] == 1);
    assert(ia[2] == 1);
    assert(ia[3] == 1);
}

int main()
{
    test_char<forward_range<std::iter_range<char*> > >();
    test_char<bidirectional_range<std::iter_range<char*> > >();
    test_char<random_access_range<std::iter_range<char*> > >();

    test_int<forward_range<std::iter_range<int*> > >();
    test_int<bidirectional_range<std::iter_range<int*> > >();
    test_int<random_access_range<std::iter_range<int*> > >();
}
