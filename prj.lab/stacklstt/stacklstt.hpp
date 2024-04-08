// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef StackLstTT_StackLstTT_HPP_20240408
#define StackLstTT_StackLstTT_HPP_20240408


#include <cstddef>
#include <memory>
#include <stdexcept>

/*
class StackLstT final {
public:
  StackLstT() = default;

  StackLstT(const StackLstT& src);

  StackLstT(StackLstT&& src) noexcept;
  
  ~StackLstT() = default;
  
  StackLstT& operator=(const StackLstT& src);

  StackLstT& operator=(StackLstT&& src) noexcept;

  [[nodiscard]] bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);
  
  [[nodiscard]] Complex& Top() &;

  [[nodiscard]] const Complex& Top() const &;

  void Clear() noexcept;

private:
  struct Node {
    Complex val;
    Node* next = nullptr;
  };

  Node* head_ = nullptr;   //!< 
};


StackLstT::StackLstT(const StackLstT& src) {
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

StackLstT::StackLstT(StackLstT&& src) noexcept {
  std::swap(head_, src.head_);
}

StackLstT& StackLstT::operator=(const StackLstT& src) {
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

StackLstT& StackLstT::operator=(StackLstT&& src) noexcept {
  std::swap(head_, src.head_);
  return *this;
}

bool StackLstT::IsEmpty() const noexcept {
  return nullptr == head_;
}

void StackLstT::Pop() noexcept {
  if (!IsEmpty()) {
    Node* deleted = head_;  
    head_ = head_->next;
    delete deleted;
  }
}

void StackLstT::Push(const Complex& val) {
  head_ = new Node{val, head_};
}
  
Complex& StackLstT::Top() & {
  if (IsEmpty()) {
    throw std::logic_error("StackLstT - try get top form empty stack.");
  }
  return head_->val;
}

const Complex& StackLstT::Top() const & {
  if (IsEmpty()) {
    throw std::logic_error("StackLstT - try get top form empty stack.");
  }
  return head_->val;
}

void StackLstT::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}
*/
#endif
