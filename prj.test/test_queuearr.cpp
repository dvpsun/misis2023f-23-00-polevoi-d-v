// 2024 by Polevoi Dmitry under Unlicense

#include <queuearr/queuearr.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <cstdint>
#include <chrono>
#include <utility>

TEST_CASE("[queuearr] - ctor") {
  QueueArr qu;
  CHECK(qu.IsEmpty());
}

TEST_CASE("[queuearr] - ctor copy") {
  QueueArr qu;
}

inline double MeasureTimeCtorMove(const int pushed_count) {
  QueueArr qu_src;
  for (double v = 0.0; v < pushed_count; v += 1.0) {
    qu_src.Push({v, v});
  }
  const auto t_beg = std::chrono::steady_clock::now();
  QueueArr qu_tgt = std::move(qu_src);
  const auto t_end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> diff = t_end - t_beg;
  return diff.count();
}

TEST_CASE("[queuearr] - ctor move") {
  QueueArr qu_src;
  QueueArr qu_tgt = std::move(qu_src);
  if (!qu_src.IsEmpty() && !qu_tgt.IsEmpty()) {
    CHECK(qu_src.Top() != qu_tgt.Top());
  }
  const auto t_0099 = MeasureTimeCtorMove(99);
  const auto t_9999 = MeasureTimeCtorMove(9999);
  std::cout << t_0099 << " " << t_9999 << std::endl;
  CHECK(t_0099 == t_0099);
}

TEST_CASE("[queuearr] - operator= move") {
  QueueArr qu_src;
  QueueArr qu_tgt;
  qu_tgt = std::move(qu_src);

  //  CHECK(qu_src.Top() != qu_tgt.Top());
}
