#pragma once

#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <memory>
#include <list>
#include <functional>

using std::vector;
using std::hash;

namespace CSCE221H {

template<typename T> class linear_probe_set {
private:
    std::vector<T> table;
    std::vector<bool> occupied;
    size_t count;

    void rehash(size_t new_capacity) {
        std::vector<T> new_table(new_capacity);
        std::vector<bool> new_occupied(new_capacity, false);

        for (size_t i = 0; i < table.size(); i++) {
            if (occupied[i]) {
                size_t j = hash<T>{}(table[i]) % new_capacity;
                while (new_occupied[j]) {
                    j = (j + 1) % new_capacity;
                }
                new_table[j] = table[i];
                new_occupied[j] = true;
            }
        }

        table = new_table;
        occupied = new_occupied;
    }

public:
    linear_probe_set(size_t initial_capacity = 10) : table(initial_capacity), occupied(initial_capacity, false), count(0) {}

    void insert(const T& value) {
        if ((double)count / table.size() >= 0.5) {
            rehash(table.size() * 2);
        }

        size_t i = hash<T>{}(value) % table.size();
        while (occupied[i]) {
            if (table[i] == value) {
                return;
            }
            i = (i + 1) % table.size();
        }

        table[i] = value;
        occupied[i] = true;
        count++;
    }

    bool contains(const T& value) const {
        size_t i = hash<T>{}(value) % table.size();
        while (occupied[i]) {
            if (table[i] == value) {
                return true;
            }
            i = (i + 1) % table.size();
        }
        return false;
    }

    size_t size() const {
        return count;
    }

    void erase(const T& value) {
        size_t i = hash<T>{}(value) % table.size();
        while (occupied[i]) {
            if (table[i] == value) {
                occupied[i] = false;
                count--;
                return;
            }
            i = (i + 1) % table.size();
        }
    }

    void for_each(std::function<void(const T&)> fn) const {
        for (size_t i = 0; i < table.size(); i++) {
            if (occupied[i]) {
                fn(table[i]);
            }
        }
    }

    size_t getCapacity() {
        return table.size();
    }
};

} // namespace CSCE221H