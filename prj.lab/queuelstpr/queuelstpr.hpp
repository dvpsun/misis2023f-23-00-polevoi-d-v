// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef QUEUELSTPR_QUEUELSTPR_HPP_20240307
#define QUEUELSTPR_QUEUELSTPR_HPP_20240307

#include <cstddef>

class QueueLstPr {
public:
  QueueLstPr() = default;

  QueueLstPr(const QueueLstPr&) = default;
  QueueLstPr(QueueLstPr&&) = default;
  
  ~QueueLstPr() = default;
  
  [[nodiscard]] QueueLstPr& operator=(const QueueLstPr&) = default;
  [[nodiscard]] QueueLstPr& operator=(QueueLstPr&&) = default;

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
