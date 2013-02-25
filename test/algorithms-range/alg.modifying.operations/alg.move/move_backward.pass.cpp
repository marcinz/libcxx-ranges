//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<BidirectionalIterator InIter, BidirectionalIterator OutIter>
//   requires OutputIterator<OutIter, RvalueOf<InIter::reference>::type>
//   OutIter
//   move_backward(InIter first, InIter last, OutIter result);

#include <algorithm-range>
#include <cassert>
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
#include <memory>
#endif

#include "test_ranges.h"

template <class InRange, class OutRange>
void
test()
{
    const unsigned N = 1000;
    int ia[N];
    for (unsigned i = 0; i < N; ++i)
        ia[i] = i;
    int ib[N] = {0};

    OutRange r = std::move_backward(InRange(std::make_iter_range(ia, ia+N)), OutRange(std::make_single_iter_backward_range(ib+N)));
    assert(base(r).base() == ib);
    for (unsigned i = 0; i < N; ++i)
        assert(ia[i] == ib[i]);
}

#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES

template <class InRange, class OutRange>
void
test1()
{
    const unsigned N = 100;
    std::unique_ptr<int> ia[N];
    for (unsigned i = 0; i < N; ++i)
        ia[i].reset(new int(i));
    std::unique_ptr<int> ib[N];

    OutRange r = std::move_backward(InRange(std::make_iter_range(ia, ia+N)), OutRange(std::make_single_iter_backward_range(ib+N)));
    assert(base(r).base() == ib);
    for (unsigned i = 0; i < N; ++i)
        assert(*ib[i] == i);
}

#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES

int main()
{
    test<bidirectional_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_backward_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, random_access_range<std::single_iter_backward_range<int*> > >();

    test<random_access_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_backward_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, random_access_range<std::single_iter_backward_range<int*> > >();

#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    test1<bidirectional_range<std::iter_range<std::unique_ptr<int>*> >, bidirectional_range<std::single_iter_backward_range<std::unique_ptr<int>*> > >();
    test1<bidirectional_range<std::iter_range<std::unique_ptr<int>*> >, random_access_range<std::single_iter_backward_range<std::unique_ptr<int>*> > >();

    test1<random_access_range<std::iter_range<std::unique_ptr<int>*> >, bidirectional_range<std::single_iter_backward_range<std::unique_ptr<int>*> > >();
    test1<random_access_range<std::iter_range<std::unique_ptr<int>*> >, random_access_range<std::single_iter_backward_range<std::unique_ptr<int>*> > >();
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
}
