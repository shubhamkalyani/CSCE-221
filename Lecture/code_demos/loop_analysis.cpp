int N = argv[1]; // user input

size_t sum = 0;
// for (size_t i = 0; i < N; ++i) {
//   for (size_t j = i; j < N; ++j) {
//     sum++;
//     do_something(); // assume constant
//   }
// }
// for (size_t k = 0; k < N; ++k) {
//   sum++;
// }
// for (size_t k = 0; k < N; ++k) {
//   sum++;
// }
// sum++;

for (size_t i = 1; i < N; i *= 2) {
  for (size_t k = 0; k < N; ++k) {
    sum++;
  }
}
// for(size_t i=N; i>1; i/=2) {

// }
// O(lg(n))

// Binary Search
template <typename RandomAccessIterator>
bool binary_search(RandomAccessIterator begin, RandomAccessIterator end,
                   int value) {
  if (begin == end)
    return false;
  RandomAccessIterator itr = begin + std::distance(begin, end) / 2;
  if (value < *itr) {
    return binary_search(begin, itr, value);
  } else if (value > *itr) {
    return binary_search(itr + 1, end, value);
  } else {
    return true;
  }
}