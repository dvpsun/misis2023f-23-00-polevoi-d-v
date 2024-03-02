// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef QUEUELST_QUEUELST_HPP_20240220
#define QUEUELST_QUEUELST_HPP_20240220

#include <complex/complex.hpp>

#include <cstddef>

class QueueLst {
public:
  QueueLst() = default;

  QueueLst(const QueueLst&) = default;

  QueueLst(QueueLst&&) = default;
  
  ~QueueLst() = default;
  
  QueueLst& operator=(const QueueLst&) = default;

  QueueLst& operator=(QueueLst&&) = default;

  [[nodiscard]] bool IsEmpty() const noexcept;

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
  Node* tail_ = nullptr;   //!< 
};

#endif
