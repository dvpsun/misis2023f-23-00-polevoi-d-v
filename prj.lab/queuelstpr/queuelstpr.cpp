// 2024 by Polevoi Dmitry under Unlicense

#include <queuelstpr/queuelstpr.hpp>

#include <stdexcept>

bool QueueLstPr::IsEmpty() const noexcept {
  return nullptr == head_;
}

void QueueLstPr::Pop() noexcept {
  if (!IsEmpty()) {
    Node* deleted = head_;  
    head_ = head_->next;
    delete deleted;
  }
}

void QueueLstPr::Push(const float& val) {
  if (IsEmpty()) {
    head_ = new Node{ val };
  } else {
    // TODO: find and insert
  }
}
  
float& QueueLstPr::Top() {
  if (IsEmpty()) {
    throw std::logic_error("QueueLstPr - try get top form empty queue.");
  }
  return head_->val;
}

const float& QueueLstPr::Top() const {
  if (IsEmpty()) {
    throw std::logic_error("QueueLstPr - try get top form empty queue.");
  }
  return head_->val;
}

void QueueLstPr::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}
