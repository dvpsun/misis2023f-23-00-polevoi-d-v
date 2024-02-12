// 2022 by Polevoi Dmitry under Unlicense
#include <complex/complex.hpp>

Complex Complex::operator-() const noexcept { return Complex(-re, -im); }

bool Complex::operator==(const Complex& rhs) const noexcept { return true; }
bool Complex::operator!=(const Complex& rhs) const noexcept { return true; }

Complex& Complex::operator+=(const Complex& rhs) noexcept { return *this; }
Complex& Complex::operator+=(const double rhs) noexcept { return operator+=(Complex(rhs)); }

Complex& Complex::operator-=(const Complex& rhs) noexcept { return *this; }
Complex& Complex::operator-=(const double rhs) noexcept { return operator-=(Complex(rhs)); }

Complex& Complex::operator*=(const Complex& rhs) noexcept {  return *this; }
Complex& Complex::operator*=(const double rhs) noexcept { return *this; }

Complex& Complex::operator/=(const Complex& rhs) { return *this; }
Complex& Complex::operator/=(const double rhs) { return *this; }

std::ostream& Complex::WriteTo(std::ostream& ostrm) const noexcept { return ostrm; }
std::istream& Complex::ReadFrom(std::istream& istrm) noexcept { return istrm; }


Complex operator+(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }

Complex operator/(const Complex& lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const Complex& lhs, const double rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const double lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }