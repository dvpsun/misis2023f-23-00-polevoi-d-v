// 2024 by Polevoi Dmitry under Unlicense

#include <complex/complex.hpp>
#include <stackarr/stackarr.hpp>

#include <algorithm>
#include <stdexcept>

StackArr::StackArr(const StackArr& src) {
  if (!src.IsEmpty()) {
    size_ = ((i_top_ + 1) / 4 + 1) * 4;
    size_ = src.i_top_;
    data_ = new Complex(size_ * 2);
    std::copy(src.data_, src.data_ + size_ + 1, data_);
  }
}

StackArr::StackArr(StackArr&& src) {
  std::swap(size_, src.size_);
  std::swap(i_top_, src.i_top_);
  std::swap(data_, src.data_);
}

StackArr& StackArr::operator=(const StackArr& src) {
  if (this != &src) {
    if (src.IsEmpty()) {
      Clear();
    }
    if (size_ <= src.i_top_) {
      size_ = (src.i_top_ + 4) / 4 * 4;
      Complex* buf = new Complex[size_];
      std::swap(data_, buf);
      delete[] buf;
    }
    i_top_ = src.i_top_;
    std::copy(src.data_, src.data_ + i_top_ + 1, data_);
  }
  return *this;
}

StackArr& StackArr::operator=(StackArr&& src) {
  if (this != &src) {
    std::swap(size_, src.size_);
    std::swap(i_top_, src.i_top_);
    std::swap(data_, src.data_);
  }
  return *this;
}

StackArr::~StackArr() {
  delete[] data_;
}

bool StackArr::IsEmpty() const noexcept {
  return i_top_ < 0;
}

void StackArr::Pop() noexcept {
  if (!IsEmpty()) {
    i_top_ -= 1;
  }
}

void StackArr::Push(const Complex& val) {
  if (nullptr == data_) {
    size_ = 8;
    data_ = new Complex[size_];
  } else if (size_ == i_top_ + 1) { 
    auto buf = new Complex(size_ * 2);
    std::copy(data_, data_ + size_, buf);
    std::swap(data_, buf);
    delete[] buf;
    size_ *= 2;
  }
  data_[++i_top_] = val;
}
  
Complex& StackArr::Top() {
  if (i_top_ < 0) {
    throw std::logic_error("StackArr - try get top form empty stack.");
  }
  return data_[i_top_];
}

const Complex& StackArr::Top() const {
  if (i_top_ < 0) {
    throw std::logic_error("StackArr - try get top form empty stack.");
  }
  return data_[i_top_];
}

void StackArr::Clear() noexcept {
  i_top_ = -1;
}
