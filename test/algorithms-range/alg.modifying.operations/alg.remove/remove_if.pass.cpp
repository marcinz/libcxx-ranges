//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<ForwardIterator Iter, Predicate<auto, Iter::value_type> Pred>
//   requires OutputIterator<Iter, RvalueOf<Iter::reference>::type>
//         && CopyConstructible<Pred>
//   Iter
//   remove_if(Iter first, Iter last, Pred pred);

#include <algorithm-range>
#include <functional>
#include <cassert>
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
#include <memory>
#endif

#include "test_ranges.h"

template <class Range>
void
test()
{
    int ia[] = {0, 1, 2, 3, 4, 2, 3, 4, 2};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    Range r = std::remove_if(Range(std::make_iter_range(ia, ia+sa)), std::bind2nd(std::equal_to<int>(), 2));
    assert(base(r).begin() == ia + sa-3);
    assert(ia[0] == 0);
    assert(ia[1] == 1);
    assert(ia[2] == 3);
    assert(ia[3] == 4);
    assert(ia[4] == 3);
    assert(ia[5] == 4);
}

#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES

struct pred
{
    bool operator()(const std::unique_ptr<int>& i) {return *i == 2;}
};

template <class Range>
void
test1()
{
    const unsigned sa = 9;
    std::unique_ptr<int> ia[sa];
    ia[0].reset(new int(0));
    ia[1].reset(new int(1));
    ia[2].reset(new int(2));
    ia[3].reset(new int(3));
    ia[4].reset(new int(4));
    ia[5].reset(new int(2));
    ia[6].reset(new int(3));
    ia[7].reset(new int(4));
    ia[8].reset(new int(2));
    Range r = std::remove_if(Range(std::make_iter_range(ia, ia+sa)), pred());
    assert(base(r).begin() == ia + sa-3);
    assert(*ia[0] == 0);
    assert(*ia[1] == 1);
    assert(*ia[2] == 3);
    assert(*ia[3] == 4);
    assert(*ia[4] == 3);
    assert(*ia[5] == 4);
}

#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES

int main()
{
    test<forward_range<std::iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<int*> > >();
    test<random_access_range<std::iter_range<int*> > >();

#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES

    test1<forward_range<std::iter_range<std::unique_ptr<int>*> > >();
    test1<bidirectional_range<std::iter_range<std::unique_ptr<int>*> > >();
    test1<random_access_range<std::iter_range<std::unique_ptr<int>*> > >();

#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
}
