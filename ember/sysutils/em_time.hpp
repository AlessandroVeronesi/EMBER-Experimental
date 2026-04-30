#pragma once

#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <type_traits>

namespace ember {

inline constexpr std::string_view U_TIME = "clk(s)";

namespace time {

using backend_t = std::uint64_t;

class time_t {
  protected:
    backend_t m_time;


  public:
    const backend_t value() const;
    void set(time_t const& other);
    void reset();
    const time_t& incr();

    // Assignment Operators
    time_t& operator=(time_t const& other);

    template <typename T>
    requires(std::is_convertible<T, backend_t>::value) time_t& operator=(T const other);

    // Increment Operators

    time_t operator+(time_t const& other);
    time_t& operator++();
    time_t operator++(int);
    time_t& operator+=(time_t const& other);

    template <typename T>
    requires(std::is_convertible<T, backend_t>::value) time_t operator+(T const other);

    template <typename T>
    requires(std::is_convertible<T, backend_t>::value) time_t& operator+=(T const other);

    // Decrement Operators
    time_t operator-(time_t const& other);
    time_t& operator--();
    time_t operator--(int);
    time_t& operator-=(time_t const& other);

    template <typename T>
    requires(std::is_convertible<T, backend_t>::value) time_t operator-(T const other);

    template <typename T>
    requires(std::is_convertible<T, backend_t>::value) time_t& operator-=(T const other);

    // Logical Operators

    bool operator==(time_t const& other) const;
    bool operator!=(time_t const& other) const;
    bool operator<(time_t const& other) const;
    bool operator<=(time_t const& other) const;
    bool operator>(time_t const& other) const;
    bool operator>=(time_t const& other) const;

    template <typename T>
    requires(std::is_convertible<T, backend_t>::value) bool operator==(T const& other) const;

    template <typename T>
    requires(std::is_convertible<T, backend_t>::value) bool operator!=(T const& other) const;

    template <typename T>
    requires(std::is_convertible<T, backend_t>::value) bool operator<(T const& other) const;

    template <typename T>
    requires(std::is_convertible<T, backend_t>::value) bool operator<=(T const& other) const;

    template <typename T>
    requires(std::is_convertible<T, backend_t>::value) bool operator>(T const& other) const;

    template <typename T>
    requires(std::is_convertible<T, backend_t>::value) bool operator>=(T const& other) const;

    // CTOR
    time_t();
    time_t(backend_t time);
    time_t(backend_t time, const char* utime);
};

} // namespace time
} // namespace ember


std::ostream& operator<<(std::ostream& os, ember::time::time_t const& foo);

#include "tpp/em_time.tpp"
