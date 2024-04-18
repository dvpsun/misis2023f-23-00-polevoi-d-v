// 2024 by Polevoi Dmitry under Unlicense

#include <bitset/bitset.hpp>

#include <iostream>
#include <stdexcept>

BitSet::BitSet(const std::int32_t size)
  : size_(size) {
}

//BitSet::BitAccessor BitSet::operator[](const int32_t idx) {
//  if (idx < 0) {
//    throw std::out_of_range("BitSet::operator[] index is negative");
//  }
//  if (std::ssize(bits_) <= idx) {
//    throw std::out_of_range("BitSet::operator[] index exceeds the maximum allowable value");
//  }
//  return {*this, idx};
//}

bool BitSet::Get(const int32_t idx) const  {
  if (idx < 0) {
    throw std::out_of_range("BitSet::operator[] index is negative");
  }
  if (std::ssize(bits_) <= idx) {
    throw std::out_of_range("BitSet::operator[] index exceeds the maximum allowable value");
  }
  // TODO
  return true;
}


void BitSet::Set(const int32_t idx, const bool val) {
}

void BitSet::Resize(const int32_t size) {
}
  
