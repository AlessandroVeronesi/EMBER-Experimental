#pragma once


//
// === ASSIGNMENT OPERATORS === //
//

template <typename T>
requires(std::is_convertible<T, ember::time::backend_t>::value)
    ember::time::time_t& ember::time::time_t::operator=(T const other) {
    m_time = static_cast<backend_t>(other);
    return *this;
}

//
// === INCREMENT OPERATORS === //
//

template <typename T>
requires(std::is_convertible<T, ember::time::backend_t>::value)
    ember::time::time_t ember::time::time_t::operator+(T const other) {
    ember::time::time_t value(static_cast<backend_t>(other));
    return *this + value;
}


template <typename T>
requires(std::is_convertible<T, ember::time::backend_t>::value)
    ember::time::time_t& ember::time::time_t::operator+=(T const other) {
    ember::time::time_t value(static_cast<backend_t>(other));
    return *this += value;
}

//
// === DECREMENT OPERATORS === //
//

template <typename T>
requires(std::is_convertible<T, ember::time::backend_t>::value)
    ember::time::time_t ember::time::time_t::operator-(T const other) {
    ember::time::time_t value(static_cast<backend_t>(other));
    return *this - value;
}


template <typename T>
requires(std::is_convertible<T, ember::time::backend_t>::value)
    ember::time::time_t& ember::time::time_t::operator-=(T const other) {
    ember::time::time_t value(static_cast<backend_t>(other));
    return *this -= value;
}

//
// === LOGICAL OPERATORS === //
//

template <typename T>
requires(std::is_convertible<T, ember::time::backend_t>::value) bool ember::time::time_t::
operator==(T const& other) const {
    return (m_time == static_cast<backend_t>(other));
}

template <typename T>
requires(std::is_convertible<T, ember::time::backend_t>::value) bool ember::time::time_t::
operator!=(T const& other) const {
    return (m_time != static_cast<backend_t>(other));
}

template <typename T>
requires(std::is_convertible<T, ember::time::backend_t>::value) bool ember::time::time_t::operator<(
    T const& other) const {
    return (m_time < static_cast<backend_t>(other));
}

template <typename T>
requires(std::is_convertible<T, ember::time::backend_t>::value) bool ember::time::time_t::
operator<=(T const& other) const {
    return (m_time <= static_cast<backend_t>(other));
}


template <typename T>
requires(std::is_convertible<T, ember::time::backend_t>::value) bool ember::time::time_t::operator>(
    T const& other) const {
    return (m_time > static_cast<backend_t>(other));
}

template <typename T>
requires(std::is_convertible<T, ember::time::backend_t>::value) bool ember::time::time_t::
operator>=(T const& other) const {
    return (m_time >= static_cast<backend_t>(other));
}
