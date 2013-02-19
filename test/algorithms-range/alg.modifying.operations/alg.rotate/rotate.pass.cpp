//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<ShuffleIterator Iter>
//   Iter
//   rotate(Iter first, Iter middle, Iter last);

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
    Range r = std::rotate(Range(std::make_iter_range(ia, ia)), Range(std::make_iter_range(ia, ia)));
    assert(base(r).begin() == ia);
    assert(ia[0] == 0);
    r = std::rotate(Range(std::make_iter_range(ia, ia+sa)), Range(std::make_iter_range(ia, ia+sa)));
    assert(base(r).begin() == ia+sa);
    assert(ia[0] == 0);
    r = std::rotate(Range(std::make_iter_range(ia, ia+sa)), Range(std::make_iter_range(ia+sa, ia+sa)));
    assert(base(r).begin() == ia);
    assert(ia[0] == 0);

    int ib[] = {0, 1};
    const unsigned sb = sizeof(ib)/sizeof(ib[0]);
    r = std::rotate(Range(std::make_iter_range(ib, ib+sb)), Range(std::make_iter_range(ib, ib+sb)));
    assert(base(r).begin() == ib+sb);
    assert(ib[0] == 0);
    assert(ib[1] == 1);
    r = std::rotate(Range(std::make_iter_range(ib, ib+sb)), Range(std::make_iter_range(ib+1, ib+sb)));
    assert(base(r).begin() == ib+1);
    assert(ib[0] == 1);
    assert(ib[1] == 0);
    r = std::rotate(Range(std::make_iter_range(ib, ib+sb)), Range(std::make_iter_range(ib+sb, ib+sb)));
    assert(base(r).begin() == ib);
    assert(ib[0] == 1);
    assert(ib[1] == 0);

    int ic[] = {0, 1, 2};
    const unsigned sc = sizeof(ic)/sizeof(ic[0]);
    r = std::rotate(Range(std::make_iter_range(ic, ic+sc)), Range(std::make_iter_range(ic, ic+sc)));
    assert(base(r).begin() == ic+sc);
    assert(ic[0] == 0);
    assert(ic[1] == 1);
    assert(ic[2] == 2);
    r = std::rotate(Range(std::make_iter_range(ic, ic+sc)), Range(std::make_iter_range(ic+1, ic+sc)));
    assert(base(r).begin() == ic+2);
    assert(ic[0] == 1);
    assert(ic[1] == 2);
    assert(ic[2] == 0);
    r = std::rotate(Range(std::make_iter_range(ic, ic+sc)), Range(std::make_iter_range(ic+2, ic+sc)));
    assert(base(r).begin() == ic+1);
    assert(ic[0] == 0);
    assert(ic[1] == 1);
    assert(ic[2] == 2);
    r = std::rotate(Range(std::make_iter_range(ic, ic+sc)), Range(std::make_iter_range(ic+sc, ic+sc)));
    assert(base(r).begin() == ic);
    assert(ic[0] == 0);
    assert(ic[1] == 1);
    assert(ic[2] == 2);

    int id[] = {0, 1, 2, 3};
    const unsigned sd = sizeof(id)/sizeof(id[0]);
    r = std::rotate(Range(std::make_iter_range(id, id+sd)), Range(std::make_iter_range(id, id+sd)));
    assert(base(r).begin() == id+sd);
    assert(id[0] == 0);
    assert(id[1] == 1);
    assert(id[2] == 2);
    assert(id[3] == 3);
    r = std::rotate(Range(std::make_iter_range(id, id+sd)), Range(std::make_iter_range(id+1, id+sd)));
    assert(base(r).begin() == id+3);
    assert(id[0] == 1);
    assert(id[1] == 2);
    assert(id[2] == 3);
    assert(id[3] == 0);
    r = std::rotate(Range(std::make_iter_range(id, id+sd)), Range(std::make_iter_range(id+2, id+sd)));
    assert(base(r).begin() == id+2);
    assert(id[0] == 3);
    assert(id[1] == 0);
    assert(id[2] == 1);
    assert(id[3] == 2);
    r = std::rotate(Range(std::make_iter_range(id, id+sd)), Range(std::make_iter_range(id+3, id+sd)));
    assert(base(r).begin() == id+1);
    assert(id[0] == 2);
    assert(id[1] == 3);
    assert(id[2] == 0);
    assert(id[3] == 1);
    r = std::rotate(Range(std::make_iter_range(id, id+sd)), Range(std::make_iter_range(id+sd, id+sd)));
    assert(base(r).begin() == id);
    assert(id[0] == 2);
    assert(id[1] == 3);
    assert(id[2] == 0);
    assert(id[3] == 1);

    int ie[] = {0, 1, 2, 3, 4};
    const unsigned se = sizeof(ie)/sizeof(ie[0]);
    r = std::rotate(Range(std::make_iter_range(ie, ie+se)), Range(std::make_iter_range(ie, ie+se)));
    assert(base(r).begin() == ie+se);
    assert(ie[0] == 0);
    assert(ie[1] == 1);
    assert(ie[2] == 2);
    assert(ie[3] == 3);
    assert(ie[4] == 4);
    r = std::rotate(Range(std::make_iter_range(ie, ie+se)), Range(std::make_iter_range(ie+1, ie+se)));
    assert(base(r).begin() == ie+4);
    assert(ie[0] == 1);
    assert(ie[1] == 2);
    assert(ie[2] == 3);
    assert(ie[3] == 4);
    assert(ie[4] == 0);
    r = std::rotate(Range(std::make_iter_range(ie, ie+se)), Range(std::make_iter_range(ie+2, ie+se)));
    assert(base(r).begin() == ie+3);
    assert(ie[0] == 3);
    assert(ie[1] == 4);
    assert(ie[2] == 0);
    assert(ie[3] == 1);
    assert(ie[4] == 2);
    r = std::rotate(Range(std::make_iter_range(ie, ie+se)), Range(std::make_iter_range(ie+3, ie+se)));
    assert(base(r).begin() == ie+2);
    assert(ie[0] == 1);
    assert(ie[1] == 2);
    assert(ie[2] == 3);
    assert(ie[3] == 4);
    assert(ie[4] == 0);
    r = std::rotate(Range(std::make_iter_range(ie, ie+se)), Range(std::make_iter_range(ie+4, ie+se)));
    assert(base(r).begin() == ie+1);
    assert(ie[0] == 0);
    assert(ie[1] == 1);
    assert(ie[2] == 2);
    assert(ie[3] == 3);
    assert(ie[4] == 4);
    r = std::rotate(Range(std::make_iter_range(ie, ie+se)), Range(std::make_iter_range(ie+se, ie+se)));
    assert(base(r).begin() == ie);
    assert(ie[0] == 0);
    assert(ie[1] == 1);
    assert(ie[2] == 2);
    assert(ie[3] == 3);
    assert(ie[4] == 4);

    int ig[] = {0, 1, 2, 3, 4, 5};
    const unsigned sg = sizeof(ig)/sizeof(ig[0]);
    r = std::rotate(Range(std::make_iter_range(ig, ig+sg)), Range(std::make_iter_range(ig, ig+sg)));
    assert(base(r).begin() == ig+sg);
    assert(ig[0] == 0);
    assert(ig[1] == 1);
    assert(ig[2] == 2);
    assert(ig[3] == 3);
    assert(ig[4] == 4);
    assert(ig[5] == 5);
    r = std::rotate(Range(std::make_iter_range(ig, ig+sg)), Range(std::make_iter_range(ig+1, ig+sg)));
    assert(base(r).begin() == ig+5);
    assert(ig[0] == 1);
    assert(ig[1] == 2);
    assert(ig[2] == 3);
    assert(ig[3] == 4);
    assert(ig[4] == 5);
    assert(ig[5] == 0);
    r = std::rotate(Range(std::make_iter_range(ig, ig+sg)), Range(std::make_iter_range(ig+2, ig+sg)));
    assert(base(r).begin() == ig+4);
    assert(ig[0] == 3);
    assert(ig[1] == 4);
    assert(ig[2] == 5);
    assert(ig[3] == 0);
    assert(ig[4] == 1);
    assert(ig[5] == 2);
    r = std::rotate(Range(std::make_iter_range(ig, ig+sg)), Range(std::make_iter_range(ig+3, ig+sg)));
    assert(base(r).begin() == ig+3);
    assert(ig[0] == 0);
    assert(ig[1] == 1);
    assert(ig[2] == 2);
    assert(ig[3] == 3);
    assert(ig[4] == 4);
    assert(ig[5] == 5);
    r = std::rotate(Range(std::make_iter_range(ig, ig+sg)), Range(std::make_iter_range(ig+4, ig+sg)));
    assert(base(r).begin() == ig+2);
    assert(ig[0] == 4);
    assert(ig[1] == 5);
    assert(ig[2] == 0);
    assert(ig[3] == 1);
    assert(ig[4] == 2);
    assert(ig[5] == 3);
    r = std::rotate(Range(std::make_iter_range(ig, ig+sg)), Range(std::make_iter_range(ig+5, ig+sg)));
    assert(base(r).begin() == ig+1);
    assert(ig[0] == 3);
    assert(ig[1] == 4);
    assert(ig[2] == 5);
    assert(ig[3] == 0);
    assert(ig[4] == 1);
    assert(ig[5] == 2);
    r = std::rotate(Range(std::make_iter_range(ig, ig+sg)), Range(std::make_iter_range(ig+sg, ig+sg)));
    assert(base(r).begin() == ig);
    assert(ig[0] == 3);
    assert(ig[1] == 4);
    assert(ig[2] == 5);
    assert(ig[3] == 0);
    assert(ig[4] == 1);
    assert(ig[5] == 2);
}

