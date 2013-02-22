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
//   min_element(Iter first, Iter last);

#include <algorithm-range>
#include <cassert>

#include "test_ranges.h"

template <class Range>
void
test(Range r)
{
    Range i = std::min_element(r);
    if (!r.empty())
    {
	for (Range j = r; !j.empty(); j.pop_front())
            assert(!(j.front() < i.front()));
    }
    else
        assert(r.empty());
}

template <class Range>
void
test(unsigned N)
{
    int* a = new int[N];
    for (int i = 0; i < N; ++i)
        a[i] = i;
    std::random_shuffle(std::make_iter_range(a, a+N));
    test(Range(std::make_iter_range(a, a+N)));
    delete [] a;
}

template <class Range>
void
test()
{
    test<Range>(0);
    test<Range>(1);
    test<Range>(2);
    test<Range>(3);
    test<Range>(10);
    test<Range>(1000);
}

int main()
{
    test<forward_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> > >();
}
