#include <CSCE221H/stack.hpp>
#include <cassert>

int main(int argc, char **argv) {
  
  CSCE221H::stack<int> vec;

  vec.push(1);
  assert(vec.size() == 1);
  // {1}

  vec.push(2);
  vec.push(3);
  vec.push(4);
  assert(vec.size() == 4);
  // {1 ,2, 3, 4}

  vec.push(5);
  assert(vec.size() == 5);
  // {1, 2, 3, 4, 5, _, _, _}

  vec.pop();
  assert(vec.size() == 4);
  // {1, 2, 3, 4, _, _, _, _}

  vec.pop();
  assert(vec.size() == 3);
  assert(vec.top() == 3);
  // {1, 2, 3, _, _, _, _, _}

  vec.clear();
  assert(vec.size() == 0);
  assert(vec.empty());

  CSCE221H::stack<int> s1;
  CSCE221H::stack<int> s2;

  s1.push(9);
  s1.push(9);
  s1.push(9);
  assert(s1.size() == 3);
  assert(s1.top() == 9);
  s2.push(8);
  s2.push(8);
  assert(s2.size() == 2);
  assert(s2.top() == 8);

  s1.swap(s2);

  assert(s1.size() == 2);
  assert(s1.top() == 8);
  assert(s2.size() == 3);
  assert(s2.top() == 9);
 
  return 0;
}