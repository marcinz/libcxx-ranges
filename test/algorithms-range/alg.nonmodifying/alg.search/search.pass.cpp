//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<ForwardIterator Iter1, ForwardIterator Iter2>
//   requires HasEqualTo<Iter1::value_type, Iter2::value_type>
//   Iter1
//   search(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2);

#include <algorithm-range>
#include <cassert>

#include "test_ranges.h"

template <class Range1, class Range2>
void
test()
{
    int ia[] = {0, 1, 2, 3, 4, 5};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa)),
		       Range2(std::make_iter_range(ia, ia))) 
	   ==
	   Range1(std::make_iter_range(ia, ia+sa)));
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa)),
		       Range2(std::make_iter_range(ia, ia+1)))
	   ==
	   Range1(std::make_iter_range(ia, ia+1)));
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa)),
		       Range2(std::make_iter_range(ia+1, ia+2))) 
	   ==
	   Range1(std::make_iter_range(ia+1, ia+2)));
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa)),
		       Range2(std::make_iter_range(ia+2, ia+2))) 
	   ==
	   Range1(std::make_iter_range(ia, ia+sa)));
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa)),
		       Range2(std::make_iter_range(ia+2, ia+3))) 
	   ==
	   Range1(std::make_iter_range(ia+2, ia+3)));
    assert(std::search(Range1(std::make_iter_range(ia, ia)),
		       Range2(std::make_iter_range(ia+2, ia+3))) 
	   ==
	   Range1(std::make_iter_range(ia, ia)));
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa)),
		       Range2(std::make_iter_range(ia+sa-1, ia+sa))) 
	   ==
	   Range1(std::make_iter_range(ia+sa-1, ia+sa)));
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa)),
		       Range2(std::make_iter_range(ia+sa-3, ia+sa))) 
	   ==
	   Range1(std::make_iter_range(ia+sa-3, ia+sa)));
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa)),
		       Range2(std::make_iter_range(ia, ia+sa))) 
	   ==
	   Range1(std::make_iter_range(ia, ia+sa)));
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa-1)),
		       Range2(std::make_iter_range(ia, ia+sa))) 
	   ==
	   Range1(std::make_iter_range(ia+sa-1, ia+sa-1)));
    assert(std::search(Range1(std::make_iter_range(ia, ia+1)),
		       Range2(std::make_iter_range(ia, ia+sa))) 
	   ==
	   Range1(std::make_iter_range(ia+1, ia+1)));
    int ib[] = {0, 1, 2, 0, 1, 2, 3, 0, 1, 2, 3, 4};
    const unsigned sb = sizeof(ib)/sizeof(ib[0]);
    int ic[] = {1};
    assert(std::search(Range1(std::make_iter_range(ib, ib+sb)),
		       Range2(std::make_iter_range(ic, ic+1))) 
	   ==
	   Range1(std::make_iter_range(ib+1, ib+2)));
    int id[] = {1, 2};
    assert(std::search(Range1(std::make_iter_range(ib, ib+sb)),
		       Range2(std::make_iter_range(id, id+2))) 
	   ==
	   Range1(std::make_iter_range(ib+1, ib+3)));
    int ie[] = {1, 2, 3};
    assert(std::search(Range1(std::make_iter_range(ib, ib+sb)),
		       Range2(std::make_iter_range(ie, ie+3))) 
	   ==
	   Range1(std::make_iter_range(ib+4, ib+7)));
    int ig[] = {1, 2, 3, 4};
    assert(std::search(Range1(std::make_iter_range(ib, ib+sb)),
		       Range2(std::make_iter_range(ig, ig+4))) 
	   ==
	   Range1(std::make_iter_range(ib+8, ib+12)));
    int ih[] = {0, 1, 1, 1, 1, 2, 3, 0, 1, 2, 3, 4};
    const unsigned sh = sizeof(ih)/sizeof(ih[0]);
    int ii[] = {1, 1, 2};
    assert(std::search(Range1(std::make_iter_range(ih, ih+sh)),
		       Range2(std::make_iter_range(ii, ii+3))) 
	   ==
	   Range1(std::make_iter_range(ih+3, ih+6)));
    int ij[] = {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0};
    const unsigned sj = sizeof(ij)/sizeof(ij[0]);
    int ik[] = {0, 0, 0, 0, 1, 1, 1, 1, 0, 0};
    const unsigned sk = sizeof(ik)/sizeof(ik[0]);
    assert(std::search(Range1(std::make_iter_range(ij, ij+sj)),
		       Range2(std::make_iter_range(ik, ik+sk))) 
	   ==
	   Range1(std::make_iter_range(ij+6, ij+6+sk)));
}

int main()
{
    test<forward_range<std::iter_range<const int*> >, 
	 forward_range<std::iter_range<const int*> > >();
    test<forward_range<std::iter_range<const int*> >, 
	 bidirectional_range<std::iter_range<const int*> > >();
    test<forward_range<std::iter_range<const int*> >, 
	 random_access_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, 
	 forward_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, 
	 bidirectional_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, 
	 random_access_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> >, 
	 forward_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> >, 
	 bidirectional_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> >, 
	 random_access_range<std::iter_range<const int*> > >();
}
