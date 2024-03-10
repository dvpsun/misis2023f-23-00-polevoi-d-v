// 2024 by Polevoi Dmitry under Unlicense

#include <queuearr/queuearr.hpp>

#include <algorithm>
#include <stdexcept>

std::ptrdiff_t QueueArr::Count() const {
  return IsEmpty() ? 0 : (tail_ + size_ + 1 - head_) % size_;
}

QueueArr::QueueArr(const QueueArr& qu) {
  if (!qu.IsEmpty()) {
    size_ = (tail_ + qu.size_ + 1 - head_) % qu.size_;
    head_ = 0;
    tail_ = size_;
    size_ = (size_ + 4) / 4 * 4;
    data_ = new Complex[size_];
    if (qu.head_ < qu.tail_) {
       std::copy(qu.data_ + qu.head_,qu.data_ + qu.tail_, data_);
    } else {
       std::copy(qu.data_ + qu.head_,qu.data_ + qu.size_, data_);
       std::copy(qu.data_ , qu.data_ + qu.tail_, data_ + qu.size_ - qu.head_);
    }
  }
}

QueueArr& QueueArr::operator=(const QueueArr&) {
  return *this;
}

QueueArr::~QueueArr() {
  delete[] data_;
}

bool QueueArr::IsEmpty() const noexcept {
  return head_ < 0;
}

void QueueArr::Pop() noexcept {
  if (!IsEmpty()) {
    if (head_ != tail_) {
      head_ = (head_ + 1) % size_;
    } else {
      head_ = -1;
    }
  }
}

void QueueArr::Push(const Complex& val) {
  if (nullptr == data_) {
    size_ = 2;
    data_ = new Complex[size_];
  } 
  if (IsEmpty()) {
    head_ = 0;
    tail_ = 0;
  } else {
    if (head_ == (tail_ + 1) % size_) {
      // resize
      auto size = 2 * size_;
      auto data = new Complex[size];
      if (head_ < tail_) {
        std::copy(data_ + head_, data_ + tail_, data);
      } else {
        std::copy(data_ + head_, data_ + size_, data);
        std::copy(data_, data_ + tail_, data + size_ - head_);
      }
      size_ = size;
    }
    tail_ = (tail_ + 1) % size_;
  }
  data_[tail_] = val;
}
  
Complex& QueueArr::Top() {
  if (IsEmpty()) {
    throw std::logic_error("QueueArr - try get top form empty queue.");
  }
  return data_[head_];
}

const Complex& QueueArr::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("QueueArr - try get top form empty queue.");
  }
  return data_[head_];
}

void QueueArr::Clear() noexcept {
    head_ = -1;
}
