//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<ForwardIterator Iter, Callable Generator>
//   requires OutputIterator<Iter, Generator::result_type>
//         && CopyConstructible<Generator>
//   void
//   generate(Iter first, Iter last, Generator gen);

#include <algorithm-range>
#include <cassert>

#include "test_ranges.h"

struct gen_test
{
    int operator()() const {return 1;}
};

template <class Range>
void
test()
{
    const unsigned n = 4;
    int ia[n] = {0};
    std::generate(Range(std::make_iter_range(ia, ia+n)), gen_test());
    assert(ia[0] == 1);
    assert(ia[1] == 1);
    assert(ia[2] == 1);
    assert(ia[3] == 1);
}

int main()
{
    test<forward_range<std::iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<int*> > >();
    test<random_access_range<std::iter_range<int*> > >();
}
