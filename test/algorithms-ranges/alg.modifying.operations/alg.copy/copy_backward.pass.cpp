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
//   requires OutputIterator<OutIter, InIter::reference>
//   OutIter
//   copy_backward(InIter first, InIter last, OutIter result);

#include <algorithm-range>
#include <cassert>

#include "test_iterators.h"
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

    InRange irg(std::make_iter_range(ia, ia+N));
    OutRange org(std::make_single_iter_backward_range(ib+N-1));

    OutRange r = std::copy_backward(irg, org);
    assert(base(r).base() == ib-1);
    for (unsigned i = 0; i < N; ++i)
        assert(ia[i] == ib[i]);
}

int main()
{
    test<bidirectional_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_backward_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, random_access_range<std::single_iter_backward_range<int*> >  >();

    test<random_access_range<std::iter_range<int*> >, bidirectional_range<std::single_iter_backward_range<int*> > >();
    test<random_access_range<std::iter_range<int*> >, random_access_range<std::single_iter_backward_range<int*> >  >();
}
