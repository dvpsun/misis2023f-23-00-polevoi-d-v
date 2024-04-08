#include <stacklstt/stacklstt.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <cstdint>
#include <string>

TEST_CASE("[stacklstt] - ctor") {
  StackLstT<float> stf;
  StackLstT<int> sti;
  StackLstT<std::string> sts;
}
