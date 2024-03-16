// 2023 by Polevoi Dmitry under Unlicense

#include <dynarr/dynarr.hpp>

#include <memory>
#include <stdexcept>

DynArr::DynArr(const std::ptrdiff_t size) 
  : capacity_(size)
  , size_(size) { 
  if (size_ <= 0) {
    throw std::invalid_argument("DynArr ctor gets negative size.");
  }
  data_ = std::make_unique<float[]>(capacity_);
}

DynArr::DynArr(const DynArr& src) 
  : capacity_(src.size_)
  , size_(src.size_) {
  data_ = std::make_unique<float[]>(capacity_);
  std::copy(src.data_.get(), src.data_.get() + src.size_, data_.get());
}

DynArr::DynArr(DynArr&& src) noexcept {
  std::swap(capacity_, src.capacity_);
  std::swap(size_, src.size_);
  std::swap(data_, src.data_);
}

DynArr& DynArr::operator=(const DynArr& src) {
  if (this != &src) {
    if (capacity_ < src.size_) {
      capacity_ = src.size_;
      data_ = std::make_unique<float[]>(capacity_);
    }
    size_ = src.size_;
    std::copy(src.data_.get(), src.data_.get() + src.size_, data_.get());
  }
  return *this;
}

DynArr& DynArr::operator=(DynArr&& src) noexcept {
  if (this != &src) {
    std::swap(capacity_, src.capacity_);
    std::swap(size_, src.size_);
    std::swap(data_, src.data_);
  }
  return *this;
}


float& DynArr::operator[](const std::ptrdiff_t idx) { 
  if (idx < 0 || size_ - 1 < idx) {
    throw std::out_of_range("DynArr ctor gets invalid index.");
  }
  return data_[idx];
}

const float& DynArr::operator[](const std::ptrdiff_t idx) const {
  if (idx < 0 || size_ - 1 < idx) {
    throw std::out_of_range("DynArr ctor gets invalid index.");
  }
  return data_[idx];
}

void DynArr::Resize(const std::ptrdiff_t size) {
  if (size <= 0) {
    throw std::invalid_argument("DynArr Resize gets non positive size.");
  }
  if (size < size_) {
    size_ = size;
  } else {
    auto buf = std::make_unique<float[]>(size);
    std::copy(data_.get(), data_.get() + size_, buf.get());
    std::swap(data_, buf);
    capacity_ = size;
    size_ = capacity_;
  }
}