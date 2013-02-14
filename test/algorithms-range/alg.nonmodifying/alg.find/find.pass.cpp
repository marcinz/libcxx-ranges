//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<InputIterator Iter, class T>
//   requires HasEqualTo<Iter::value_type, T>
//   Iter
//   find(Iter first, Iter last, const T& value);

#include <algorithm-range>
#include <cassert>

#include "test_iterators.h"
#include "test_ranges.h"

int main()
{
    int ia[] = {0, 1, 2, 3, 4, 5};
    const unsigned s = sizeof(ia)/sizeof(ia[0]);
    forward_range<std::iter_range<input_iterator<const int*> > > r = 
        std::find(make_forward_range(std::make_iter_range(
                      input_iterator<const int*>(ia),
                      input_iterator<const int*>(ia+s))),
		  3);
    assert(r.front() == 3);
    r = std::find(make_forward_range(std::make_iter_range(
		      input_iterator<const int*>(ia), 
		      input_iterator<const int*>(ia+s))), 
		  10);
    assert(r.base().begin() == input_iterator<const int*>(ia+s));
}
