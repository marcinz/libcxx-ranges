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
//         && LessThanComparable<Iter::value_type>
//   void
//   sort(Iter first, Iter last);

#include <algorithm-range>
#include <cassert>

template <class RN>
void
test_sort_helper(RN r)
{
    typedef typename std::range_traits<RN>::value_type value_type;
    if (!r.empty())
    {
        long len = r.length();
        value_type* save(new value_type[len]);
        do
        {
	    std::copy(r, std::make_single_iter_range(save));
            std::sort(std::make_iter_range(save, save+len));
            assert(std::is_sorted(std::make_iter_range(save, save+len)));
        } while (std::next_permutation(r));
        delete [] save;
    }
}

template <class RN>
void
test_sort_driver_driver(RN r, int start, RN real_last)
{
    for (RN i = r; i.begin() > (r + start).begin(); i.pop_front())
    {
        i.front() = start;
        if (i.empty())
        {
            test_sort_helper(real_last);
        }
	if (start > 0)
	    test_sort_driver_driver(i, start-1, real_last);
    }
}

template <class RN>
void
test_sort_driver(RN r, int start)
{
    test_sort_driver_driver(r, start, r);
}

template <unsigned sa>
void
test_sort_()
{
    int ia[sa];
    for (int i = 0; i < sa; ++i)
    {
        test_sort_driver(std::make_iter_range(ia, ia+sa), i);
    }
}

void
test_larger_sorts(unsigned N, unsigned M)
{
    assert(N != 0);
    assert(M != 0);
    // create array length N filled with M different numbers
    int* array = new int[N];
    
    int x = 0;
    for (int i = 0; i < N; ++i)
    {
        array[i] = x;
        if (++x == M)
            x = 0;
    }
    // test saw tooth pattern
    std::sort(std::make_iter_range(array, array+N));
    assert(std::is_sorted(std::make_iter_range(array, array+N)));
    // test random pattern
    std::random_shuffle(std::make_iter_range(array, array+N));
    std::sort(std::make_iter_range(array, array+N));
    assert(std::is_sorted(std::make_iter_range(array, array+N)));
    // test sorted pattern
    std::sort(std::make_iter_range(array, array+N));
    assert(std::is_sorted(std::make_iter_range(array, array+N)));
    // test reverse sorted pattern
    std::reverse(std::make_iter_range(array, array+N));
    std::sort(std::make_iter_range(array, array+N));
    assert(std::is_sorted(std::make_iter_range(array, array+N)));
    // test swap ranges 2 pattern
    std::swap_ranges(std::make_iter_range(array, array+N/2), std::make_single_iter_range(array+N/2));
    std::sort(std::make_iter_range(array, array+N));
    assert(std::is_sorted(std::make_iter_range(array, array+N)));
    // test reverse swap ranges 2 pattern
    std::reverse(std::make_iter_range(array, array+N));
    std::swap_ranges(std::make_iter_range(array, array+N/2), std::make_single_iter_range(array+N/2));
    std::sort(std::make_iter_range(array, array+N));
    assert(std::is_sorted(std::make_iter_range(array, array+N)));
    delete [] array;
}

void
test_larger_sorts(unsigned N)
{
    test_larger_sorts(N, 1);
    test_larger_sorts(N, 2);
    test_larger_sorts(N, 3);
    test_larger_sorts(N, N/2-1);
    test_larger_sorts(N, N/2);
    test_larger_sorts(N, N/2+1);
    test_larger_sorts(N, N-2);
    test_larger_sorts(N, N-1);
    test_larger_sorts(N, N);
}

int main()
{
    // test null range
    int d = 0;
    std::sort(std::make_iter_range(&d, &d));
    // exhaustively test all possibilities up to length 8
    test_sort_<1>();
    test_sort_<2>();
    test_sort_<3>();
    test_sort_<4>();
    test_sort_<5>();
    test_sort_<6>();
    test_sort_<7>();
    test_sort_<8>();

    test_larger_sorts(256);
    test_larger_sorts(257);
    test_larger_sorts(499);
    test_larger_sorts(500);
    test_larger_sorts(997);
    test_larger_sorts(1000);
    test_larger_sorts(1009);
}