#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES

template <class Range>
void
test1()
{
    std::unique_ptr<int> ia[1];
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    for (int i = 0; i < sa; ++i)
        ia[i].reset(new int(i));
    Range r = std::rotate(Range(std::make_iter_range(ia, ia)), Range(std::make_iter_range(ia, ia)));
    assert(base(r).begin() == ia);
    assert(*ia[0] == 0);
    r = std::rotate(Range(std::make_iter_range(ia, ia+sa)), Range(std::make_iter_range(ia, ia+sa)));
    assert(base(r).begin() == ia+sa);
    assert(*ia[0] == 0);
    r = std::rotate(Range(std::make_iter_range(ia, ia+sa)), Range(std::make_iter_range(ia+sa, ia+sa)));
    assert(base(r).begin() == ia);
    assert(*ia[0] == 0);

    std::unique_ptr<int> ib[2];
    const unsigned sb = sizeof(ib)/sizeof(ib[0]);
    for (int i = 0; i < sb; ++i)
        ib[i].reset(new int(i));
    r = std::rotate(Range(std::make_iter_range(ib, ib+sb)), Range(std::make_iter_range(ib, ib+sb)));
    assert(base(r).begin() == ib+sb);
    assert(*ib[0] == 0);
    assert(*ib[1] == 1);
    r = std::rotate(Range(std::make_iter_range(ib, ib+sb)), Range(std::make_iter_range(ib+1, ib+sb)));
    assert(base(r).begin() == ib+1);
    assert(*ib[0] == 1);
    assert(*ib[1] == 0);
    r = std::rotate(Range(std::make_iter_range(ib, ib+sb)), Range(std::make_iter_range(ib+sb, ib+sb)));
    assert(base(r).begin() == ib);
    assert(*ib[0] == 1);
    assert(*ib[1] == 0);

    std::unique_ptr<int> ic[3];
    const unsigned sc = sizeof(ic)/sizeof(ic[0]);
    for (int i = 0; i < sc; ++i)
        ic[i].reset(new int(i));
    r = std::rotate(Range(std::make_iter_range(ic, ic+sc)), Range(std::make_iter_range(ic, ic+sc)));
    assert(base(r).begin() == ic+sc);
    assert(*ic[0] == 0);
    assert(*ic[1] == 1);
    assert(*ic[2] == 2);
    r = std::rotate(Range(std::make_iter_range(ic, ic+sc)), Range(std::make_iter_range(ic+1, ic+sc)));
    assert(base(r).begin() == ic+2);
    assert(*ic[0] == 1);
    assert(*ic[1] == 2);
    assert(*ic[2] == 0);
    r = std::rotate(Range(std::make_iter_range(ic, ic+sc)), Range(std::make_iter_range(ic+2, ic+sc)));
    assert(base(r).begin() == ic+1);
    assert(*ic[0] == 0);
    assert(*ic[1] == 1);
    assert(*ic[2] == 2);
    r = std::rotate(Range(std::make_iter_range(ic, ic+sc)), Range(std::make_iter_range(ic+sc, ic+sc)));
    assert(base(r).begin() == ic);
    assert(*ic[0] == 0);
    assert(*ic[1] == 1);
    assert(*ic[2] == 2);

    std::unique_ptr<int> id[4];
    const unsigned sd = sizeof(id)/sizeof(id[0]);
    for (int i = 0; i < sd; ++i)
        id[i].reset(new int(i));
    r = std::rotate(Range(std::make_iter_range(id, id+sd)), Range(std::make_iter_range(id, id+sd)));
    assert(base(r).begin() == id+sd);
    assert(*id[0] == 0);
    assert(*id[1] == 1);
    assert(*id[2] == 2);
    assert(*id[3] == 3);
    r = std::rotate(Range(std::make_iter_range(id, id+sd)), Range(std::make_iter_range(id+1, id+sd)));
    assert(base(r).begin() == id+3);
    assert(*id[0] == 1);
    assert(*id[1] == 2);
    assert(*id[2] == 3);
    assert(*id[3] == 0);
    r = std::rotate(Range(std::make_iter_range(id, id+sd)), Range(std::make_iter_range(id+2, id+sd)));
    assert(base(r).begin() == id+2);
    assert(*id[0] == 3);
    assert(*id[1] == 0);
    assert(*id[2] == 1);
    assert(*id[3] == 2);
    r = std::rotate(Range(std::make_iter_range(id, id+sd)), Range(std::make_iter_range(id+3, id+sd)));
    assert(base(r).begin() == id+1);
    assert(*id[0] == 2);
    assert(*id[1] == 3);
    assert(*id[2] == 0);
    assert(*id[3] == 1);
    r = std::rotate(Range(std::make_iter_range(id, id+sd)), Range(std::make_iter_range(id+sd, id+sd)));
    assert(base(r).begin() == id);
    assert(*id[0] == 2);
    assert(*id[1] == 3);
    assert(*id[2] == 0);
    assert(*id[3] == 1);

    std::unique_ptr<int> ie[5];
    const unsigned se = sizeof(ie)/sizeof(ie[0]);
    for (int i = 0; i < se; ++i)
        ie[i].reset(new int(i));
    r = std::rotate(Range(std::make_iter_range(ie, ie+se)), Range(std::make_iter_range(ie, ie+se)));
    assert(base(r).begin() == ie+se);
    assert(*ie[0] == 0);
    assert(*ie[1] == 1);
    assert(*ie[2] == 2);
    assert(*ie[3] == 3);
    assert(*ie[4] == 4);
    r = std::rotate(Range(std::make_iter_range(ie, ie+se)), Range(std::make_iter_range(ie+1, ie+se)));
    assert(base(r).begin() == ie+4);
    assert(*ie[0] == 1);
    assert(*ie[1] == 2);
    assert(*ie[2] == 3);
    assert(*ie[3] == 4);
    assert(*ie[4] == 0);
    r = std::rotate(Range(std::make_iter_range(ie, ie+se)), Range(std::make_iter_range(ie+2, ie+se)));
    assert(base(r).begin() == ie+3);
    assert(*ie[0] == 3);
    assert(*ie[1] == 4);
    assert(*ie[2] == 0);
    assert(*ie[3] == 1);
    assert(*ie[4] == 2);
    r = std::rotate(Range(std::make_iter_range(ie, ie+se)), Range(std::make_iter_range(ie+3, ie+se)));
    assert(base(r).begin() == ie+2);
    assert(*ie[0] == 1);
    assert(*ie[1] == 2);
    assert(*ie[2] == 3);
    assert(*ie[3] == 4);
    assert(*ie[4] == 0);
    r = std::rotate(Range(std::make_iter_range(ie, ie+se)), Range(std::make_iter_range(ie+4, ie+se)));
    assert(base(r).begin() == ie+1);
    assert(*ie[0] == 0);
    assert(*ie[1] == 1);
    assert(*ie[2] == 2);
    assert(*ie[3] == 3);
    assert(*ie[4] == 4);
    r = std::rotate(Range(std::make_iter_range(ie, ie+se)), Range(std::make_iter_range(ie+se, ie+se)));
    assert(base(r).begin() == ie);
    assert(*ie[0] == 0);
    assert(*ie[1] == 1);
    assert(*ie[2] == 2);
    assert(*ie[3] == 3);
    assert(*ie[4] == 4);

    std::unique_ptr<int> ig[6];
    const unsigned sg = sizeof(ig)/sizeof(ig[0]);
    for (int i = 0; i < sg; ++i)
        ig[i].reset(new int(i));
    r = std::rotate(Range(std::make_iter_range(ig, ig+sg)), Range(std::make_iter_range(ig, ig+sg)));
    assert(base(r).begin() == ig+sg);
    assert(*ig[0] == 0);
    assert(*ig[1] == 1);
    assert(*ig[2] == 2);
    assert(*ig[3] == 3);
    assert(*ig[4] == 4);
    assert(*ig[5] == 5);
    r = std::rotate(Range(std::make_iter_range(ig, ig+sg)), Range(std::make_iter_range(ig+1, ig+sg)));
    assert(base(r).begin() == ig+5);
    assert(*ig[0] == 1);
    assert(*ig[1] == 2);
    assert(*ig[2] == 3);
    assert(*ig[3] == 4);
    assert(*ig[4] == 5);
    assert(*ig[5] == 0);
    r = std::rotate(Range(std::make_iter_range(ig, ig+sg)), Range(std::make_iter_range(ig+2, ig+sg)));
    assert(base(r).begin() == ig+4);
    assert(*ig[0] == 3);
    assert(*ig[1] == 4);
    assert(*ig[2] == 5);
    assert(*ig[3] == 0);
    assert(*ig[4] == 1);
    assert(*ig[5] == 2);
    r = std::rotate(Range(std::make_iter_range(ig, ig+sg)), Range(std::make_iter_range(ig+3, ig+sg)));
    assert(base(r).begin() == ig+3);
    assert(*ig[0] == 0);
    assert(*ig[1] == 1);
    assert(*ig[2] == 2);
    assert(*ig[3] == 3);
    assert(*ig[4] == 4);
    assert(*ig[5] == 5);
    r = std::rotate(Range(std::make_iter_range(ig, ig+sg)), Range(std::make_iter_range(ig+4, ig+sg)));
    assert(base(r).begin() == ig+2);
    assert(*ig[0] == 4);
    assert(*ig[1] == 5);
    assert(*ig[2] == 0);
    assert(*ig[3] == 1);
    assert(*ig[4] == 2);
    assert(*ig[5] == 3);
    r = std::rotate(Range(std::make_iter_range(ig, ig+sg)), Range(std::make_iter_range(ig+5, ig+sg)));
    assert(base(r).begin() == ig+1);
    assert(*ig[0] == 3);
    assert(*ig[1] == 4);
    assert(*ig[2] == 5);
    assert(*ig[3] == 0);
    assert(*ig[4] == 1);
    assert(*ig[5] == 2);
    r = std::rotate(Range(std::make_iter_range(ig, ig+sg)), Range(std::make_iter_range(ig+sg, ig+sg)));
    assert(base(r).begin() == ig);
    assert(*ig[0] == 3);
    assert(*ig[1] == 4);
    assert(*ig[2] == 5);
    assert(*ig[3] == 0);
    assert(*ig[4] == 1);
    assert(*ig[5] == 2);
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
