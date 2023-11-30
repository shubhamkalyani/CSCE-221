#include <functional>
#include <iostream>
#include <string>

int main(int argc, char **argv) {

  std::hash<std::string> string_hasher;

  std::string bob = "Bob";
  size_t bob_hash = string_hasher(bob);

  std::cout << "Hash of " << bob << " = " << bob_hash << std::endl;

  std::cout << "Hash of Howdy Aggs = " << std::hash<std::string>{}("Howdy Aggs")
            << std::endl;

  std::cout << "Hash of 17 = " << std::hash<int>{}(17) << std::endl;

  std::cout << "Hash of \"17\" = " << std::hash<std::string>{}("17")
            << std::endl;

  return 0;
}