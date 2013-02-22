//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<ForwardIterator Iter>
//   requires LessThanComparable<Iter::value_type>
//   Iter
//   is_sorted_until(Iter first, Iter last);

#include <algorithm-range>
#include <cassert>

#include "test_ranges.h"

template <class Range>
void
test()
{
    {
    int a[] = {0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a))) == Range(std::make_iter_range(a, a)));
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+sa, a+sa)));
    }

    {
    int a[] = {0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+sa, a+sa)));
    }
    {
    int a[] = {0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+sa, a+sa)));
    }
    {
    int a[] = {1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+1, a+sa)));
    }
    {
    int a[] = {1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+sa, a+sa)));
    }

    {
    int a[] = {0, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+sa, a+sa)));
    }
    {
    int a[] = {0, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+sa, a+sa)));
    }
    {
    int a[] = {0, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+2, a+sa)));
    }
    {
    int a[] = {0, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+sa, a+sa)));
    }
    {
    int a[] = {1, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+1, a+sa)));
    }
    {
    int a[] = {1, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+1, a+sa)));
    }
    {
    int a[] = {1, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+2, a+sa)));
    }
    {
    int a[] = {1, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+sa, a+sa)));
    }

    {
    int a[] = {0, 0, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+sa, a+sa)));
    }
    {
    int a[] = {0, 0, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+sa, a+sa)));
    }
    {
    int a[] = {0, 0, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+3, a+sa)));
    }
    {
    int a[] = {0, 0, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+sa, a+sa)));
    }
    {
    int a[] = {0, 1, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+2, a+sa)));
    }
    {
    int a[] = {0, 1, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+2, a+sa)));
    }
    {
    int a[] = {0, 1, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+3, a+sa)));
    }
    {
    int a[] = {0, 1, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+sa, a+sa)));
    }
    {
    int a[] = {1, 0, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+1, a+sa)));
    }
    {
    int a[] = {1, 0, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+1, a+sa)));
    }
    {
    int a[] = {1, 0, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+1, a+sa)));
    }
    {
    int a[] = {1, 0, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+1, a+sa)));
    }
    {
    int a[] = {1, 1, 0, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+2, a+sa)));
    }
    {
    int a[] = {1, 1, 0, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+2, a+sa)));
    }
    {
    int a[] = {1, 1, 1, 0};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+3, a+sa)));
    }
    {
    int a[] = {1, 1, 1, 1};
    unsigned sa = sizeof(a) / sizeof(a[0]);
    assert(std::is_sorted_until(Range(std::make_iter_range(a, a+sa))) == Range(std::make_iter_range(a+sa, a+sa)));
    }
}

int main()
{
    test<forward_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> > >();
}
