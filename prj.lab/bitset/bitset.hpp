// 2024 by Polevoi Dmitry under Unlicense

#pragma once
#ifndef BITSET_BITSET_HPP_20240318
#define BITSET_BITSET_HPP_20240318

#include <cstdint>
#include <iosfwd>
#include <vector>

class BitSet {
public:
  BitSet() = default;

  BitSet(const BitSet&) = default;

  BitSet(BitSet&&) = default;

  BitSet(const std::int32_t);

  BitSet& operator=(const BitSet&) = default;

  BitSet& operator=(BitSet&&) = default;

  ~BitSet() = default;

  [[nodiscard]] bool operator==(const BitSet& rhs) const noexcept;

  [[nodiscard]] bool operator!=(const BitSet& rhs) const noexcept;

  int32_t Size() const noexcept { return size_; }

  void Resize(const int32_t size); // 0 < size

  [[nodiscard]] bool Get(const int32_t idx) const;

  void Set(const int32_t idx, const bool val);

  void Fill(const bool val) noexcept;

  [[nodiscard]] BitSet& operator&=(const BitSet& rhs);

  [[nodiscard]] BitSet& operator|=(const BitSet& rhs);

  [[nodiscard]] BitSet& operator^=(const BitSet& rhs);

  [[nodiscard]] BitSet operator~();

  // ? operator[](const int32_t) - what can return
  // std::ostream& WriteTxt(std::ostream&)
  // std::ostream& WriteBinary(std::ostream&)
  // std::istream& ReadTxt(std::istream&)
  // std::istream& RaadBinary(std::istream&)
private:
  std::int32_t size_ = 0;
  std::vector<uint32_t> bits_;
};

// std::ostream& operaror<<(std::ostream&, const BitSet&);
// std::istream& operaror>>(std::istream&, BitSet&);

[[nodiscard]] BitSet operator&(const BitSet& lhs, const BitSet& rhs);

[[nodiscard]] BitSet operator|(const BitSet& lhs, const BitSet& rhs);

[[nodiscard]] BitSet operator^(const BitSet& lhs, const BitSet& rhs);

#endif
