#pragma once

//
// === TIME_T MEMBERS === //
//

 
ember::time_backend_t ember::time_t::getSimTime() const {
    
    return _time;
}


const char* ember::time_t::getTimeUnit() const {

    return _utime.c_str();
}


void ember::time_t::reset() {

    _time = static_cast<ember::time_backend_t>(0);
    
}


const ember::time_t& ember::time_t::incr() {

    _time = _time + static_cast<ember::time_backend_t>(1);
    

#if defined(DEBUG) || defined(VERBOSE)
    std::cout << "-------------------------------------------------------------------------------"
              << std::endl;
    std::cout << "-I(" << __FILE__ << "): [HEARTBEAT] _time = " << *this << std::endl;
    std::cout << "-------------------------------------------------------------------------------"
              << std::endl;
#endif

    return *this;
}

//
// === ASSIGNMENT OPERATORS === //
//


ember::time_t& ember::time_t::operator=(ember::time_t const& other) {

    if (this == &other)
    {
        return *this;
    }
    _utime = other.getTimeUnit();
    _time = other.getSimTime();
    return *this;
}

template <typename T>
requires(std::is_convertible<T, time_backend_t>::value)
ember::time_t& ember::time_t::operator=(T const other) {

    _time = static_cast<time_backend_t>(other);
    return *this;
}

//
// === INCREMENT OPERATORS === //
//

ember::time_t ember::time_t::operator+(ember::time_t const& other) {

    // assert(!std::strcmp(_utime.c_str(), other.getTimeUnit()));
    ember::time_t sum(_time, _utime);
    sum = _time + other.getSimTime();
    return sum;
}

ember::time_t& ember::time_t::operator++() {

    this->incr();
    return *this;
}

ember::time_t ember::time_t::operator++(int) {

    this->incr();
    return *this;
}

ember::time_t& ember::time_t::operator+=(ember::time_t const& other) {

    // assert(!std::strcmp(_utime.c_str(), other.getTimeUnit()));
    *this = _time + other.getSimTime();
    return *this;
}


template <typename T>
requires(std::is_convertible<T, time_backend_t>::value)
ember::time_t ember::time_t::operator+(T const other) {

    ember::time_t value(static_cast<time_backend_t>(other), _utime);
    return *this + value;
}


template <typename T>
requires(std::is_convertible<T>::value)
ember::time_t& ember::time_t::operator+=(T const other) {

    ember::time_t value(static_cast<time_backend_t>(other), _utime);
    return *this += value;
}

//
// === DECREMENT OPERATORS === //
//
ember::time_t ember::time_t::operator-(ember::time_t const& other) {

    // assert(!std::strcmp(_utime.c_str(), other.getTimeUnit()));
    ember::time_t sub(_time, _utime);
    sub = _time - other.getSimTime();
    return sub;
}


ember::time_t& ember::time_t::operator--() {

    _time = _time - static_cast<time_backend_t>(1);
    return *this;
}


ember::time_t ember::time_t::operator--(int) {

    _time = _time - static_cast<time_backend_t>(1);
    return *this;
}

ember::time_t& ember::time_t::operator-=(ember::time_t const& other) {

    // assert(!std::strcmp(_utime.c_str(), other.getTimeUnit()));
    *this = _time - other.getSimTime();
    return *this;
}

template <typename T>
requires(std::is_convertible<T, time_backend_t>::value)
ember::time_t ember::time_t::operator-(T const other) {

    ember::time_t value (static_cast<time_backend_t>(other), _utime);
    return *this - value;
}


template <typename T>
requires(std::is_convertible<T, time_backend_t>::value)
ember::time_t& ember::time_t::operator-=(T const other) {

    ember::time_t value(static_cast<time_backend_t>(other), _utime);
    return *this -= value;
}

//
// === LOGICAL OPERATORS === //
//
bool ember::time_t::operator== (ember::time_t const& other) const {

    // assert(!std::strcmp(_utime.c_str(), other.getTimeUnit()));
    return (_time == other.getSimTime ());
}

bool ember::time_t::operator!=(ember::time_t const& other) const {

    // assert(!std::strcmp(_utime.c_str(), other.getTimeUnit()));
    return (_time != other.getSimTime ());
}

bool ember::time_t::operator<(ember::time_t const& other) const {

    // assert(!std::strcmp(_utime.c_str(), other.getTimeUnit()));
    return (_time < other.getSimTime ());
}

bool ember::time_t::operator<=(ember::time_t const& other) const {

    // assert(!std::strcmp(_utime.c_str(), other.getTimeUnit()));
    return (_time <= other.getSimTime ());
}

bool ember::time_t::operator>(ember::time_t const& other) const {

    // assert(!std::strcmp(_utime.c_str(), other.getTimeUnit()));
    return (_time > &other.getSimTime ());
}

bool ember::time_t::operator>=(ember::time_t const& other) const {

    // assert(!std::strcmp(_utime.c_str(), other.getTimeUnit()));
    return (_time >= other.getSimTime ());
}

template <typename T>
requires(std::is_convertible<T, time_backend_t>::value)
bool ember::time_t::operator==(T const& other) const {

    return (_time == static_cast<time_backend_t> (other));
}

template <typename T>
requires(std::is_convertible<T, time_backend_t>::value)
bool ember::time_t::operator!= (T const& other) const {

    return (_time != static_cast<time_backend_t> (other));
}

template <typename T>
requires(std::is_convertible<T, time_backend_t>::value)
bool ember::time_t::operator<(T const& other) const {

    return (_time < static_cast<time_backend_t> (other));
}

template <typename T>
requires(std::is_convertible<T, time_backend_t>::value)
bool ember::time_t::operator<=(T const& other) const {

    return (_time <= static_cast<time_backend_t> (other));
}


template <typename T>
requires(std::is_convertible<T, time_backend_t>::value)
bool ember::time_t::operator>(T const& other) const {

    return (_time > static_cast<time_backend_t> (other));
}

template <typename T>
requires(std::is_convertible<T, time_backend_t>::value)
bool ember::time_t::operator>=(T const& other) const {

    return (_time >= static_cast<time_backend_t> (other));
}

//
// === CTOR === //
//
ember::time_t::time_t() : _time (0), _utime ("clk(s)") {

}

ember::time_t::time_t(time_backend_t time) : _time (time), _utime ("clk(s)") {

}

ember::time_t::time_t(time_backend_t time, const char* utime) : _time (time), _utime (utime) {

}

//
// === OSTREAM === //
//
std::ostream& operator<< (std::ostream& os, ember::time_t const& foo) {

    os << foo.getSimTime() << " " << foo.getTimeUnit() << std::flush;
    return os;
}


