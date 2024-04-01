// 2024 by Polevoi Dmitry under Unlicense

#include <queuelst/queuelst.hpp>

#include <stdexcept>

QueueLst::QueueLst(const QueueLst& src) {
  if (!src.IsEmpty()) {
    head_ = new Node{src.head_->val};
    Node* p_src = src.head_;
    Node* p_dst = head_;
    while (p_src->next) {
      p_dst->next = new Node{p_src->next->val};
      p_src = p_src->next;
      p_dst = p_dst->next;
    }
    tail_ = p_dst;
  }
}

QueueLst::QueueLst(QueueLst&& src) noexcept 
    : head_(src.head_), tail_(src.tail_) {
  src.head_ = nullptr;
  src.tail_ = nullptr;
}

QueueLst& QueueLst::operator=(const QueueLst& src) {
  if (this != &src) {
    if (src.IsEmpty()) {
      Clear();
    } else {
      // TODO: faster and smartert
      QueueLst copy(src);
      std::swap(head_, copy.head_);
      std::swap(tail_, copy.tail_);
    }
  }
  return *this;
}

QueueLst& QueueLst::operator=(QueueLst&& src) noexcept {
  if (this != &src) {
    std::swap(head_, src.head_);
    std::swap(tail_, src.tail_);
  }
  return *this;
}

bool QueueLst::IsEmpty() const noexcept {
  return nullptr == head_;
}

void QueueLst::Pop() noexcept {
  if (!IsEmpty()) {
    Node* deleted = head_;  
    head_ = head_->next;
    delete deleted;
  }
  if (IsEmpty()) {
    tail_ = nullptr;
  }
}

void QueueLst::Push(const Complex& val) {
  if (IsEmpty()) {
    tail_ = new Node{val};
    head_ = tail_;
  } else {
    tail_->next = new Node{val};
    tail_ = tail_->next;
  }
}
  
Complex& QueueLst::Top() & {
  if (IsEmpty()) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  return head_->val;
}

const Complex& QueueLst::Top() const & {
  if (IsEmpty()) {
    throw std::logic_error("QueueLst - try get top form empty queue.");
  }
  return head_->val;
}

void QueueLst::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}
