// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef QUEUEARR_QUEUEARR_HPP_20240227
#define QUEUEARR_QUEUEARR_HPP_20240227

#include <complex/complex.hpp>

#include <cstddef>

class QueueArr {
public:
  QueueArr() = default;

  QueueArr(const QueueArr&);

  QueueArr(QueueArr&&) = default;
  
  ~QueueArr();
  
  QueueArr& operator=(const QueueArr&);

  QueueArr& operator=(QueueArr&&) = default;

  [[nodiscard]] bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);
  
  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;

private:
  std::ptrdiff_t size_ = 0;  //!< 
  Complex* data_ = nullptr;  //!< 
  std::ptrdiff_t head_ = -1; //!< 
  std::ptrdiff_t tail_ = -1; //!< 
private:
  std::ptrdiff_t Count() const;
};

#endif
