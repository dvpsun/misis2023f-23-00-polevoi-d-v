// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef STACKLSTT_STACKLSTT_HPP_20240408
#define STACKLSTT_STACKLSTT_HPP_20240408


#include <cstddef>
#include <memory>
#include <stdexcept>

template<class T>
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

  void Push(const T& val);
  
  [[nodiscard]] T& Top() &;

  [[nodiscard]] const T& Top() const &;

  void Clear() noexcept;

private:
  struct Node {
    T val;
    Node* next = nullptr;
  };

  Node* head_ = nullptr;   //!< 
};

template<class T>
StackLstT<T>::StackLstT(const StackLstT<T>& src) {
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

template<class T>
StackLstT<T>::StackLstT(StackLstT<T>&& src) noexcept {
  std::swap(head_, src.head_);
}

template<class T>
StackLstT<T>& StackLstT<T>::operator=(const StackLstT<T>& src) {
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

template<class T>
StackLstT<T>& StackLstT<T>::operator=(StackLstT<T>&& src) noexcept {
  std::swap(head_, src.head_);
  return *this;
}

template<class T>
bool StackLstT<T>::IsEmpty() const noexcept {
  return nullptr == head_;
}

template<class T>
void StackLstT<T>::Pop() noexcept {
  if (!IsEmpty()) {
    Node* deleted = head_;  
    head_ = head_->next;
    delete deleted;
  }
}

template<class T>
void StackLstT<T>::Push(const T& val) {
  head_ = new Node{val, head_};
}

template<class T>
T& StackLstT<T>::Top() & {
  if (IsEmpty()) {
    throw std::logic_error("StackLstT - try get top form empty stack.");
  }
  return head_->val;
}

template<class T>
const T& StackLstT<T>::Top() const & {
  if (IsEmpty()) {
    throw std::logic_error("StackLstT - try get top form empty stack.");
  }
  return head_->val;
}

template<class T>
void StackLstT<T>::Clear() noexcept {
  while (!IsEmpty()) {
    Pop();
  }
}

#endif
