#include <cassert>
#include <CSCE221H/naive_set.hpp>
#include <chrono>
#include <set>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

int main(int argc, char **argv) {

    CSCE221H::naive_set<int> bst_in_order;
    CSCE221H::naive_set<int> bst_random;

    std::set<int> set_in_order;
    std::set<int> set_random;

    // assert(bst.size() == 0);

    // bst.insert(0);
    // assert(bst.size() == 1);
    // assert(bst.contains(0));

    // bst.insert(0);
    // assert(bst.size() == 1);
    // assert(bst.contains(0));

    // bst.insert(1);
    // assert(bst.size() == 2);
    // assert(bst.contains(0));

    // bst.erase(0);
    // assert(bst.size() == 1);
    // assert(bst.contains(1));

    // output log in CSCE-221H-S23-LAB/build/Testing/Temporary/LastTest.log

    int n = 1000;

    auto start = std::chrono::high_resolution_clock::now(); // bst in-order insertion
    for (int i = 0; i < n; i++) {
        bst_in_order.insert(i);
    }
    auto end = high_resolution_clock::now();
    duration<double, std::milli> elapsed = end - start;

    std::cout << "Naive BST in-order insertion time: " << elapsed.count() << " milliseconds" << std::endl;

    start = std::chrono::high_resolution_clock::now(); // set in-order insertion
    for (int i = 0; i < n; i++) {
        set_in_order.insert(i);
    }
    end = high_resolution_clock::now();
    elapsed = end - start;

    std::cout << "Set in-order insertion time: " << elapsed.count() << " milliseconds" << std::endl;

    srand(time(0));

    start = std::chrono::high_resolution_clock::now(); // bst random insertion
    for (int i = 0; i < n; i++) {
        bst_random.insert(rand());
    }
    end = high_resolution_clock::now();
    elapsed = end - start;

    std::cout << "Naive BST random insertion time: " << elapsed.count() << " milliseconds" << std::endl;

    start = std::chrono::high_resolution_clock::now(); // set random insertion
    for (int i = 0; i < n; i++) {
        set_random.insert(rand());
    }
    end = high_resolution_clock::now();
    elapsed = end - start;

    std::cout << "Set random insertion time: " << elapsed.count() << " milliseconds" << std::endl;
}
