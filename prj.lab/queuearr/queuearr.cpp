// 2024 by Polevoi Dmitry under Unlicense

#include <queuearr/queuearr.hpp>

#include <algorithm>
#include <stdexcept>

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
       std::copy(qu.data_ , qu.data_ + qu.tail_, data_ + qu.size_);
    }
  }
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
    data_ = new Complex[1];
  } 
  if (IsEmpty()) {
    head_ = 0;
    tail_ = 0;
  } else {
    if (head_ == (tail_ + 1) % size_) {
      // resize
    } else {
      tail_ = (tail_ + 1) % size_;
    }
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
