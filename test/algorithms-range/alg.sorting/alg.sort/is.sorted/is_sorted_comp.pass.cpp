//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<ForwardIterator Iter, StrictWeakOrder<auto, Iter::value_type> Compare>
//   requires CopyConstructible<Compare>
//   bool
//   is_sorted(Iter first, Iter last, Compare comp);

#include <algorithm-range>
#include <functional>
#include <cassert>

#include "test_ranges.h"

template <class Range>
void
test()
{
    {
    int a[] = {0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Range(std::make_iter_range(a, a))));
    assert(std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }

    {
    int a[] = {0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }

    {
    int a[] = {0, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {0, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {0, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {0, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {1, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {1, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {1, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {1, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }

    {
    int a[] = {0, 0, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {0, 0, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {0, 0, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {0, 0, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {0, 1, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {0, 1, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {0, 1, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {0, 1, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {1, 0, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {1, 0, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {1, 0, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {1, 0, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {1, 1, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {1, 1, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(!std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {1, 1, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
    {
    int a[] = {1, 1, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted(Range(std::make_iter_range(a, a+sa)), std::greater<int>()));
    }
}

int main()
{
    test<forward_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> > >();
}
