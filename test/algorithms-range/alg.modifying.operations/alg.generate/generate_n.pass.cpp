//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<class Iter, IntegralLike Size, Callable Generator>
//   requires OutputIterator<Iter, Generator::result_type>
//         && CopyConstructible<Generator>
//   void
//   generate_n(Iter first, Size n, Generator gen);

#include <algorithm-range>
#include <cassert>

#include "test_ranges.h"

struct gen_test
{
    int operator()() const {return 2;}
};

template <class Range>
void
test()
{
    const unsigned n = 4;
    int ia[n] = {0};
    assert(std::generate_n(Range(std::make_single_iter_range(ia)), n, gen_test()) == Range(std::make_single_iter_range(ia+n)));
    assert(ia[0] == 2);
    assert(ia[1] == 2);
    assert(ia[2] == 2);
    assert(ia[3] == 2);
}

int main()
{
    test<forward_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::single_iter_range<int*> > >();
}
