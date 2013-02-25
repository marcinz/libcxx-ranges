//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<InputIterator InIter, class OutIter,
//          Callable<auto, const InIter::value_type&> Op>
//   requires OutputIterator<OutIter, Op::result_type> && CopyConstructible<Op>
//   OutIter
//   transform(InIter first, InIter last, OutIter result, Op op);

#include <algorithm-range>
#include <functional>
#include <cassert>

#include "test_ranges.h"

template <class InRange, class OutRange>
void
test()
{
    int ia[] = {0, 1, 2, 3, 4};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    int ib[sa] = {0};
    OutRange r = std::transform(InRange(std::make_iter_range(ia, ia+sa)), OutRange(std::make_single_iter_range(ib)),
                               std::bind2nd(std::plus<int>(), 1));
    assert(base(r).base() == ib + sa);
    assert(ib[0] == 1);
    assert(ib[1] == 2);
    assert(ib[2] == 3);
    assert(ib[3] == 4);
    assert(ib[4] == 5);
}

int main()
{
    test<input_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<forward_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<bidirectional_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<random_access_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();
}
