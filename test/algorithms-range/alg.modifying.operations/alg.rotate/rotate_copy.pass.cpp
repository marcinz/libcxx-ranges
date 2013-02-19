//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<ForwardIterator InIter, OutputIterator<auto, InIter::reference> OutIter>
//   OutIter
//   rotate_copy(InIter first, InIter middle, InIter last, OutIter result);

#include <algorithm-range>
#include <cassert>

#include "test_ranges.h"

template <class InRange, class OutRange>
void
test()
{
    int ia[] = {0, 1, 2, 3};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    int ib[sa] = {0};

    OutRange r = std::rotate_copy(InRange(std::make_iter_range(ia, ia)), InRange(std::make_iter_range(ia, ia)), OutRange(std::make_single_iter_range(ib)));
    assert(base(r).base() == ib);

    r = std::rotate_copy(InRange(std::make_iter_range(ia, ia+1)), InRange(std::make_iter_range(ia, ia+1)), OutRange(std::make_single_iter_range(ib)));
    assert(base(r).base() == ib+1);
    assert(ib[0] == 0);

    r = std::rotate_copy(InRange(std::make_iter_range(ia, ia+1)), InRange(std::make_iter_range(ia+1, ia+1)), OutRange(std::make_single_iter_range(ib)));
    assert(base(r).base() == ib+1);
    assert(ib[0] == 0);

    r = std::rotate_copy(InRange(std::make_iter_range(ia, ia+2)), InRange(std::make_iter_range(ia, ia+2)), OutRange(std::make_single_iter_range(ib)));
    assert(base(r).base() == ib+2);
    assert(ib[0] == 0);
    assert(ib[1] == 1);

    r = std::rotate_copy(InRange(std::make_iter_range(ia, ia+2)), InRange(std::make_iter_range(ia+1, ia+2)), OutRange(std::make_single_iter_range(ib)));
    assert(base(r).base() == ib+2);
    assert(ib[0] == 1);
    assert(ib[1] == 0);

    r = std::rotate_copy(InRange(std::make_iter_range(ia, ia+2)), InRange(std::make_iter_range(ia+2, ia+2)), OutRange(std::make_single_iter_range(ib)));
    assert(base(r).base() == ib+2);
    assert(ib[0] == 0);
    assert(ib[1] == 1);

    r = std::rotate_copy(InRange(std::make_iter_range(ia, ia+3)), InRange(std::make_iter_range(ia, ia+3)), OutRange(std::make_single_iter_range(ib)));
    assert(base(r).base() == ib+3);
    assert(ib[0] == 0);
    assert(ib[1] == 1);
    assert(ib[2] == 2);

    r = std::rotate_copy(InRange(std::make_iter_range(ia, ia+3)), InRange(std::make_iter_range(ia+1, ia+3)), OutRange(std::make_single_iter_range(ib)));
    assert(base(r).base() == ib+3);
    assert(ib[0] == 1);
    assert(ib[1] == 2);
    assert(ib[2] == 0);

    r = std::rotate_copy(InRange(std::make_iter_range(ia, ia+3)), InRange(std::make_iter_range(ia+2, ia+3)), OutRange(std::make_single_iter_range(ib)));
    assert(base(r).base() == ib+3);
    assert(ib[0] == 2);
    assert(ib[1] == 0);
    assert(ib[2] == 1);

    r = std::rotate_copy(InRange(std::make_iter_range(ia, ia+3)), InRange(std::make_iter_range(ia+3, ia+3)), OutRange(std::make_single_iter_range(ib)));
    assert(base(r).base() == ib+3);
    assert(ib[0] == 0);
    assert(ib[1] == 1);
    assert(ib[2] == 2);

    r = std::rotate_copy(InRange(std::make_iter_range(ia, ia+4)), InRange(std::make_iter_range(ia, ia+4)), OutRange(std::make_single_iter_range(ib)));
    assert(base(r).base() == ib+4);
    assert(ib[0] == 0);
    assert(ib[1] == 1);
    assert(ib[2] == 2);
    assert(ib[3] == 3);

    r = std::rotate_copy(InRange(std::make_iter_range(ia, ia+4)), InRange(std::make_iter_range(ia+1, ia+4)), OutRange(std::make_single_iter_range(ib)));
    assert(base(r).base() == ib+4);
    assert(ib[0] == 1);
    assert(ib[1] == 2);
    assert(ib[2] == 3);
    assert(ib[3] == 0);

    r = std::rotate_copy(InRange(std::make_iter_range(ia, ia+4)), InRange(std::make_iter_range(ia+2, ia+4)), OutRange(std::make_single_iter_range(ib)));
    assert(base(r).base() == ib+4);
    assert(ib[0] == 2);
    assert(ib[1] == 3);
    assert(ib[2] == 0);
    assert(ib[3] == 1);

    r = std::rotate_copy(InRange(std::make_iter_range(ia, ia+4)), InRange(std::make_iter_range(ia+3, ia+4)), OutRange(std::make_single_iter_range(ib)));
    assert(base(r).base() == ib+4);
    assert(ib[0] == 3);
    assert(ib[1] == 0);
    assert(ib[2] == 1);
    assert(ib[3] == 2);

    r = std::rotate_copy(InRange(std::make_iter_range(ia, ia+4)), InRange(std::make_iter_range(ia+4, ia+4)), OutRange(std::make_single_iter_range(ib)));
    assert(base(r).base() == ib+4);
    assert(ib[0] == 0);
    assert(ib[1] == 1);
    assert(ib[2] == 2);
    assert(ib[3] == 3);
}

int main()
{
    test<bidirectional_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<random_access_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<std::iter_range<const int*> , output_range<std::single_iter_range<int*> > >();
    test<std::iter_range<const int*> , forward_range<std::single_iter_range<int*> > >();
    test<std::iter_range<const int*> , bidirectional_range<std::single_iter_range<int*> > >();
    test<std::iter_range<const int*> , random_access_range<std::single_iter_range<int*> > >();
}
