#pragma once

#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include <type_traits>

namespace ember {

namespace sim {

inline constexpr std::string_view U_TIME = "clk(s)";

using backend_t = std::uint64_t;

class Tick {
  protected:
    backend_t m_time;

  public:
    const backend_t value() const;

    void set(Tick const& other);

    void reset();

    const Tick& incr();

    // Assignment Operators

    Tick& operator=(Tick const& other);

    template <typename T>
    requires(std::is_convertible<T, backend_t>::value) Tick& operator=(T const other);

    // Increment Operators

    Tick operator+(Tick const& other);
    Tick& operator++();
    Tick operator++(int);
    Tick& operator+=(Tick const& other);

    template <typename T>
    requires(std::is_convertible<T, backend_t>::value) Tick operator+(T const other);

    template <typename T>
    requires(std::is_convertible<T, backend_t>::value) Tick& operator+=(T const other);

    // Decrement Operators
    Tick operator-(Tick const& other);
    Tick& operator--();
    Tick operator--(int);
    Tick& operator-=(Tick const& other);

    template <typename T>
    requires(std::is_convertible<T, backend_t>::value) Tick operator-(T const other);

    template <typename T>
    requires(std::is_convertible<T, backend_t>::value) Tick& operator-=(T const other);

    // Logical Operators

    bool operator==(Tick const& other) const;
    bool operator!=(Tick const& other) const;
    bool operator<(Tick const& other) const;
    bool operator<=(Tick const& other) const;
    bool operator>(Tick const& other) const;
    bool operator>=(Tick const& other) const;

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
    Tick();
    Tick(backend_t time);
    Tick(backend_t time, const char* utime);
    Tick(const Tick& other);
};

} // namespace sim
} // namespace ember

std::ostream& operator<<(std::ostream& os, ember::sim::Tick const& foo);

#include "tpp/em_time.tpp"
