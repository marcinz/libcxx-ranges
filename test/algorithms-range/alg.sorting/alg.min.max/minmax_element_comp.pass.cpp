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
//   pair<Iter, Iter>
//   minmax_element(Iter first, Iter last, Compare comp);

#include <algorithm-range>
#include <functional>
#include <cassert>

#include "test_ranges.h"

template <class Range>
void
test(Range r)
{
    typedef std::greater<int> Compare;
    Compare comp;
    std::pair<Range, Range> p = std::minmax_element(r, comp);
    if (!r.empty())
    {
      for (Range j = r; !j.empty(); j.pop_front())
        {
	    assert(!comp(j.front(), p.first.front()));
            assert(!comp(p.second.front(), j.front()));
        }
    }
    else
    {
        assert(p.first.empty());
        assert(p.second.empty());
    }
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
    {
    const unsigned N = 100;
    int* a = new int[N];
    for (int i = 0; i < N; ++i)
        a[i] = 5;
    std::random_shuffle(std::make_iter_range(a, a+N));
    typedef std::greater<int> Compare;
    Compare comp;
    std::pair<Range, Range> p = std::minmax_element(Range(std::make_iter_range(a, a+N)), comp);
    assert(base(p.first).begin() == a);
    assert(base(p.second).begin() == a+N-1);
    delete [] a;
    }
}

int main()
{
    test<forward_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> > >();
}
