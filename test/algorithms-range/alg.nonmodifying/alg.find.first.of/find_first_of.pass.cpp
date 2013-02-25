//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<InputIterator Iter1, ForwardIterator Iter2>
//   requires HasEqualTo<Iter1::value_type, Iter2::value_type>
//   Iter1
//   find_first_of(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2);

#include <algorithm-range>
#include <cassert>

#include "test_ranges.h"

int main()
{
    int ia[] = {0, 1, 2, 3, 0, 1, 2, 3};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    int ib[] = {1, 3, 5, 7};
    const unsigned sb = sizeof(ib)/sizeof(ib[0]);
    assert(std::find_first_of(make_input_range(std::make_iter_range(ia, ia + sa)),
                              make_forward_range(std::make_iter_range(ib, ib + sb))) ==
	   make_input_range(std::make_iter_range(ia+1, ia + sa)));
    int ic[] = {7};
    assert(std::find_first_of(make_input_range(std::make_iter_range(ia, ia + sa)),
                              make_forward_range(std::make_iter_range(ic,ic + 1))) ==
	   make_input_range(std::make_iter_range(ia+sa, ia+sa)));
    assert(std::find_first_of(make_input_range(std::make_iter_range(ia, ia + sa)),
                              make_forward_range(std::make_iter_range(ic, ic))) ==
	   make_input_range(std::make_iter_range(ia+sa, ia+sa)));
    assert(std::find_first_of(make_input_range(std::make_iter_range(ia,ia)),
                              make_forward_range(std::make_iter_range(ic, ic+1))) ==
	   make_input_range(std::make_iter_range(ia, ia)));
}
