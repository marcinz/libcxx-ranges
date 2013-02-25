//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<InputIterator InIter, class OutIter>
//   requires OutputIterator<OutIter, RvalueOf<InIter::value_type>::type>
//         && EqualityComparable<InIter::value_type>
//         && HasAssign<InIter::value_type, InIter::reference>
//         && Constructible<InIter::value_type, InIter::reference>
//   OutIter
//   unique_copy(InIter first, InIter last, OutIter result);

#include <algorithm-range>
#include <cassert>

#include "test_ranges.h"

template <class InRange, class OutRange>
void
test()
{
    const int ia[] = {0};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    int ja[sa] = {-1};
    OutRange r = std::unique_copy(InRange(std::make_iter_range(ia, ia+sa)), OutRange(std::make_single_iter_range(ja)));
    assert(base(r).base() == ja + sa);
    assert(ja[0] == 0);

    const int ib[] = {0, 1};
    const unsigned sb = sizeof(ib)/sizeof(ib[0]);
    int jb[sb] = {-1};
    r = std::unique_copy(InRange(std::make_iter_range(ib, ib+sb)), OutRange(std::make_single_iter_range(jb)));
    assert(base(r).base() == jb + sb);
    assert(jb[0] == 0);
    assert(jb[1] == 1);

    const int ic[] = {0, 0};
    const unsigned sc = sizeof(ic)/sizeof(ic[0]);
    int jc[sc] = {-1};
    r = std::unique_copy(InRange(std::make_iter_range(ic, ic+sc)), OutRange(std::make_single_iter_range(jc)));
    assert(base(r).base() == jc + 1);
    assert(jc[0] == 0);

    const int id[] = {0, 0, 1};
    const unsigned sd = sizeof(id)/sizeof(id[0]);
    int jd[sd] = {-1};
    r = std::unique_copy(InRange(std::make_iter_range(id, id+sd)), OutRange(std::make_single_iter_range(jd)));
    assert(base(r).base() == jd + 2);
    assert(jd[0] == 0);
    assert(jd[1] == 1);

    const int ie[] = {0, 0, 1, 0};
    const unsigned se = sizeof(ie)/sizeof(ie[0]);
    int je[se] = {-1};
    r = std::unique_copy(InRange(std::make_iter_range(ie, ie+se)), OutRange(std::make_single_iter_range(je)));
    assert(base(r).base() == je + 3);
    assert(je[0] == 0);
    assert(je[1] == 1);
    assert(je[2] == 0);

    const int ig[] = {0, 0, 1, 1};
    const unsigned sg = sizeof(ig)/sizeof(ig[0]);
    int jg[sg] = {-1};
    r = std::unique_copy(InRange(std::make_iter_range(ig, ig+sg)), OutRange(std::make_single_iter_range(jg)));
    assert(base(r).base() == jg + 2);
    assert(jg[0] == 0);
    assert(jg[1] == 1);

    const int ih[] = {0, 1, 1};
    const unsigned sh = sizeof(ih)/sizeof(ih[0]);
    int jh[sh] = {-1};
    r = std::unique_copy(InRange(std::make_iter_range(ih, ih+sh)), OutRange(std::make_single_iter_range(jh)));
    assert(base(r).base() == jh + 2);
    assert(jh[0] == 0);
    assert(jh[1] == 1);

    const int ii[] = {0, 1, 1, 1, 2, 2, 2};
    const unsigned si = sizeof(ii)/sizeof(ii[0]);
    int ji[si] = {-1};
    r = std::unique_copy(InRange(std::make_iter_range(ii, ii+si)), OutRange(std::make_single_iter_range(ji)));
    assert(base(r).base() == ji + 3);
    assert(ji[0] == 0);
    assert(ji[1] == 1);
    assert(ji[2] == 2);
}

int main()
{
    test<input_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<forward_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<bidirectional_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<random_access_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();
}
