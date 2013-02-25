//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<InputIterator InIter, OutputIterator<auto, InIter::reference> OutIter, class T>
//   requires HasEqualTo<InIter::value_type, T>
//   OutIter
//   remove_copy(InIter first, InIter last, OutIter result, const T& value);

#include <algorithm-range>
#include <cassert>

#include "test_ranges.h"

template <class InRange, class OutRange>
void
test()
{
    int ia[] = {0, 1, 2, 3, 4, 2, 3, 4, 2};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    int ib[sa];
    OutRange r = std::remove_copy(InRange(std::make_iter_range(ia, ia+sa)), OutRange(std::make_single_iter_range(ib)), 2);
    assert(base(r).base() == ib + sa-3);
    assert(ib[0] == 0);
    assert(ib[1] == 1);
    assert(ib[2] == 3);
    assert(ib[3] == 4);
    assert(ib[4] == 3);
    assert(ib[5] == 4);
}

int main()
{
    test<input_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<forward_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<bidirectional_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<random_access_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();
}
