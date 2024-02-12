// 2024 by Polevoi Dmitry under Unlicense

#include <complex/complex.hpp>
#include <stackarr/stackarr.hpp>

#include <algorithm>
#include <stdexcept>

bool StackArr::IsEmpty() const noexcept {
  return 0 <= i_top_;
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
