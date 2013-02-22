//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<BidirectionalIterator Iter, StrictWeakOrder<auto, Iter::value_type> Compare>
//   requires ShuffleIterator<Iter>
//         && CopyConstructible<Compare>
//   bool
//   prev_permutation(Iter first, Iter last, Compare comp);

#include <algorithm-range>
#include <functional>
#include <cassert>

#include "test_ranges.h"

#include <cstdio>

int factorial(int x)
{
    int r = 1;
    for (; x; --x)
        r *= x;
    return r;
}

template <class Range>
void
test()
{
    typedef std::greater<int> C;
    int ia[] = {1, 2, 3, 4, 5, 6};
    const int sa = sizeof(ia)/sizeof(ia[0]);
    int prev[sa];
    for (int e = 0; e <= sa; ++e)
    {
        int count = 0;
        bool x;
        do
        {
            std::copy(std::make_iter_range(ia, ia+e), std::make_single_iter_range(prev));
            x = std::prev_permutation(Range(std::make_iter_range(ia, ia+e)), C());
            if (e > 1)
            {
                if (x)
		    assert(std::lexicographical_compare(std::make_iter_range(ia, ia+e), std::make_iter_range(prev, prev+e), C()));
                else
                    assert(std::lexicographical_compare(std::make_iter_range(prev, prev+e), std::make_iter_range(ia, ia+e), C()));
            }
            ++count;
        } while (x);
        assert(count == factorial(e));
    }
}

int main()
{
    test<bidirectional_range<std::iter_range<int*> > >();
    test<random_access_range<std::iter_range<int*> > >();
}
