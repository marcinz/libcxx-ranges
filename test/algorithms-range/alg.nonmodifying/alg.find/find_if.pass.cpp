//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<InputIterator Iter, Predicate<auto, Iter::value_type> Pred>
//   requires CopyConstructible<Pred>
//   Iter
//   find_if(Iter first, Iter last, Pred pred);

#include <algorithm-range>
#include <functional>
#include <cassert>

#include "test_iterators.h"
#include "test_ranges.h"

int main()
{
    int ia[] = {0, 1, 2, 3, 4, 5};
    const unsigned s = sizeof(ia)/sizeof(ia[0]);
    forward_range<std::iter_range<input_iterator<const int*> > > r = 
	std::find_if(make_forward_range(std::make_iter_range(
			 input_iterator<const int*>(ia),
			 input_iterator<const int*>(ia+s))),
		     std::bind2nd(std::equal_to<int>(), 3));
    assert(r.front() == 3);
    r = std::find_if(make_forward_range(std::make_iter_range(
			 input_iterator<const int*>(ia),
			 input_iterator<const int*>(ia+s))),
                     std::bind2nd(std::equal_to<int>(), 10));
    assert(r.base().begin() == input_iterator<const int*>(ia+s));
}
