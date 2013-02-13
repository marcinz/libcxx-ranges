// -*- C++ -*-

#ifndef RANGES_H
#define RANGES_H

#include <ranges>

template <class Rg>
class output_range
{
private:
    Rg rg_;
    
    template <class U> friend class output_range;
public:
    typedef std::output_range_tag                                      range_category;
    typedef typename std::range_traits<Rg>::value_type                 value_type;
    typedef typename std::range_traits<Rg>::length_type                length_type;
    typedef typename std::range_traits<Rg>::reference                  reference;
    typedef output_range<typename std::range_traits<Rg>::before_type>  before_type;
    typedef output_range<typename std::range_traits<Rg>::after_type>   after_type;

    Rg base() const {return rg_;}
    
    output_range () : rg_() {}
    explicit output_range(Rg rg) : rg_(rg) {}
    template <class U>
        output_range(const output_range<U>& u) : rg_(u.rg_) {}

    reference front() const {return rg_.front();}
    void pop_front() {rg_.pop_front();}
    bool empty() const {return rg_.empty();}
};

template <class Rg>
class input_range
{
private:
    Rg rg_;
    
    template <class U> friend class input_range;
public:
    typedef std::input_range_tag                                      range_category;
    typedef typename std::range_traits<Rg>::value_type                value_type;
    typedef typename std::range_traits<Rg>::length_type               length_type;
    typedef typename std::range_traits<Rg>::reference                 reference;
    typedef input_range<typename std::range_traits<Rg>::before_type>  before_type;
    typedef input_range<typename std::range_traits<Rg>::after_type>   after_type;

    Rg base() const {return rg_;}

    input_range() : rg_() {}
    explicit input_range(Rg rg) : rg_(rg) {}
    template <class U>
        input_range(const input_range<U>& u) : rg_(u.rg_) {} 
    
    reference front() const {return rg_.front();}
    void pop_front() {rg_.pop_front();}
    bool empty() const {return rg_.empty();}

    friend bool operator==(const input_range& x, const input_range& y)
        {return x.rg_ == y.rg_;}
    friend bool operator!=(const input_range& x, const input_range& y)
        {return !(x == y);}
};

template <class Rg>
class forward_range
{
private:
    Rg rg_;
    
    template <class U> friend class forward_range;
public:
    typedef std::forward_range_tag                                      range_category;
    typedef typename std::range_traits<Rg>::value_type                  value_type;
    typedef typename std::range_traits<Rg>::length_type                 length_type;
    typedef typename std::range_traits<Rg>::reference                   reference;
    typedef forward_range<typename std::range_traits<Rg>::before_type>  before_type;
    typedef forward_range<typename std::range_traits<Rg>::after_type>   after_type;

    Rg base() const {return rg_;}

    forward_range() : rg_() {}
    explicit forward_range(Rg rg) : rg_(rg) {}
    template <class U>
        forward_range(const forward_range<U>& u) : rg_(u.rg_) {} 
    
    reference front() const {return rg_.front();}
    void pop_front() {rg_.pop_front();}
    bool empty() const {return rg_.empty();}
    before_type before(const forward_range& r) const {return rg_.before(r);}
    forward_range before_including(const forward_range& r) const {return rg_.before_including(r);}
    after_type after(const forward_range& r) const {return rg_.after(r);}
    forward_range after_including(const forward_range& r) const {return rg_.after_including(r);}

    friend bool operator==(const forward_range& x, const forward_range& y)
        {return x.rg_ == y.rg_;}
    friend bool operator!=(const forward_range& x, const forward_range& y)
        {return !(x == y);}
};

template <class Rg>
class bidirectional_range
{
private:
    Rg rg_;
    
    template <class U> friend class bidirectional_range;
public:
    typedef std::bidirectional_range_tag                                      range_category;
    typedef typename std::range_traits<Rg>::value_type                        value_type;
    typedef typename std::range_traits<Rg>::length_type                       length_type;
    typedef typename std::range_traits<Rg>::reference                         reference;
    typedef bidirectional_range<typename std::range_traits<Rg>::before_type>  before_type;
    typedef bidirectional_range<typename std::range_traits<Rg>::after_type>   after_type;

    Rg base() const {return rg_;}

    bidirectional_range() : rg_() {}
    explicit bidirectional_range(Rg rg) : rg_(rg) {}
    template <class U>
        bidirectional_range(const bidirectional_range<U>& u) : rg_(u.rg_) {} 
    
    reference front() const {return rg_.front();}
    void pop_front() {rg_.pop_front();}
    reference back() const {return rg_.back();}
    void pop_back() {rg_.pop_back();}
    bool empty() const {return rg_.empty();}
    before_type before(const bidirectional_range& r) const {return rg_.before(r);}
    bidirectional_range before_including(const bidirectional_range& r) const {return rg_.before_including(r);}
    after_type after(const bidirectional_range& r) const {return rg_.after(r);}
    bidirectional_range after_including(const bidirectional_range& r) const {return rg_.after_including(r);}

    friend bool operator==(const bidirectional_range& x, const bidirectional_range& y)
        {return x.rg_ == y.rg_;}
    friend bool operator!=(const bidirectional_range& x, const bidirectional_range& y)
        {return !(x == y);}
};

template <class Rg>
class random_access_range
{
private:
    Rg rg_;
    
    template <class U> friend class random_access_range;
public:
    typedef std::random_access_range_tag                                      range_category;
    typedef typename std::range_traits<Rg>::value_type                        value_type;
    typedef typename std::range_traits<Rg>::length_type                       length_type;
    typedef typename std::range_traits<Rg>::reference                         reference;
    typedef random_access_range<typename std::range_traits<Rg>::before_type>  before_type;
    typedef random_access_range<typename std::range_traits<Rg>::after_type>   after_type;

    Rg base() const {return rg_;}

    random_access_range() : rg_() {}
    explicit random_access_range(Rg rg) : rg_(rg) {}
    template <class U>
        random_access_range(const random_access_range<U>& u) : rg_(u.rg_) {} 
    
    reference front() const {return rg_.front();}
    void pop_front() {rg_.pop_front();}
    reference back() const {return rg_.back();}
    void pop_back() {rg_.pop_back();}
    bool empty() const {return rg_.empty();}
    length_type length() const {return rg_.length();}
    before_type before(const random_access_range& r) const {return before_type(rg_.before(r.base()));}
    random_access_range before_including(const random_access_range& r) const {return rg_.before_including(r);}
    after_type after(const random_access_range& r) const {return rg_.after(r);}
    random_access_range after_including(const random_access_range& r) const {return rg_.after_including(r);}
    random_access_range operator+(length_type n) const 
        {random_access_range tmp(*this); tmp+= n; return tmp;}
    random_access_range& operator+=(length_type n) {rg_ += n; return *this;}
    random_access_range operator-(length_type n) const 
        {random_access_range tmp(*this); tmp-= n; return tmp;}
    random_access_range& operator-=(length_type n) {rg_ += n; return *this;}
    reference operator[](length_type n) const {return rg_[n];}

    friend bool operator==(const random_access_range& x, const random_access_range& y)
        {return x.rg_ == y.rg_;}
    friend bool operator!=(const random_access_range& x, const random_access_range& y)
        {return !(x == y);}
};

template <class Range>
inline output_range<Range> make_output_range(Range r) {return output_range<Range>(r);}

template <class Range>
inline input_range<Range> make_input_range(Range r) {return input_range<Range>(r);}

template <class Range>
inline forward_range<Range> make_forward_range(Range r) {return forward_range<Range>(r);}

template <class Range>
inline bidirectional_range<Range> make_bidirectional_range(Range r) {return bidirectional_range<Range>(r);}

template <class Range>
inline random_access_range<Range> make_random_range(Range r) {return random_access_range<Range>(r);}

template <class Range>
inline Range base(output_range<Range> i) { return i.base(); }

template <class Range>
inline Range base(input_range<Range> i) { return i.base(); }

template <class Range>
inline Range base(forward_range<Range> i) { return i.base(); }

template <class Range>
inline Range base(bidirectional_range<Range> i) { return i.base(); }

template <class Range>
inline Range base(random_access_range<Range> i) { return i.base(); }

#endif // RANGES_H
// Local Variables:
// c-basic-offset: 4
// End:
