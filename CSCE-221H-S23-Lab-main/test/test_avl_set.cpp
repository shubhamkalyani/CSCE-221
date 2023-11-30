#include <cassert>
#include <CSCE221H/avl_set.hpp>
#include <CSCE221H/naive_set.hpp>
#include <chrono>
#include <set>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

int main(int argc, char **argv) {

    CSCE221H::avl_set<int> avl_in_order;
    CSCE221H::avl_set<int> avl_random;

    CSCE221H::naive_set<int> naive_in_order;
    CSCE221H::naive_set<int> naive_random;

    std::set<int> set_in_order;
    std::set<int> set_random;

    // output log in CSCE-221H-S23-LAB/build/Testing/Temporary/LastTest.log

    int n = 1;
    int max = n * 100;

    auto start = std::chrono::high_resolution_clock::now(); // avl in-order insertion
    // for (int i = 0; i < n; i++) {
    //     avl_in_order.insert(i);
    // }
    auto end = high_resolution_clock::now();
    duration<double, std::milli> elapsed = end - start;

    // std::cout << "AVL in-order insertion time: " << elapsed.count() << " milliseconds" << std::endl;

    // start = std::chrono::high_resolution_clock::now(); // naive in-order insertion
    // for (int i = 0; i < n; i++) {
    //     set_in_order.insert(i);
    // }
    // end = high_resolution_clock::now();
    // elapsed = end - start;
    // std::cout << "Set in-order insertion time: " << elapsed.count() << " milliseconds" << std::endl;

    srand(time(0));

    int x;

    start = std::chrono::high_resolution_clock::now(); // avl random insertion
    for (int i = 0; i < n; i++) {
        x = rand() % max;
        avl_random.insert(x);
    }
    end = high_resolution_clock::now();
    elapsed = end - start;
    //std::cout << "AVL random insertion time: " << elapsed.count() << " milliseconds" << std::endl;

    start = std::chrono::high_resolution_clock::now(); // naive random insertion
        for (int i = 0; i < n; i++) {
            x = rand() % max;
            naive_random.insert(x);
            //std::cout << x << std::endl;
        }
    end = high_resolution_clock::now();
    elapsed = end - start;
    //std::cout << "Naive BST random insertion time: " << elapsed.count() << " milliseconds" << std::endl;

    start = std::chrono::high_resolution_clock::now(); // set random insertion
        for (int i = 0; i < n; i++) {
            x = rand() % max;
            set_random.insert(x);
        }
    end = high_resolution_clock::now();
    elapsed = end - start;
    //std::cout << "Set random insertion time: " << elapsed.count() << " milliseconds" << std::endl;
        
    duration<double, std::milli> avl_total;
    for (int i = 0; i < n; i++) {
        //std::cout << "run " << i << std::endl;
        start = std::chrono::high_resolution_clock::now(); // avl random query
        avl_random.contains(rand() % max);
        end = high_resolution_clock::now();
        elapsed = end - start;
        avl_total += elapsed;
    }
    avl_total /= n;
    //std::cout << "AVL random query time: " << avl_total.count() << " milliseconds" << std::endl;

    duration<double, std::milli> set_total;
    for (int i = 0; i < n; i++) {
        //std::cout << "run " << i << std::endl;
        start = std::chrono::high_resolution_clock::now(); // set random query
        while (set_random.find(rand() % max) != set_random.end()) {
            //std::cout << "SET doesnt contain" << std::endl;
        }
        end = high_resolution_clock::now();
        elapsed = end - start;
        set_total += elapsed;
    }
    set_total /= n;
    std::cout << "Set random query time: " << set_total.count() << " milliseconds" << std::endl;

    start = std::chrono::high_resolution_clock::now(); // avl random erase
    for (int i = 0; i < n; i++) {
        avl_random.erase(rand() % max);
    }
    end = high_resolution_clock::now();
    elapsed = end - start;
    //std::cout << "AVL random erase time: " << elapsed.count() << " milliseconds" << std::endl;

    start = std::chrono::high_resolution_clock::now(); // set random erase
    for (int i = 0; i < n; i++) {
        set_random.erase(rand() % max);
    }
    end = high_resolution_clock::now();
    elapsed = end - start;
    //std::cout << "Set random erase time: " << elapsed.count() << " milliseconds" << std::endl;
}
