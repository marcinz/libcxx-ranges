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
//   requires HasSwap<Iter1::reference, Iter2::reference>
//   Iter2
//   swap_ranges(Iter1 first1, Iter1 last1, Iter2 first2);

#include <algorithm-range>
#include <cassert>
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
#include <memory>
#endif

#include "test_ranges.h"

template<class Range1, class Range2>
void
test()
{
    int i[3] = {1, 2, 3};
    int j[3] = {4, 5, 6};
    Range2 r = std::swap_ranges(Range1(std::make_iter_range(i, i+3)), Range2(std::make_single_iter_range(j)));
    assert(base(r).base() == j+3);
    assert(i[0] == 4);
    assert(i[1] == 5);
    assert(i[2] == 6);
    assert(j[0] == 1);
    assert(j[1] == 2);
    assert(j[2] == 3);
}

#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES

template<class Range1, class Range2>
void
test1()
{
    std::unique_ptr<int> i[3];
    for (int k = 0; k < 3; ++k)
        i[k].reset(new int(k+1));
    std::unique_ptr<int> j[3];
    for (int k = 0; k < 3; ++k)
        j[k].reset(new int(k+4));
    Range2 r = std::swap_ranges(Range1(std::make_iter_range(i, i+3)), Range2(std::make_single_iter_range(j)));
    assert(base(r).base() == j+3);
    assert(*i[0] == 4);
    assert(*i[1] == 5);
    assert(*i[2] == 6);
    assert(*j[0] == 1);
    assert(*j[1] == 2);
    assert(*j[2] == 3);
}

#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES

int main()
{
    test<forward_range<std::iter_range<int*> >, forward_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<bidirectional_range<std::iter_range<int*> >, forward_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<random_access_range<std::iter_range<int*> >, forward_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<int*> >, random_access_range<std::single_iter_range<int*> > >();

#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES

    test1<forward_range<std::iter_range<std::unique_ptr<int>*> >, forward_range<std::single_iter_range<std::unique_ptr<int>*> > >();
    test1<forward_range<std::iter_range<std::unique_ptr<int>*> >, bidirectional_range<std::single_iter_range<std::unique_ptr<int>*> > >();
    test1<forward_range<std::iter_range<std::unique_ptr<int>*> >, random_access_range<std::single_iter_range<std::unique_ptr<int>*> > >();

    test1<bidirectional_range<std::iter_range<std::unique_ptr<int>*> >, forward_range<std::single_iter_range<std::unique_ptr<int>*> > >();
    test1<bidirectional_range<std::iter_range<std::unique_ptr<int>*> >, bidirectional_range<std::single_iter_range<std::unique_ptr<int>*> > >();
    test1<bidirectional_range<std::iter_range<std::unique_ptr<int>*> >, random_access_range<std::single_iter_range<std::unique_ptr<int>*> > >();

    test1<random_access_range<std::iter_range<std::unique_ptr<int>*> >, forward_range<std::single_iter_range<std::unique_ptr<int>*> > >();
    test1<random_access_range<std::iter_range<std::unique_ptr<int>*> >, bidirectional_range<std::single_iter_range<std::unique_ptr<int>*> > >();
    test1<random_access_range<std::iter_range<std::unique_ptr<int>*> >, random_access_range<std::single_iter_range<std::unique_ptr<int>*> > >();

#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
}
