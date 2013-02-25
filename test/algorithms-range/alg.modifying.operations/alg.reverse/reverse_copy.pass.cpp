//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<BidirectionalRangeator InRange, OutputRangeator<auto, InRange::reference> OutRange>
//   OutRange
//   reverse_copy(InRange r, OutRange result);

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
    OutRange r = std::reverse_copy(InRange(std::make_iter_range(ia, ia)), 
				   OutRange(std::make_single_iter_range(ja)));
    assert(base(r).base() == ja);
    assert(ja[0] == -1);
    r = std::reverse_copy(InRange(std::make_iter_range(ia, ia+sa)), 
			  OutRange(std::make_single_iter_range(ja)));
    assert(ja[0] == 0);

    const int ib[] = {0, 1};
    const unsigned sb = sizeof(ib)/sizeof(ib[0]);
    int jb[sb] = {-1};
    r = std::reverse_copy(InRange(std::make_iter_range(ib, ib+sb)), 
			  OutRange(std::make_single_iter_range(jb)));
    assert(base(r).base() == jb+sb);
    assert(jb[0] == 1);
    assert(jb[1] == 0);

    const int ic[] = {0, 1, 2};
    const unsigned sc = sizeof(ic)/sizeof(ic[0]);
    int jc[sc] = {-1};
    r = std::reverse_copy(InRange(std::make_iter_range(ic, ic+sc)), 
			  OutRange(std::make_single_iter_range(jc)));
    assert(base(r).base() == jc+sc);
    assert(jc[0] == 2);
    assert(jc[1] == 1);
    assert(jc[2] == 0);

    int id[] = {0, 1, 2, 3};
    const unsigned sd = sizeof(id)/sizeof(id[0]);
    int jd[sd] = {-1};
    r = std::reverse_copy(InRange(std::make_iter_range(id, id+sd)), 
			  OutRange(std::make_single_iter_range(jd)));
    assert(base(r).base() == jd+sd);
    assert(jd[0] == 3);
    assert(jd[1] == 2);
    assert(jd[2] == 1);
    assert(jd[3] == 0);
}

int main()
{
    test<bidirectional_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<random_access_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();
}
