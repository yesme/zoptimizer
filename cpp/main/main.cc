#include <iostream>

#include "src/base/algo/hash.h"

int main(int argc, char* argv[]) {
  std::cout << "hello world!" << std::endl;
  std::cout << zopt_base::JumpConsistentHash(10, 5) << std::endl;
  return 0;
}
