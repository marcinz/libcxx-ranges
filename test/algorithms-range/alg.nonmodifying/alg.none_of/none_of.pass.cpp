//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template <class InputIterator, class Predicate>
//   bool
//   none_of(InputIterator first, InputIterator last, Predicate pred);

#include <algorithm-range>
#include <cassert>

#include "test_ranges.h"

struct test1
{
    bool operator()(const int& i) const
    {
        return i % 2 == 0;
    }
};

int main()
{
    {
        int ia[] = {2, 4, 6, 8};
        const unsigned sa = sizeof(ia)/sizeof(ia[0]);
        assert(std::none_of(make_input_range(std::make_iter_range(ia, ia+sa)), test1()) == false);
        assert(std::none_of(make_input_range(std::make_iter_range(ia, ia)), test1()) == true);
    }
    {
        const int ia[] = {2, 4, 5, 8};
        const unsigned sa = sizeof(ia)/sizeof(ia[0]);
        assert(std::none_of(make_input_range(std::make_iter_range(ia, ia+sa)), test1()) == false);
        assert(std::none_of(make_input_range(std::make_iter_range(ia, ia)), test1()) == true);
    }
    {
        const int ia[] = {1, 3, 5, 7};
        const unsigned sa = sizeof(ia)/sizeof(ia[0]);
        assert(std::none_of(make_input_range(std::make_iter_range(ia, ia+sa)), test1()) == true);
        assert(std::none_of(make_input_range(std::make_iter_range(ia, ia)), test1()) == true);
    }
}
