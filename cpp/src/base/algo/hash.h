#ifndef SRC_BASE_ALGO_HASH_H_
#define SRC_BASE_ALGO_HASH_H_

#include <cstdint>

namespace zopt_base {

// Given a key and the number of the buckets, return which bucket should this
// key belongs to. This algorithm is invented by Google:
//   "A Fast, Minimal Memory, Consistent Hash Algorithm"
//   https://arxiv.org/pdf/1406.2294
inline std::int32_t JumpConsistentHash(std::uint64_t key, std::int32_t num_buckets) {
  std::int64_t b = -1, j = 0;
  while (j < num_buckets) {
    b = j;
    // determined pseudo rand generator
    key = key * 2862933555777941757ULL + 1;  // srand(key)
    j = (b + 1) * (double(1LL << 31) / double((key >> 33) + 1));  // rand()
  }
  return b;
}

}

#endif  // SRC_BASE_ALGO_HASH_H_