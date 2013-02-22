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
//   requires HasLess<T, Iter::value_type>
//   Iter
//   upper_bound(Iter first, Iter last, const T& value);

#include <algorithm-range>
#include <vector-range>
#include <cassert>

#include "test_ranges.h"

template <class Range, class T>
void
test(Range r, const T& value)
{
    Range i = std::upper_bound(r, value);
    for (Range j = r.before(i); !j.empty(); j.pop_front())
	assert(!(value < j.front()));
    for (Range j = i; !j.empty(); j.pop_front()) { 
        assert(value < j.front());
    }
}

template <class Range>
void
test()
{
    const unsigned N = 1000;
    const unsigned M = 10;
    std::vector<int> v(N);
    int x = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        v[i] = x;
        if (++x == M)
            x = 0;
    }
    std::sort(std::make_iter_range(v.begin(), v.end()));
    for (x = 0; x <= M; ++x)
        test(Range(std::make_iter_range(v.data(), v.data()+v.size())), x);
}

int main()
{
    int d[] = {0, 1, 2, 3};
    for (int* e = d; e <= d+4; ++e)
        for (int x = -1; x <= 4; ++x)
            test(std::make_iter_range(d, e), x);

    test<forward_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> > >();
}
