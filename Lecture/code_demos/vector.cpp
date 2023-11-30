#include <iostream>
#include <vector>

int main(int argc, char **argv) {

  std::vector<int> vec;
  vec.reserve(50);

  for (size_t i = 0; i < 51; ++i) {
    vec.push_back(i);

    std::cout << "Size = " << vec.size() << ", "
              << "Capacity = " << vec.capacity() << std::endl;
  }

  return 0;
}