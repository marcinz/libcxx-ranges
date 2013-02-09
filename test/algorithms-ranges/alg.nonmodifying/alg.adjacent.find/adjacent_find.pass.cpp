//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<ForwardIterator Iter>
//   requires EqualityComparable<Iter::value_type>
//   Iter
//   adjacent_find(Iter first, Iter last);

#include <algorithm-range>
#include <cassert>

#include "test_iterators.h"
#include "test_ranges.h"

int main()
{
    int ia[] = {0, 1, 2, 2, 0, 1, 2, 3};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    assert(std::adjacent_find(make_forward_range(std::make_iter_range(
			          forward_iterator<const int*>(ia),
				  forward_iterator<const int*>(ia + sa)))) ==
	                      make_forward_range(std::make_iter_range(
				  forward_iterator<const int*>(ia+2),
				  forward_iterator<const int*>(ia + sa))));
    assert(std::adjacent_find(make_forward_range(std::make_iter_range(
                                  forward_iterator<const int*>(ia),
				  forward_iterator<const int*>(ia)))) ==
	                      make_forward_range(std::make_iter_range(
				  forward_iterator<const int*>(ia),
				  forward_iterator<const int*>(ia))));
    assert(std::adjacent_find(make_forward_range(std::make_iter_range(
				  forward_iterator<const int*>(ia+3),
				  forward_iterator<const int*>(ia + sa)))) ==
	                      make_forward_range(std::make_iter_range(
				  forward_iterator<const int*>(ia+sa),
				  forward_iterator<const int*>(ia + sa))));
}
