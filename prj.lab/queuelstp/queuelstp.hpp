// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef QUEUELSTP_QUEUELSTP_HPP_20240307
#define QUEUELSTP_QUEUELSTP_HPP_20240307

#include <cstddef>

class QueueLstP {
public:
  QueueLstP() = default;

  QueueLstP(const QueueLstP&) = default;
  QueueLstP(QueueLstP&&) = default;
  
  ~QueueLstP() = default;
  
  [[nodiscard]] QueueLstP& operator=(const QueueLstP&) = default;
  [[nodiscard]] QueueLstP& operator=(QueueLstP&&) = default;

  [[nodiscard]] bool IsEmpty() const noexcept;

  void Pop() noexcept;

  void Push(const float& val);
  
  [[nodiscard]] float& Top();

  [[nodiscard]] const float& Top() const;

  void Clear() noexcept;

private:
  struct Node {
    float val;
    Node* next = nullptr;
  };

  Node* head_ = nullptr;   //!< 
};

#endif
