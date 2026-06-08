#include "em_tick.hpp"

//
// === Tick MEMBERS === //
//

void ember::sim::Tick::set(Tick const& other) {
    *this = other;
}

const ember::sim::backend_t ember::sim::Tick::value() const {
    return m_time;
}

void ember::sim::Tick::reset() {
    m_time = static_cast<ember::sim::backend_t>(0);
}

const ember::sim::Tick& ember::sim::Tick::incr() {
    m_time = m_time + static_cast<ember::sim::backend_t>(1);

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

ember::sim::Tick& ember::sim::Tick::operator=(ember::sim::Tick const& other) {
    if (this == &other) {
        return *this;
    }
    m_time = other.value();
    return *this;
}

//
// === INCREMENT OPERATORS === //
//

ember::sim::Tick ember::sim::Tick::operator+(ember::sim::Tick const& other) {
    ember::sim::Tick sum(m_time);
    sum = m_time + other.value();
    return sum;
}

ember::sim::Tick& ember::sim::Tick::operator++() {
    this->incr();
    return *this;
}

ember::sim::Tick ember::sim::Tick::operator++(int) {
    this->incr();
    return *this;
}

ember::sim::Tick& ember::sim::Tick::operator+=(ember::sim::Tick const& other) {
    *this = m_time + other.value();
    return *this;
}

//
// === DECREMENT OPERATORS === //
//

ember::sim::Tick ember::sim::Tick::operator-(ember::sim::Tick const& other) {
    ember::sim::Tick sub(m_time);
    sub = m_time - other.value();
    return sub;
}

ember::sim::Tick& ember::sim::Tick::operator--() {
    m_time = m_time - static_cast<backend_t>(1);
    return *this;
}

ember::sim::Tick ember::sim::Tick::operator--(int) {
    m_time = m_time - static_cast<backend_t>(1);
    return *this;
}

ember::sim::Tick& ember::sim::Tick::operator-=(ember::sim::Tick const& other) {
    *this = m_time - other.value();
    return *this;
}

//
// === LOGICAL OPERATORS === //
//

bool ember::sim::Tick::operator==(ember::sim::Tick const& other) const {
    return (m_time == other.value());
}

bool ember::sim::Tick::operator!=(ember::sim::Tick const& other) const {
    return (m_time != other.value());
}

bool ember::sim::Tick::operator<(ember::sim::Tick const& other) const {
    return (m_time < other.value());
}

bool ember::sim::Tick::operator<=(ember::sim::Tick const& other) const {
    return (m_time <= other.value());
}

bool ember::sim::Tick::operator>(ember::sim::Tick const& other) const {
    return (m_time > other.value());
}

bool ember::sim::Tick::operator>=(ember::sim::Tick const& other) const {
    return (m_time >= other.value());
}

//
// === CTOR === //
//

ember::sim::Tick::Tick() : m_time(0) {}

ember::sim::Tick::Tick(backend_t time) : m_time(time) {}

ember::sim::Tick::Tick(backend_t time, const char* utime) : m_time(time) {}

ember::sim::Tick::Tick(const ember::sim::Tick& other) {
    m_time = other.m_time;
}

//
// === OSTREAM === //
//

std::ostream& operator<<(std::ostream& os, ember::sim::Tick const& foo) {
    os << foo.value() << " " << ember::sim::U_TIME << std::flush;
    return os;
}