#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

#include <CSCE221H/heap_sort.hpp>

int main(int argc, char **argv) {

  const size_t N = 7500; //1000000

  //
  // Generate random numbers for input
  std::vector<size_t> the_input;
  std::mt19937 mt(0);
  std::uniform_int_distribution<size_t> dist(0, std::numeric_limits<size_t>::max());

  for (size_t i = N; i > 0; --i) {
    the_input.push_back(i);
  }
  
  //
  // Call std::sort
  auto start = std::chrono::high_resolution_clock::now();

  std::sort(the_input.begin(), the_input.end(), std::less<size_t>());
  //heap_sort(the_input.begin(), the_input.end(), std::less<size_t>());

  auto end = high_resolution_clock::now();
  duration<double, std::milli> elapsed = end - start;
  std::cout << "Sort() sort random time: " << elapsed.count() << " milliseconds" << std::endl;

  //
  // Check if sorted
  assert(std::is_sorted(the_input.begin(), the_input.end(), std::less<size_t>()));

  return 0;
}