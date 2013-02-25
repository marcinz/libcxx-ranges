//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<InputIterator InIter1, InputIterator InIter2, class OutIter,
//          Callable<auto, const InIter1::value_type&, const InIter2::value_type&> BinaryOp>
//   requires OutputIterator<OutIter, BinaryOp::result_type> && CopyConstructible<BinaryOp>
// OutIter
// transform(InIter1 first1, InIter1 last1, InIter2 first2, OutIter result, BinaryOp binary_op);

#include <algorithm-range>
#include <functional>
#include <cassert>

#include "test_ranges.h"

template<class InRange1, class InRange2, class OutRange>
void
test()
{
    int ia[] = {0, 1, 2, 3, 4};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    int ib[sa] = {1, 2, 3, 4, 5};
    OutRange r = std::transform(InRange1(std::make_iter_range(ib, ib+sa)), InRange2(std::make_single_iter_range(ia)),
				OutRange(std::make_single_iter_range(ib)), std::minus<int>());
    assert(base(r).base() == ib + sa);
    assert(ib[0] == 1);
    assert(ib[1] == 1);
    assert(ib[2] == 1);
    assert(ib[3] == 1);
    assert(ib[4] == 1);
}

int main()
{
    test<input_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<input_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<input_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<input_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<forward_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<forward_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<forward_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<forward_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<bidirectional_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<bidirectional_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<bidirectional_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<bidirectional_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<random_access_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, input_range<std::single_iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<random_access_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<random_access_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<random_access_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();
}
