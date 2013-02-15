//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<ForwardRangeator Range1, ForwardRangeator Range2>
//   requires HasEqualTo<Range1::value_type, Range2::value_type>
//   Range1
//   search(Range1 first1, Range1 last1, Range2 first2, Range2 last2);

#include <algorithm-range>
#include <cassert>

#include "test_ranges.h"

struct count_equal
{
    static unsigned count;
    template <class T>
    bool operator()(const T& x, const T& y)
        {++count; return x == y;}
};

unsigned count_equal::count = 0;

template <class Range1, class Range2>
void
test()
{
    int ia[] = {0, 1, 2, 3, 4, 5};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    count_equal::count = 0;
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa)), 
		       Range2(std::make_iter_range(ia, ia)), count_equal()) 
	   == 
	   Range1(std::make_iter_range(ia, ia+sa)));
    assert(count_equal::count <= 0);
    count_equal::count = 0;
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa)),
		       Range2(std::make_iter_range(ia, ia+1)), count_equal()) 
	   ==
	   Range1(std::make_iter_range(ia, ia+1)));
    assert(count_equal::count <= sa);
    count_equal::count = 0;
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa)),
		       Range2(std::make_iter_range(ia+1, ia+2)), count_equal()) 
	   ==
	   Range1(std::make_iter_range(ia+1, ia+2)));
    assert(count_equal::count <= sa);
    count_equal::count = 0;
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa)),
		       Range2(std::make_iter_range(ia+2, ia+2)), count_equal()) 
	   ==
	   Range1(std::make_iter_range(ia, ia+sa)));
    assert(count_equal::count <= 0);
    count_equal::count = 0;
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa)),
		       Range2(std::make_iter_range(ia+2, ia+3)), count_equal()) 
	   ==
	   Range1(std::make_iter_range(ia+2, ia+3)));
    assert(count_equal::count <= sa);
    count_equal::count = 0;
    assert(std::search(Range1(std::make_iter_range(ia, ia)),
		       Range2(std::make_iter_range(ia+2, ia+3)), count_equal()) 
	   ==
	   Range1(std::make_iter_range(ia, ia)));
    assert(count_equal::count <= 0);
    count_equal::count = 0;
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa)),
		       Range2(std::make_iter_range(ia+sa-1, ia+sa)), count_equal()) 
	   ==
	   Range1(std::make_iter_range(ia+sa-1, ia+sa)));
    assert(count_equal::count <= sa);
    count_equal::count = 0;
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa)),
		       Range2(std::make_iter_range(ia+sa-3, ia+sa)), count_equal()) 
	   ==
	   Range1(std::make_iter_range(ia+sa-3, ia+sa)));
    assert(count_equal::count <= sa*3);
    count_equal::count = 0;
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa)),
		       Range2(std::make_iter_range(ia, ia+sa)), count_equal()) 
	   ==
	   Range1(std::make_iter_range(ia, ia+sa)));
    assert(count_equal::count <= sa*sa);
    count_equal::count = 0;
    assert(std::search(Range1(std::make_iter_range(ia, ia+sa-1)),
		       Range2(std::make_iter_range(ia, ia+sa)), count_equal()) 
	   ==
	   Range1(std::make_iter_range(ia+sa-1, ia+sa-1)));
    assert(count_equal::count <= (sa-1)*sa);
    count_equal::count = 0;
    assert(std::search(Range1(std::make_iter_range(ia, ia+1)),
		       Range2(std::make_iter_range(ia, ia+sa)), count_equal()) 
	   ==
	   Range1(std::make_iter_range(ia+1, ia+1)));
    assert(count_equal::count <= sa);
    count_equal::count = 0;
    int ib[] = {0, 1, 2, 0, 1, 2, 3, 0, 1, 2, 3, 4};
    const unsigned sb = sizeof(ib)/sizeof(ib[0]);
    int ic[] = {1};
    assert(std::search(Range1(std::make_iter_range(ib, ib+sb)),
		       Range2(std::make_iter_range(ic, ic+1)), count_equal()) 
	   ==
	   Range1(std::make_iter_range(ib+1, ib+2)));
    assert(count_equal::count <= sb);
    count_equal::count = 0;
    int id[] = {1, 2};
    assert(std::search(Range1(std::make_iter_range(ib, ib+sb)),
		       Range2(std::make_iter_range(id, id+2)), count_equal()) 
	   ==
	   Range1(std::make_iter_range(ib+1, ib+3)));
    assert(count_equal::count <= sb*2);
    count_equal::count = 0;
    int ie[] = {1, 2, 3};
    assert(std::search(Range1(std::make_iter_range(ib, ib+sb)),
		       Range2(std::make_iter_range(ie, ie+3)), count_equal()) 
	   ==
	   Range1(std::make_iter_range(ib+4, ib+7)));
    assert(count_equal::count <= sb*3);
    count_equal::count = 0;
    int ig[] = {1, 2, 3, 4};
    assert(std::search(Range1(std::make_iter_range(ib, ib+sb)),
		       Range2(std::make_iter_range(ig, ig+4)), count_equal()) 
	   ==
	   Range1(std::make_iter_range(ib+8, ib+12)));
    assert(count_equal::count <= sb*4);
    count_equal::count = 0;
    int ih[] = {0, 1, 1, 1, 1, 2, 3, 0, 1, 2, 3, 4};
    const unsigned sh = sizeof(ih)/sizeof(ih[0]);
    int ii[] = {1, 1, 2};
    assert(std::search(Range1(std::make_iter_range(ih, ih+sh)),
		       Range2(std::make_iter_range(ii, ii+3)), count_equal()) 
	   ==
	   Range1(std::make_iter_range(ih+3, ih+6)));
    assert(count_equal::count <= sh*3);
}

int main()
{
    test<forward_range<std::iter_range<const int*> >, forward_range<std::iter_range<const int*> > >();
    test<forward_range<std::iter_range<const int*> >, bidirectional_range<std::iter_range<const int*> > >();
    test<forward_range<std::iter_range<const int*> >, random_access_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, forward_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, bidirectional_range<std::iter_range<const int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, random_access_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> >, forward_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> >, bidirectional_range<std::iter_range<const int*> > >();
    test<random_access_range<std::iter_range<const int*> >, random_access_range<std::iter_range<const int*> > >();
}
