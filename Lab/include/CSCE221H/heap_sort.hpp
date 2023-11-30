#pragma once

#include <iostream>
#include <iterator>
#include <algorithm>

template <typename RandomIt, typename Compare>
void heap_sort(RandomIt first, RandomIt last, Compare comp) {
  size_t n = std::distance(first, last);

  for (size_t i = n / 2; i > 0; --i) {
    size_t parent = i - 1;
    size_t largest = parent;

    while (true) {
      size_t left = parent * 2 + 1;
      size_t right = left + 1;

      if (left < n && comp(*(first + largest), *(first + left))) {
        largest = left;
      }
      if (right < n && comp(*(first + largest), *(first + right))) {
        largest = right;
      }
      if (largest != parent) {
        std::iter_swap(first + parent, first + largest);
        parent = largest;
      } else {
        break;
      }
    }
  }

  for (size_t i = n; i > 1; --i) {
    std::iter_swap(first, first + i - 1);

    size_t parent = 0;
    size_t largest = parent;

    while (true) {
      size_t left = parent * 2 + 1;
      size_t right = left + 1;

      if (left < i - 1 && comp(*(first + largest), *(first + left))) {
        largest = left;
      }
      if (right < i - 1 && comp(*(first + largest), *(first + right))) {
        largest = right;
      }
      if (largest != parent) {
        std::iter_swap(first + parent, first + largest);
        parent = largest;
      } else {
        break;
      }
    }
  }

  size_t dist = std::distance(first, last);
  std::cout << "dist = " << dist << std::endl;
  std::cout << "*(first + 5) = " << *(first + 5) << std::endl;
}
