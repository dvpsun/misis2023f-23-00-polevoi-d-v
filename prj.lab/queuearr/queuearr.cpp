// 2024 by Polevoi Dmitry under Unlicense

#include <queuearr/queuearr.hpp>

#include <algorithm>
#include <stdexcept>

std::ptrdiff_t QueueArr::Count() const {
  return IsEmpty() ? 0 : (tail_ + size_ - head_) % size_ + 1;
}

QueueArr& QueueArr::operator=(const QueueArr& src) {
  if (this != &src) {
    std::ptrdiff_t count = src.Count();
    if (0 == count) {
      head_ = -1;
    } else {
      if (size_ < count) {
        size_ = (count + 4) / 4 * 4;
        delete[] data_;
        data_ = new Complex[size_];
      }
      if (src.head_ < src.tail_) {
        std::copy(src.data_ + src.head_, src.data_ + src.tail_ + 1, data_);
      }
      else {
        std::copy(src.data_ + src.head_, src.data_ + src.size_, data_);
        std::copy(src.data_, src.data_ + src.tail_ + 1, data_ + src.size_ - src.head_);
      }
    head_ = 0;
      tail_ = count - 1;
    }
  }
  return *this;
}

QueueArr::QueueArr(const QueueArr& src) {
  if (!src.IsEmpty()) {
    std::ptrdiff_t count = src.Count();
    head_ = 0;
    tail_ = count - 1;
    size_ = (count + 4) / 4 * 4;
    data_ = new Complex[size_];
    if (src.head_ < src.tail_) {
       std::copy(src.data_ + src.head_, src.data_ + src.tail_ + 1, data_);
    } else {
       std::copy(src.data_ + src.head_, src.data_ + src.size_, data_);
       std::copy(src.data_, src.data_ + src.tail_ + 1, data_ + src.size_ - src.head_);
    }
  }
}

QueueArr::QueueArr(QueueArr&& src) noexcept {
  std::swap(size_, src.size_);
  std::swap(data_, src.data_);
  std::swap(head_, src.head_);
  std::swap(tail_, src.tail_);
}

QueueArr& QueueArr::operator=(QueueArr&& src) {
  if (this != &src) {
    std::swap(size_, src.size_);
    std::swap(data_, src.data_);
    std::swap(head_, src.head_);
    std::swap(tail_, src.tail_);
  }
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
      Complex* buf = new Complex[size_ * 2];
      std::swap(buf, data_);
      if (head_ < tail_) {
        std::copy(buf + head_, buf + tail_ + 1, data_);
      } else {
        std::copy(buf + head_, buf + size_, data_);
        std::copy(buf, buf + tail_ + 1, data_ + tail_ - head_);
      }
      delete[] buf;
      size_ *= 2;
      tail_ = Count();
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
