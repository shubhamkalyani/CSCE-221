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

template<typename T> class hash_table_set {
private:
    vector<std::list<T>> table;
    size_t num_elements = 0;

    void resize() {
        std::vector<std::list<T>> new_table(table.size() * 2);

        for (auto& list : table) {
            for (auto& elem : list) {
                size_t index = hash<T>{}(elem) % new_table.size();
                new_table[index].push_back(elem);
            }
        }

        table = std::move(new_table);
    }

public:
    hash_table_set() : table(10) {}

    void insert(const T& elem) {
        if ((double)num_elements / table.size() >= 0.5) {
            resize();
        }

        size_t index = hash<T>{}(elem) % table.size();
        table[index].push_back(elem);
        num_elements++;
    }

    bool contains(const T& elem) const {
        size_t index = hash<T>{}(elem) % table.size();
        for (auto& e : table[index]) {
            if (e == elem) {
                return true;
            }
        }
        return false;
    }

    size_t size() const {
        return num_elements;
    }

    void erase(const T& elem) {
        size_t index = hash<T>{}(elem) % table.size();
        auto& list = table[index];
        for (auto it = list.begin(); it != list.end(); ++it) {
            if (*it == elem) {
                list.erase(it);
                num_elements--;
                return;
            }
        }
    }

    void for_each(std::function<void(const T&)> fn) {
        for (auto& list : table) {
            for (auto& elem : list) {
                fn(elem);
            }
        }
    }

    size_t getCapacity() {
        return table.size();
    }
};

} // namespace CSCE221H