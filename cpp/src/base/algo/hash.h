#ifndef BASE_ALGO_HASH_H_
#define BASE_ALGO_HASH_H_

#include <cstdint>

namespace zoptimizer_base {

// Given a key and the number of the buckets, return which bucket should this
// key belongs to. This algorithm is invented by Google:
//   "A Fast, Minimal Memory, Consistent Hash Algorithm"
//   https://arxiv.org/pdf/1406.2294
inline std::int32_t JumpConsistentHash(std::uint64_t key, std::int32_t num_buckets) {
  std::int64_t b = -1, j = 0;
  while (j < num_buckets) {
    b = j;
    key = key * 2862933555777941757ULL + 1;
    // double(...) here serves as a determined rand generator
    j = (b + 1) * (double(1LL << 31) / double((key >> 33) + 1));
  }
  return b;
}

}

#endif  // BASE_ALGO_HASH_H_