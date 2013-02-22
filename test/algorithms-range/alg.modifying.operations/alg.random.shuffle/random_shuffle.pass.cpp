//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<RandomAccessIterator Iter>
//   requires ShuffleIterator<Iter>
//   void
//   random_shuffle(Iter first, Iter last);

#include <algorithm-range>
#include <cassert>

int main()
{
    int ia[] = {1, 2, 3, 4};
    int ia1[] = {1, 4, 3, 2};
    int ia2[] = {4, 1, 2, 3};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    std::random_shuffle(std::make_iter_range(ia, ia+sa));
    assert(std::equal(std::make_iter_range(ia, ia+sa), std::make_single_iter_range(ia1)));
    std::random_shuffle(std::make_iter_range(ia, ia+sa));
    assert(std::equal(std::make_iter_range(ia, ia+sa), std::make_single_iter_range(ia2)));
}
