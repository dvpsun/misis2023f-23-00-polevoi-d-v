// 2024 by Polevoi Dmitry under Unlicense

#include <stacklst/stacklst.hpp>

#include <memory>
#include <stdexcept>

StackLst::StackLst(const StackLst& src) {
  if (!src.IsEmpty()) {
    head_ = new Node{src.Top()};
    Node* p_src = src.head_;
    Node* p_dst = head_;
    while (p_src->next) {
      p_dst->next = new Node{p_src->next->val};
      p_src = p_src->next;
      p_dst = p_dst->next;
    }
  }
}

StackLst::StackLst(StackLst&& src) noexcept {
  std::swap(head_, src.head_);
}

StackLst& StackLst::operator=(const StackLst& src) {
  if (this != &src) {
    if (src.IsEmpty()) {
      Clear();
    } else {
      Node* p_src = src.head_;
      if (IsEmpty()) {
        head_ = new Node{src.head_->val};
      } else {
        head_->val = src.head_->val;
      }
      Node* p_dst = head_;
      while (p_src->next) {
        if (p_dst->next) {
          p_dst->next->val = p_src->next->val;
        } else {
          p_dst->next = new Node{ p_src->next->val };
        }
        p_src = p_src->next;
        p_dst = p_dst->next;
      }
      if (p_dst->next) {
        Node* tail = p_dst->next->next;
        while (p_dst->next) {
          delete p_dst->next;
          p_dst->next = nullptr;
          p_dst = tail;
        }
      }
    }
  }
  return *this;
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
