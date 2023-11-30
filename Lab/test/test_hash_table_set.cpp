#include <cassert>
#include <CSCE221H/hash_table_set.hpp>
#include <CSCE221H/avl_set.hpp>
#include <CSCE221H/naive_set.hpp>
#include <chrono>
#include <set>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

int main(int argc, char **argv) {
    CSCE221H::hash_table_set<int> hash_in_order;

    int n = 1;

    auto start = std::chrono::high_resolution_clock::now(); // hash in-order insertion
    for (int i = 0; i < n; i++) {
        hash_in_order.insert(i);
    }
    auto end = high_resolution_clock::now();
    duration<double, std::milli> elapsed = end - start;

    std::cout << "Chaining hash table in-order insertion time: " << elapsed.count() << " milliseconds" << std::endl;

    return 0;
}