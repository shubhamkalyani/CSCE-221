#include <cassert>
#include <iostream>
#include <vector>

template <typename Container> void printer(const Container &c) {
  for (const auto &e : c) {
    std::cout << e << std::endl;
  }
}

template <typename Container>
typename Container::value_type sum_everything(const Container &c) {
  // assert(c.size() > 0);
  typename Container::value_type to_return{0};

  for (const auto &e : c) {
    to_return += e;
  }

  return to_return;
}

template <typename Container> void my_recursion(Container &c) {
  if (c.empty()) {
    return;
  }
  std::cout << "Removing " << c.back() << std::endl;
  c.pop_back();
  my_recursion(c);
}

int main(int argc, char **argv) {

  std::vector<double> myvec_double = {3.14, 2.8, 7.5};

  std::vector<int> myvec_int = {};

  sum_everything(myvec_double);

  sum_everything(myvec_int);

  printer(myvec_double);

  // my_recursion(myvec_double);

  std::vector<double>::iterator itr = myvec_double.begin();
  itr++;
  std::cout << *itr << std::endl;

  return 0;
}