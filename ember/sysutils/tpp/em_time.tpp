#pragma once

//
// === ASSIGNMENT OPERATORS === //
//

template <typename T>

requires(std::is_convertible<T, ember::sim::backend_t>::value)
    ember::sim::Tick& ember::sim::Tick::operator=(T const other) {
    m_time = static_cast<ember::sim::backend_t>(other);
    return *this;
}

//
// === INCREMENT OPERATORS === //
//

template <typename T>

requires(std::is_convertible<T, ember::sim::backend_t>::value)
    ember::sim::Tick ember::sim::Tick::operator+(T const other) {
    ember::sim::Tick value(static_cast<ember::sim::backend_t>(other));

    return *this + value;
}

template <typename T>

requires(std::is_convertible<T, ember::sim::backend_t>::value)
    ember::sim::Tick& ember::sim::Tick::operator+=(T const other) {
    ember::sim::Tick value(static_cast<ember::sim::backend_t>(other));

    return *this += value;
}

//
// === DECREMENT OPERATORS === //
//

template <typename T>

requires(std::is_convertible<T, ember::sim::backend_t>::value)
    ember::sim::Tick ember::sim::Tick::operator-(T const other) {
    ember::sim::Tick value(static_cast<ember::sim::backend_t>(other));

    return *this - value;
}

template <typename T>

requires(std::is_convertible<T, ember::sim::backend_t>::value)
    ember::sim::Tick& ember::sim::Tick::operator-=(T const other) {
    ember::sim::Tick value(static_cast<ember::sim::backend_t>(other));

    return *this -= value;
}

//
// === LOGICAL OPERATORS === //
//

template <typename T>

requires(std::is_convertible<T, ember::sim::backend_t>::value) bool ember::sim::Tick::operator==(
    T const& other) const {
    return (m_time == static_cast<ember::sim::backend_t>(other));
}

template <typename T>

requires(std::is_convertible<T, ember::sim::backend_t>::value) bool ember::sim::Tick::operator!=(
    T const& other) const {
    return (m_time != static_cast<ember::sim::backend_t>(other));
}

template <typename T>

requires(std::is_convertible<T, ember::sim::backend_t>::value) bool ember::sim::Tick::operator<(
    T const& other) const {
    return (m_time < static_cast<ember::sim::backend_t>(other));
}

template <typename T>

requires(std::is_convertible<T, ember::sim::backend_t>::value) bool ember::sim::Tick::operator<=(
    T const& other) const {
    return (m_time <= static_cast<ember::sim::backend_t>(other));
}

template <typename T>

requires(std::is_convertible<T, ember::sim::backend_t>::value) bool ember::sim::Tick::operator>(
    T const& other) const {
    return (m_time > static_cast<ember::sim::backend_t>(other));
}

template <typename T>

requires(std::is_convertible<T, ember::sim::backend_t>::value) bool ember::sim::Tick::operator>=(
    T const& other) const {
    return (m_time >= static_cast<ember::sim::backend_t>(other));
}
