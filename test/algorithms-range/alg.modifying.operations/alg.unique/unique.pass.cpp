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
//   requires OutputIterator<Iter, Iter::reference>
//         && EqualityComparable<Iter::value_type>
//   Iter
//   unique(Iter first, Iter last);

#include <algorithm-range>
#include <cassert>
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
#include <memory>
#endif

#include "test_ranges.h"

template <class Range>
void
test()
{
    int ia[] = {0};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    Range r = std::unique(Range(std::make_iter_range(ia, ia+sa)));
    assert(base(r).begin() == ia + sa);
    assert(ia[0] == 0);

    int ib[] = {0, 1};
    const unsigned sb = sizeof(ib)/sizeof(ib[0]);
    r = std::unique(Range(std::make_iter_range(ib, ib+sb)));
    assert(base(r).begin() == ib + sb);
    assert(ib[0] == 0);
    assert(ib[1] == 1);

    int ic[] = {0, 0};
    const unsigned sc = sizeof(ic)/sizeof(ic[0]);
    r = std::unique(Range(std::make_iter_range(ic, ic+sc)));
    assert(base(r).begin() == ic + 1);
    assert(ic[0] == 0);

    int id[] = {0, 0, 1};
    const unsigned sd = sizeof(id)/sizeof(id[0]);
    r = std::unique(Range(std::make_iter_range(id, id+sd)));
    assert(base(r).begin() == id + 2);
    assert(id[0] == 0);
    assert(id[1] == 1);

    int ie[] = {0, 0, 1, 0};
    const unsigned se = sizeof(ie)/sizeof(ie[0]);
    r = std::unique(Range(std::make_iter_range(ie, ie+se)));
    assert(base(r).begin() == ie + 3);
    assert(ie[0] == 0);
    assert(ie[1] == 1);
    assert(ie[2] == 0);

    int ig[] = {0, 0, 1, 1};
    const unsigned sg = sizeof(ig)/sizeof(ig[0]);
    r = std::unique(Range(std::make_iter_range(ig, ig+sg)));
    assert(base(r).begin() == ig + 2);
    assert(ig[0] == 0);
    assert(ig[1] == 1);

    int ih[] = {0, 1, 1};
    const unsigned sh = sizeof(ih)/sizeof(ih[0]);
    r = std::unique(Range(std::make_iter_range(ih, ih+sh)));
    assert(base(r).begin() == ih + 2);
    assert(ih[0] == 0);
    assert(ih[1] == 1);

    int ii[] = {0, 1, 1, 1, 2, 2, 2};
    const unsigned si = sizeof(ii)/sizeof(ii[0]);
    r = std::unique(Range(std::make_iter_range(ii, ii+si)));
    assert(base(r).begin() == ii + 3);
    assert(ii[0] == 0);
    assert(ii[1] == 1);
    assert(ii[2] == 2);
}

#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES

struct do_nothing
{
    void operator()(void*) const {}
};

typedef std::unique_ptr<int, do_nothing> Ptr;

template <class Range>
void
test1()
{
    int one = 1;
    int two = 2;
    Ptr ia[1];
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    Range r = std::unique(Range(std::make_iter_range(ia, ia+sa)));
    assert(base(r).begin() == ia + sa);
    assert(ia[0] == 0);

    Ptr ib[2];
    ib[1].reset(&one);
    const unsigned sb = sizeof(ib)/sizeof(ib[0]);
    r = std::unique(Range(std::make_iter_range(ib, ib+sb)));
    assert(base(r).begin() == ib + sb);
    assert(ib[0] == 0);
    assert(*ib[1] == 1);

    Ptr ic[2];
    const unsigned sc = sizeof(ic)/sizeof(ic[0]);
    r = std::unique(Range(std::make_iter_range(ic, ic+sc)));
    assert(base(r).begin() == ic + 1);
    assert(ic[0] == 0);

    Ptr id[3];
    id[2].reset(&one);
    const unsigned sd = sizeof(id)/sizeof(id[0]);
    r = std::unique(Range(std::make_iter_range(id, id+sd)));
    assert(base(r).begin() == id + 2);
    assert(id[0] == 0);
    assert(*id[1] == 1);

    Ptr ie[4];
    ie[2].reset(&one);
    const unsigned se = sizeof(ie)/sizeof(ie[0]);
    r = std::unique(Range(std::make_iter_range(ie, ie+se)));
    assert(base(r).begin() == ie + 3);
    assert(ie[0] == 0);
    assert(*ie[1] == 1);
    assert(ie[2] == 0);

    Ptr ig[4];
    ig[2].reset(&one);
    ig[3].reset(&one);
    const unsigned sg = sizeof(ig)/sizeof(ig[0]);
    r = std::unique(Range(std::make_iter_range(ig, ig+sg)));
    assert(base(r).begin() == ig + 2);
    assert(ig[0] == 0);
    assert(*ig[1] == 1);

    Ptr ih[3];
    ih[1].reset(&one);
    ih[2].reset(&one);
    const unsigned sh = sizeof(ih)/sizeof(ih[0]);
    r = std::unique(Range(std::make_iter_range(ih, ih+sh)));
    assert(base(r).begin() == ih + 2);
    assert(ih[0] == 0);
    assert(*ih[1] == 1);

    Ptr ii[7];
    ii[1].reset(&one);
    ii[2].reset(&one);
    ii[3].reset(&one);
    ii[4].reset(&two);
    ii[5].reset(&two);
    ii[6].reset(&two);
    const unsigned si = sizeof(ii)/sizeof(ii[0]);
    r = std::unique(Range(std::make_iter_range(ii, ii+si)));
    assert(base(r).begin() == ii + 3);
    assert(ii[0] == 0);
    assert(*ii[1] == 1);
    assert(*ii[2] == 2);
}

#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES

int main()
{
    test<forward_range<std::iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<int*> > >();
    test<random_access_range<std::iter_range<int*> > >();

#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES

    test1<forward_range<std::iter_range<Ptr*>> >();
    test1<bidirectional_range<std::iter_range<Ptr*>> >();
    test1<random_access_range<std::iter_range<Ptr*>> >();

#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
}
