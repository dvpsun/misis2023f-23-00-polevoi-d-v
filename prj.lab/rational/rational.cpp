// 2023 by Polevoi Dmitry under Unlicense
#include <rational/rational.hpp>

#include <stdexcept>

Rational::Rational(const std::int64_t num, const std::int64_t den)
  : num_(num), den_(den) {
  if (0 == den_) {
    throw std::invalid_argument("Zero denumenator in Rational ctor");
  }
}

bool Rational::operator==(const Rational& rhs) const noexcept { return true; }
bool Rational::operator!=(const Rational& rhs) const noexcept { return true; }
bool Rational::operator<(const Rational& rhs) const noexcept { return true; }
bool Rational::operator<=(const Rational& rhs) const noexcept { return true; }
bool Rational::operator>(const Rational& rhs) const noexcept { return true; }
bool Rational::operator>=(const Rational& rhs) const noexcept { return true; }

Rational& Rational::operator+=(const Rational& rhs) noexcept { return *this; };
Rational& Rational::operator-=(const Rational& rhs) noexcept { return *this; };
Rational& Rational::operator*=(const Rational& rhs) noexcept { return *this; };
Rational& Rational::operator/=(const Rational& rhs) { return *this; };

Rational& Rational::operator+=(const int64_t rhs) noexcept { return operator+=(Rational(rhs)); };
Rational& Rational::operator-=(const int64_t rhs) noexcept { return operator-=(Rational(rhs)); };
Rational& Rational::operator*=(const int64_t rhs) noexcept { return operator*=(Rational(rhs)); };
Rational& Rational::operator/=(const int64_t rhs) { return operator/=(Rational(rhs)); };


Rational operator+(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } += rhs; }
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } -= rhs; }
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } *= rhs; }
Rational operator/(const Rational& lhs, const Rational& rhs) { return Rational{lhs} /= rhs; }

Rational operator+(const Rational& lhs, const int64_t rhs) noexcept { return Rational{ lhs } += rhs; }
Rational operator-(const Rational& lhs, const int64_t rhs) noexcept { return Rational{ lhs } -= rhs; };
Rational operator*(const Rational& lhs, const int64_t rhs) noexcept { return Rational{ lhs } *= rhs; };
Rational operator/(const Rational& lhs, const int64_t rhs) { return Rational{ lhs } /= rhs; }

Rational operator+(const int64_t lhs, const Rational& rhs) noexcept { return operator+(rhs, lhs); }
Rational operator-(const int64_t lhs, const Rational& rhs) noexcept { return operator+(rhs, lhs); }
Rational operator*(const int64_t lhs, const Rational& rhs) noexcept { return operator+(rhs, lhs); }
Rational operator/(const int64_t lhs, const Rational& rhs) { return operator+(rhs, lhs); }


std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept { return ostrm; }

std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept { return istrm; }
