// 2023 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef DYNARR_DYNARR_HPP_20231203
#define DYNARR_DYNARR_HPP_20231203

#include <cstddef>

class DynArr {
public:
  [[nodiscard]] DynArr() = default;

  [[nodiscard]] DynArr(const DynArr&) = default;
  
  //! \param size - начальный размер, 0 < size
  [[nodiscard]] DynArr(const std::ptrdiff_t size) : size_(size) { }
  
  ~DynArr() = default;
  
  [[nodiscard]] DynArr& operator=(const DynArr&) = default;

  [[nodiscard]] std::ptrdiff_t Size() const noexcept { return size_; }
  
  //! \param size - новый размер, 0 < size
  void Resize(const std::ptrdiff_t size) { size_ = size; }
  
  [[nodiscard]] float& operator[](const std::ptrdiff_t idx) { return data_; }
  
  [[nodiscard]] const float& operator[](const std::ptrdiff_t idx) const { return data_; }

private:
  std::ptrdiff_t size_ = 0; //!< число элементов в массиве
  float data_ = 0;          //!< элементы массива
};

#endif // !DYNARR_DYNARR_HPP_20231203
