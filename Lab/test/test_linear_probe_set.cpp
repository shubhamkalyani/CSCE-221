#include <cassert>
#include <CSCE221H/linear_probe_set.hpp>
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
    CSCE221H::linear_probe_set<int> linear_in_order;

    duration<double, std::milli> elapsed1;

    srand(time(0));
    
    vector<int> v = {1, 10, 100, 1000, 2500, 5000, 7500, 10000, 15000, 20000, 40000, 60000, 80000, 100000};
    v = {100};

    for (int n : v) {
        for (int i = 0; i < 30; i++) {
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < n; i++) {
                hash_in_order.insert(rand());
            }
            auto end = high_resolution_clock::now();
            elapsed1 += (end - start);        
        }
        std::cout << "chained random insertion time for " << n << " insertions: " << elapsed1.count() / 30 << " milliseconds" << std::endl;

        // duration<double, std::milli> elapsed2;

        // for (int i = 0; i < 3; i++) {
        //     auto start = std::chrono::high_resolution_clock::now();
        //     for (int i = 0; i < n; i++) {
        //         linear_in_order.insert(rand());
        //     }
        //     auto end = high_resolution_clock::now();
        //     elapsed2 += end - start;
        // }
        // std::cout << "linear probe random insertion time for " << n << " insertions: " << elapsed2.count() / 3 << " milliseconds" << std::endl;
    }

    
}