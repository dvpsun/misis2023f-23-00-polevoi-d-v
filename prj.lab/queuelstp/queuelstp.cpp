// 2024 by Polevoi Dmitry under Unlicense

#include <queuelstp/queuelstp.hpp>

#include <stdexcept>

bool QueueLstP::IsEmpty() const noexcept {
  return nullptr == head_;
}

void QueueLstP::Pop() noexcept {
  if (!IsEmpty()) {
    Node* deleted = head_;  
    head_ = head_->next;
    delete deleted;
  }
}

void QueueLstP::Push(const float& val) {
  if (IsEmpty()) {
    head_ = new Node{ val };
  } else {
    // TODO: find and insert
  }
}
  
float& QueueLstP::Top() {
  if (IsEmpty()) {
    throw std::logic_error("QueueLstP - try get top form empty queue.");
  }
  return head_->val;
}

const float& QueueLstP::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("QueueLstP - try get top form empty queue.");
  }
  return head_->val;
}

void QueueLstP::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}
