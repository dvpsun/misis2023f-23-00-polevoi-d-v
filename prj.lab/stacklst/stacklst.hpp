// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef STACKLST_STACKLST_HPP_20240213
#define STACKLST_STACKLST_HPP_20240213

#include <complex/complex.hpp>

#include <cstddef>

class StackLst {
public:
  StackLst() = default;

  StackLst(const StackLst&) = default;
  
  ~StackLst() = default;
  
  [[nodiscard]] StackLst& operator=(const StackLst&) = default;

  bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const Complex& val);
  
  [[nodiscard]] Complex& Top();

  [[nodiscard]] const Complex& Top() const;

  void Clear() noexcept;

private:
  struct Node {
    Complex val;
    Node* next = nullptr;
  };

  Node* head_ = nullptr;   //!< 
};

#endif