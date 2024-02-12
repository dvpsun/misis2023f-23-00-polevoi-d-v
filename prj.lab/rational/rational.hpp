// 2023 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef RATIONAL_RATIONAL_HPP_20231113
#define RATIONAL_RATIONAL_HPP_20231113

#include <cstdint>
#include <iosfwd>

class Rational {
public:
  [[nodiscard]] Rational() = default;
  [[nodiscard]] Rational(const Rational&) = default;
  [[nodiscard]] explicit Rational(const std::int64_t num) noexcept : num_(num) { }
  [[nodiscard]] Rational(const std::int64_t num, const std::int64_t den);
  ~Rational() = default;
  [[nodiscard]] Rational& operator=(const Rational&) = default;

  [[nodiscard]] std::int64_t num() const noexcept { return num_; }
  [[nodiscard]] std::int64_t den() const noexcept { return den_; }

  [[nodiscard]] bool operator==(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator!=(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator<(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator<=(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator>(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator>=(const Rational& rhs) const noexcept;

  [[nodiscard]] Rational operator-() const noexcept { return { -num_, den_ }; }

  Rational& operator+=(const Rational& rhs) noexcept;
  Rational& operator-=(const Rational& rhs) noexcept;
  Rational& operator*=(const Rational& rhs) noexcept;
  Rational& operator/=(const Rational& rhs);

  Rational& operator+=(const int64_t rhs) noexcept;
  Rational& operator-=(const int64_t rhs) noexcept;
  Rational& operator*=(const int64_t rhs) noexcept;
  Rational& operator/=(const int64_t rhs);

  //! \brief Форматированный вывод в поток ostrm рационального числа в виде num/den.
  //!
  //! \param[in,out] ostrm - поток
  //! \retval поток
  std::ostream& WriteTo(std::ostream& ostrm) const noexcept;

  //! \brief Форматированный ввод из потока istrm комплексного числа в виде num/den.
  //!
  //! \param[in,out] istrm - поток
  //! \retval поток
  std::istream& ReadFrom(std::istream& istrm) noexcept;

private:
  std::int64_t num_ = 0; //!< числитель
  std::int64_t den_ = 1; //!< знаменатель, > 0
};

[[nodiscard]] Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const Rational& rhs);

[[nodiscard]] Rational operator+(const Rational& lhs, const int64_t rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs, const int64_t rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs, const int64_t rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const int64_t rhs);

[[nodiscard]] Rational operator+(const int64_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const int64_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const int64_t lhs, const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const int64_t lhs, const Rational& rhs);

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept;

std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept;

#endif // !RATIONAL_RATIONAL_HPP_20231113
