// -*- C++ -*-

#ifndef RANGES_H
#define RANGES_H

#include <range>
#include <type_traits>

// All of the following range "prototypes" could be augmented by unbounded versions, which would prohibit certain operations not valid for an unbound range.

template <class Rg>
class output_range
{
private:
    Rg rg_;
    
    template <class U> friend class output_range;
    
    class assigner {
    private:
	Rg r;
    public:
	assigner(const Rg r) : r(r) {}
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
	template<typename T>
	void operator=(T&& v) {r.front() = std::forward<T>(v);}
#else
	template<typename T>
	void operator=(const T& v) {r.front() = v;}
#endif
    };
	
public:
    typedef std::output_range_tag                                      range_category;
    typedef void                                                       value_type;
    typedef void                                                       length_type;
    typedef void                                                       reference;
    typedef void                                                       begin_begin_type;
    typedef void                                                       end_end_type;
    typedef void                                                       begin_type;
    typedef void                                                       end_type;

    Rg base() const {return rg_;}
    
    output_range () : rg_() {}
    explicit output_range(Rg rg) : rg_(rg) {}
    template <class U>
        output_range(const output_range<U>& u) : rg_(u.rg_) {}

    assigner front() const {return assigner(rg_);}
    void pop_front() {rg_.pop_front();}
};

template<typename T>
class equal_proxy 
{
private:
    T t_;
public:
    bool operator==(const equal_proxy& x) const { return t_ == x.t_; }
    bool operator!=(const equal_proxy& x) const { return t_ != x.t_; }
};

template<typename T>
equal_proxy<T> make_equal_proxy(T t) { return equal_proxy<T>(t); }

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
    typedef input_range<typename std::range_traits<Rg>::begin_begin_type>  begin_begin_type;
    typedef input_range<typename std::range_traits<Rg>::end_end_type>   end_end_type;
    typedef equal_proxy<typename std::range_traits<Rg>::begin_type>   begin_type;
    typedef equal_proxy<typename std::range_traits<Rg>::end_type>     end_type;

    Rg base() const {return rg_;}

    input_range() : rg_() {}
    explicit input_range(Rg rg) : rg_(rg) {}
    template <class U>
        input_range(const input_range<U>& u) : rg_(u.rg_) {} 
    
    reference front() const {return rg_.front();}
    void pop_front() {rg_.pop_front();}
    bool empty() const {return rg_.empty();}

    begin_type begin() const {return make_equal_proxy(rg_.begin()); }
    end_type   end()   const {return make_equal_proxy(rg_.end());}

    friend bool operator==(const input_range& x, const input_range& y)
        {return x.rg_ == y.rg_;}
    friend bool operator!=(const input_range& x, const input_range& y)
        {return !(x.rg_ == y.rg_);}
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
    typedef forward_range<typename std::range_traits<Rg>::begin_begin_type>  begin_begin_type;
    typedef forward_range<typename std::range_traits<Rg>::end_end_type>   end_end_type;
    typedef equal_proxy<typename std::range_traits<Rg>::begin_type>     begin_type;
    typedef equal_proxy<typename std::range_traits<Rg>::end_type>       end_type;

    Rg base() const {return rg_;}

    forward_range() : rg_() {}
    explicit forward_range(Rg rg) : rg_(rg) {}
    template <class U>
        forward_range(const forward_range<U>& u) : rg_(u.rg_) {} 
    
    reference front() const {return rg_.front();}
    void pop_front() {rg_.pop_front();}
    bool empty() const {return rg_.empty();}

    begin_begin_type begin_begin(const forward_range& r) const {return begin_begin_type(rg_.begin_begin(r.base()));}
    forward_range begin_end(const forward_range& r) const {return forward_range(rg_.begin_end(r.base()));}
    forward_range end_begin(const forward_range& r) const {return forward_range(rg_.end_begin(r.base()));}
    end_end_type end_end(const forward_range& r) const {return end_end_type(rg_.end_end(r.base()));}

    begin_type begin() const {return make_equal_proxy(rg_.begin()); }
    end_type   end()   const {return make_equal_proxy(rg_.end());}

    friend bool operator==(const forward_range& x, const forward_range& y)
        {return x.rg_ == y.rg_;}
    friend bool operator!=(const forward_range& x, const forward_range& y)
        {return !(x.rg_ == y.rg_);}
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
    typedef bidirectional_range<typename std::range_traits<Rg>::begin_begin_type>  begin_begin_type;
    typedef bidirectional_range<typename std::range_traits<Rg>::end_end_type>   end_end_type;
    typedef equal_proxy<typename std::range_traits<Rg>::begin_type>           begin_type;
    typedef equal_proxy<typename std::range_traits<Rg>::end_type>             end_type;

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

    begin_begin_type begin_begin(const bidirectional_range& r) const {return begin_begin_type(rg_.begin_begin(r.base()));}
    bidirectional_range begin_end(const bidirectional_range& r) const {return bidirectional_range(rg_.begin_end(r.base()));}
    bidirectional_range end_begin(const bidirectional_range& r) const {return bidirectional_range(rg_.end_begin(r.base()));}
    end_end_type end_end(const bidirectional_range& r) const {return end_end_type(rg_.end_end(r.base()));}

    begin_type begin() const {return make_equal_proxy(rg_.begin()); }
    end_type   end()   const {return make_equal_proxy(rg_.end());}

    friend bool operator==(const bidirectional_range& x, const bidirectional_range& y)
        {return x.rg_ == y.rg_;}
    friend bool operator!=(const bidirectional_range& x, const bidirectional_range& y)
        {return x.rg_ != y.rg_;}
};

template<typename T>
class order_proxy 
{
private:
    T t_;
public:
    bool operator==(const order_proxy& x) const { return t_ == x.t_; }
    bool operator!=(const order_proxy& x) const { return t_ != x.t_; }
    bool operator>(const order_proxy& x) const { return t_ > x.t_; }
    bool operator<(const order_proxy& x) const { return t_ < x.t_; }
    bool operator>=(const order_proxy& x) const { return t_ >= x.t_; }
    bool operator<=(const order_proxy& x) const { return t_ <= x.t_; }
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
    typedef random_access_range<typename std::range_traits<Rg>::begin_begin_type>  begin_begin_type;
    typedef random_access_range<typename std::range_traits<Rg>::end_end_type>   end_end_type;
    typedef order_proxy<typename std::range_traits<Rg>::begin_type>           begin_type;
    typedef order_proxy<typename std::range_traits<Rg>::end_type>             end_type;

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
    random_access_range operator+(length_type n) const 
        {random_access_range tmp(*this); tmp+= n; return tmp;}
    random_access_range& operator+=(length_type n) {rg_ += n; return *this;}
    random_access_range operator-(length_type n) const 
        {random_access_range tmp(*this); tmp-= n; return tmp;}
    random_access_range& operator-=(length_type n) {rg_ += n; return *this;}
    reference operator[](length_type n) const {return rg_[n];}

    begin_begin_type begin_begin(const random_access_range& r) const {return begin_begin_type(rg_.begin_begin(r.base()));}
    random_access_range begin_end(const random_access_range& r) const {return random_access_range(rg_.begin_end(r.base()));}
    random_access_range end_begin(const random_access_range& r) const {return random_access_range(rg_.end_begin(r.base()));}
    end_end_type end_end(const random_access_range& r) const {return end_end_type(rg_.end_end(r.base()));}

    begin_type begin() const {return make_order_proxy(rg_.begin()); }
    end_type   end()   const {return make_order_proxy(rg_.end());}

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
