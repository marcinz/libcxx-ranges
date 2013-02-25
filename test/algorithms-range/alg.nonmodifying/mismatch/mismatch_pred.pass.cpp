//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<InputIterator Iter1, InputIterator Iter2,
//          Predicate<auto, Iter1::value_type, Iter2::value_type> Pred>
//   requires CopyConstructible<Pred>
//   pair<Iter1, Iter2>
//   mismatch(Iter1 first1, Iter1 last1, Iter2 first2, Pred pred);

#include <algorithm-range>
#include <functional>
#include <cassert>

#include "test_ranges.h"

int main()
{
    int ia[] = {0, 1, 2, 2, 0, 1, 2, 3};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    int ib[] = {0, 1, 2, 3, 0, 1, 2, 3};
    assert(std::mismatch(make_input_range(std::iter_range<const int*>(ia, ia + sa)),
                         make_input_range(std::single_iter_range<const int*>(ib)),
                         std::equal_to<int>()) ==
                         (std::pair<input_range<std::iter_range<const int*> >,
	    input_range<std::single_iter_range<const int*> > >
	    (make_input_range(std::iter_range<const int*>(ia+3, ia+sa)),
	     make_input_range(std::single_iter_range<const int*>(ib+3)))));
}
