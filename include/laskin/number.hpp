/*
 * Copyright (c) 2018, Rauli Laine
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef LASKIN_NUMBER_HPP_GUARD
#define LASKIN_NUMBER_HPP_GUARD

#include <iostream>
#include <string>

#include <gmpxx.h>

#include "laskin/unit.hpp"

namespace laskin
{
  class number
  {
  public:
    using value_type = mpf_class;
    using unit_type = laskin::unit;

    explicit number(const value_type& value, unit_type unit = unit_type::none);
    number(const number& that);
    number& operator=(const number& that);

    /**
     * Tests whether given string contains a valid number.
     */
    static bool isnumber(const std::u32string& input);

    /**
     * Parses given string into a number.
     */
    static number from_string(const std::u32string& input);

    inline const value_type& value() const
    {
      return m_value;
    }

    inline unit_type unit() const
    {
      return m_unit;
    }

    std::u32string to_string() const;

    number operator+(const number& that) const;
    number operator-(const number& that) const;
    number operator*(const number& that) const;

    number operator/(int operand) const;

    number& operator+=(const number& that);
    number& operator-=(const number& that);
    number& operator*=(const number& that);

    number& operator+=(int operand);
    number& operator-=(int operand);

    bool operator==(const number& that) const;
    bool operator!=(const number& that) const;
    bool operator<(const number& that) const;
    bool operator>(const number& that) const;
    bool operator<=(const number& that) const;
    bool operator>=(const number& that) const;

  private:
    value_type m_value;
    unit_type m_unit;
  };

  std::ostream& operator<<(std::ostream&, const number&);
}

#endif /* !LASKIN_NUMBER_HPP_GUARD */
