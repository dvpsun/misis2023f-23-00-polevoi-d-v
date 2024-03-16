// 2024 by Polevoi Dmitry under Unlicense

#include <stacklst/stacklst.hpp>

#include <memory>
#include <stdexcept>

StackLst::StackLst(StackLst&& src) noexcept {
  std::swap(head_, src.head_);
}

StackLst& StackLst::operator=(StackLst&& src) noexcept {
  std::swap(head_, src.head_);
  return *this;
}

bool StackLst::IsEmpty() const noexcept {
  return nullptr == head_;
}

void StackLst::Pop() noexcept {
  if (!IsEmpty()) {
    Node* deleted = head_;  
    head_ = head_->next;
    delete deleted;
  }
}

void StackLst::Push(const Complex& val) {
  head_ = new Node{val, head_};
}
  
Complex& StackLst::Top() & {
  if (IsEmpty()) {
    throw std::logic_error("StackLst - try get top form empty stack.");
  }
  return head_->val;
}

const Complex& StackLst::Top() const & {
  if (IsEmpty()) {
    throw std::logic_error("StackLst - try get top form empty stack.");
  }
  return head_->val;
}

void StackLst::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}
