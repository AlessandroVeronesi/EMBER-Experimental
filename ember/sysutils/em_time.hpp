#pragma once

#include <cassert>
#include <cstring>
#include <iostream>
#include <type_traits>
#include <cstdint>
#include <string>

namespace ember {

using time_backend_t = std::uint64_t;

class time_t
{
  protected:
    time_backend_t _time;
    std::string _utime;

  public:
    const time_backend_t getSimTime() const;
    const char* getTimeUnit() const;
    void reset();
    const time_t& incr();

    // Assignment Operators
    time_t& operator=(time_t const& other);

    template <typename T>
    requires(std::is_convertible<T, time_backend_t>::value)
    time_t& operator=(T const other);

    // Increment Operators
    
    time_t operator+(time_t const& other);
    time_t& operator++();
    time_t operator++(int);
    time_t& operator+=(time_t const& other);
    
    template <typename T>
    requires(std::is_convertible<T, time_backend_t>::value)
    time_t operator+(T const other);

    template <typename T>
    requires(std::is_convertible<T, time_backend_t>::value)
    time_t& operator+=(T const other);

    // Decrement Operators
    time_t operator-(time_t const& other);
    time_t& operator--();
    time_t operator--(int);
    time_t& operator-=(time_t const& other);

    template <typename T>
    requires(std::is_convertible<T, time_backend_t>::value)
    time_t operator-(T const other);

    template <typename T>
    requires(std::is_convertible<T, time_backend_t>::value)
    time_t& operator-=(T const other);

    // Logical Operators
    
    bool operator==(time_t const& other) const;
    bool operator!=(time_t const& other) const;
    bool operator< (time_t const& other) const;
    bool operator<=(time_t const& other) const;
    bool operator> (time_t const& other) const;
    bool operator>=(time_t const& other) const;

    template <typename T>
    requires(std::is_convertible<T, time_backend_t>::value)
    bool operator==(T const& other) const;

    template <typename T>
    requires(std::is_convertible<T, time_backend_t>::value)
    bool operator!=(T const& other) const;

    template <typename T>
    requires(std::is_convertible<T, time_backend_t>::value)
    bool operator<(T const& other) const;

    template <typename T>
    requires(std::is_convertible<T, time_backend_t>::value)
    bool operator<=(T const& other) const;

    template <typename T>
    requires(std::is_convertible<T, time_backend_t::value)
    bool operator>(T const& other) const;

    template <typename T>
    requires(std::is_convertible<T, time_backend_t>::value)
    bool operator>=(T const& other) const;

    // CTOR
    time_t();
    time_t(time_backend_t time);
    time_t(time_backend_t time, const char* utime);
};

} // namespace ember

 
std::ostream& operator<<(std::ostream& os, ember::time_t const& foo);

#include "tpp/em_time.tpp"

