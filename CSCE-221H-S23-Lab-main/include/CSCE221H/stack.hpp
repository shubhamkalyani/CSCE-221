#pragma once

#include <cstddef>
#include <iostream>
#include <CSCE221H/vector.hpp>

namespace CSCE221H {

template <typename T> class stack {
  public:
    using value_type = T;

    stack() {
      vector<T> s;
    }

    void push(const T &value) {
      s.push_back(value);
    }

    void pop() {
      if (s.size() == 0) {
        return;
      }
      s.pop_back();
    }

    T &top() {
      return s.back();
    }

    void clear() {
      s.clear();
    }

    void swap(stack& x) {
      s.swap(x.s);
    }

    size_t size() {
      return s.size();
    }

    bool empty() const {
      if (s.size() == 0) {
        return true;
      }
      return false;
    }

    private:
      vector<T> s;
};

} // namespace CSCE221H