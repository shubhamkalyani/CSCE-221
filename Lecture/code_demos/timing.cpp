#include <chrono> // see:  https://en.cppreference.com/w/cpp/chrono
#include <iostream>
#include <random> // see:  https://cplusplus.com/reference/random/
#include <set>
// using namespace std;   // I avoid this
namespace chrono = std::chrono;

//
//  This program takes no command line arguments and
//  simply measures the time of a 10 second sleep.
//
int main(int argc, char **argv) {

  std::cout << "Howdy from example_timer.cpp" << std::endl;

  size_t test_size = 1e7;
  std::set<size_t> int_set;

  //
  // Random Sequence Setup
  std::default_random_engine generator(42);
  std::uniform_int_distribution<size_t> distribution(0, 1e12);
  std::vector<size_t> test_sequence;
  for (size_t i = 0; i < test_size; ++i) {
    // For Sequential
    // test_sequence.push_back(i);

    // For Random
    test_sequence.push_back(distribution(generator));
  }

  //
  // Test insertion into set
  auto start_time = chrono::high_resolution_clock::now();
  {
    for (size_t val : test_sequence) {
      int_set.insert(val);
    }
  }
  auto end_time = chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed = end_time - start_time;

  std::cout << "I took " << elapsed.count() << " seconds." << std::endl;

  return 0;
}