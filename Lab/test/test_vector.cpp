#include <CSCE221H/vector.hpp>
#include <cassert>

int main(int argc, char **argv) {

  CSCE221H::vector<int> vec;

  vec.push_back(1);
  assert(vec.size() == 1);
  assert(vec.capacity() == 1);
  // {1}

  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  assert(vec.size() == 4);
  assert(vec.capacity() == 4);
  // {1 ,2, 3, 4}

  vec.push_back(5);
  assert(vec.size() == 5);
  assert(vec.capacity() == 8);
  // {1, 2, 3, 4, 5, _, _, _}

  vec.pop_back();
  assert(vec.size() == 4);
  // {1, 2, 3, 4, _, _, _, _}

  vec.pop_back();
  assert(vec.size() == 3);
  assert(vec.capacity() == 8);
  // {1, 2, 3, _, _, _, _, _}

  vec.shrink_to_fit();
  assert(vec.size() == 3);
  assert(vec.capacity() == 3);
  // {1, 2, 3}
 
  assert(vec.back() == 3);
  assert(vec.front() == 1);
  assert(vec[0] == 1);
  assert(vec[1] == 2);
  assert(vec[2] == 3);
  assert(vec.size() == 3);
  assert(vec.capacity() == 3);

  vec.assign(2, 10);
  assert(vec[0] == 10);
  assert(vec[1] == 10);
  assert(vec[2] == 3);
  assert(vec.size() == 3);
  assert(vec.capacity() == 3);
  // {10, 10, 3}

  vec.assign(10, 100);
  assert(vec[0] == 100);
  assert(vec[1] == 100);
  assert(vec[2] == 100);
  assert(vec[3] == 100);
  assert(vec[4] == 100);
  assert(vec[5] == 100);
  assert(vec[6] == 100);
  assert(vec[7] == 100);
  assert(vec[8] == 100);
  assert(vec[9] == 100);
  assert(vec.size() == 10);
  assert(vec.capacity() == 10);
  // {100, 100, 100, 100, 100, 100, 100, 100, 100, 100}

  vec.clear();
  assert(vec[0] == 0);
  assert(vec[1] == 0);
  assert(vec[2] == 0);
  assert(vec[3] == 0);
  assert(vec[4] == 0);
  assert(vec[5] == 0);
  assert(vec[6] == 0);
  assert(vec[7] == 0);
  assert(vec[8] == 0);
  assert(vec[9] == 0);
  assert(vec.size() == 0);
  assert(vec.capacity() == 10);

  CSCE221H::vector<int> s1;
  CSCE221H::vector<int> s2;

  s1.assign(3, 9);
  assert(s1.size() == 3);
  assert(s1[0] == 9);
  s2.assign(2, 8);
  assert(s2.size() == 2);
  assert(s2[0] == 8);

  s1.swap(s2);

  assert(s1.size() == 2);
  assert(s1[0] == 8);
  assert(s2.size() == 3);
  assert(s2[0] == 9);

  return 0;
}