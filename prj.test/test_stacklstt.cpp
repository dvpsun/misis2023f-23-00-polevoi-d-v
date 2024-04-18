#include <stacklstt/stacklstt.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include "utils.hpp"

#include <cstdint>
#include <string>
#include <vector>



#define TYPES int, double, std::string



TEST_CASE_TEMPLATE_DEFINE("[stacklstt] - ctor", T, test_ctor) {
  StackLstT<T> st_def;
}


TEST_CASE_TEMPLATE_DEFINE("[stacklstt] - LIFO", T, test_lifo) {
  StackLstT<T> st;
  std::vector<T> data;
  FillData(40, data);
  for (int i = 0; i < std::ssize(data); i += 1) {
    st.Push(data[i]);
  }
  bool correct_lifo = true;
  for (int i = std::ssize(data) - 1; correct_lifo && 0 <= i; i -= 1) {
    correct_lifo = data[i] == st.Top();
    st.Pop();
  }
  CHECK(correct_lifo);
}



TEST_CASE_TEMPLATE_INVOKE(test_ctor, TYPES);
TEST_CASE_TEMPLATE_INVOKE(test_lifo, TYPES);