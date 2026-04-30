#include "em_time.hpp"


//
// === TIME_T MEMBERS === //
//


const ember::time::backend_t ember::time::time_t::value() const {
    return m_time;
}

void ember::time::time_t::set(time_t const& other) {
    *this = other;
}


void ember::time::time_t::reset() {
    m_time = static_cast<ember::time::backend_t>(0);
}


const ember::time::time_t& ember::time::time_t::incr() {
    m_time = m_time + static_cast<ember::time::backend_t>(1);


#if defined(DEBUG) || defined(VERBOSE)
    std::cout << "-------------------------------------------------------------------------------"
              << std::endl;
    std::cout << "-I(" << __FILE__ << "): [HEARTBEAT] m_time = " << *this << std::endl;
    std::cout << "-------------------------------------------------------------------------------"
              << std::endl;
#endif

    return *this;
}

//
// === ASSIGNMENT OPERATORS === //
//

ember::time::time_t&
ember::time::time_t::operator=(ember::time::time_t const& other) {
    if (this == &other) {
        return *this;
    }
    m_time = other.value();
    return *this;
}

//
// === INCREMENT OPERATORS === //
//

ember::time::time_t
ember::time::time_t::operator+(ember::time::time_t const& other) {
    ember::time::time_t sum(m_time);
    sum = m_time + other.value();
    return sum;
}

ember::time::time_t& ember::time::time_t::operator++() {
    this->incr();
    return *this;
}

ember::time::time_t ember::time::time_t::operator++(int) {
    this->incr();
    return *this;
}

ember::time::time_t&
ember::time::time_t::operator+=(ember::time::time_t const& other) {
    *this = m_time + other.value();
    return *this;
}

//
// === DECREMENT OPERATORS === //
//

ember::time::time_t
ember::time::time_t::operator-(ember::time::time_t const& other) {
    ember::time::time_t sub(m_time);
    sub = m_time - other.value();
    return sub;
}


ember::time::time_t& ember::time::time_t::operator--() {
    m_time = m_time - static_cast<backend_t>(1);
    return *this;
}


ember::time::time_t ember::time::time_t::operator--(int) {
    m_time = m_time - static_cast<backend_t>(1);
    return *this;
}

ember::time::time_t&
ember::time::time_t::operator-=(ember::time::time_t const& other) {
    *this = m_time - other.value();
    return *this;
}

//
// === LOGICAL OPERATORS === //
//

bool ember::time::time_t::operator==(ember::time::time_t const& other) const {
    return (m_time == other.value());
}

bool ember::time::time_t::operator!=(ember::time::time_t const& other) const {
    return (m_time != other.value());
}

bool ember::time::time_t::operator<(ember::time::time_t const& other) const {
    return (m_time < other.value());
}

bool ember::time::time_t::operator<=(ember::time::time_t const& other) const {
    return (m_time <= other.value());
}

bool ember::time::time_t::operator>(ember::time::time_t const& other) const {
    return (m_time > other.value());
}

bool ember::time::time_t::operator>=(ember::time::time_t const& other) const {
    return (m_time >= other.value());
}

//
// === CTOR === //
//
ember::time::time_t::time_t() : m_time(0) {}

ember::time::time_t::time_t(backend_t time) : m_time(time) {}

ember::time::time_t::time_t(backend_t time, const char* utime) : m_time(time) {}

//
// === OSTREAM === //
//
std::ostream& operator<<(std::ostream& os, ember::time::time_t const& foo) {
    os << foo.value() << " " << ember::U_TIME << std::flush;
    return os;
}