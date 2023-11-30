#pragma once

#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <memory>

using std::shared_ptr;

namespace CSCE221H {

template <typename T> class naive_set {
  public:
    using value_type = T;

    struct Node {
        T data;
        shared_ptr<Node> left, right;
        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };
    
    naive_set() : m_size(0), m_root(nullptr) {}
    
    void insert(const T& value) {
        m_root = insertHelper(m_root, value);
    }
    
    bool contains(const T& value) const {
        return containsHelper(m_root, value);
    }
    
    size_t size() const {
        return m_size;
    }
    
    void erase(const T& value) {
        m_root = eraseHelper(m_root, value);
    }
    
    void for_each(std::function<void(const T&)> fn) const {
        for_eachHelper(m_root, fn);
    }
    
    private:
        shared_ptr<Node> m_root;
        size_t m_size;
    
    shared_ptr<Node> insertHelper(shared_ptr<Node> node, const T& value) {
        if (!node) {
            ++m_size;
            return std::make_shared<Node>(value);
        }
        
        if (value < node->data) {
            node->left = insertHelper(node->left, value);
        } else if (value > node->data) {
            node->right = insertHelper(node->right, value);
        }
        return node;
    }
    
    bool containsHelper(shared_ptr<Node> node, const T& value) const {
        if (!node) {
            return false;
        }
        
        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return containsHelper(node->left, value);
        } else {
            return containsHelper(node->right, value);
        }
    }
    
    shared_ptr<Node> eraseHelper(shared_ptr<Node> node, const T& value) {
        if (!node) {
            return node;
        }
        
        if (value < node->data) {
            node->left = eraseHelper(node->left, value);
        }
        else if (value > node->data) {
            node->right = eraseHelper(node->right, value);
        }
        else {
            if (!node->left && !node->right) {
                node.reset();
            } else if (!node->left) {
                node = node->right;
            } else if (!node->right) {
                node = node->left;
            } else {
                std::shared_ptr<Node> minRight = node->right;
                while (minRight->left) {
                    minRight = minRight->left;
                }
                node->data = minRight->data;
                node->right = eraseHelper(node->right, minRight->data);
            }
            --m_size;
        }
        return node;
    }
    
    void for_eachHelper(shared_ptr<Node> node, std::function<void(const T&)> fn) const {
        if (node) {
            for_eachHelper(node->left, fn);
            fn(node->data);
            for_eachHelper(node->right, fn);
        }
    }
};

} // namespace CSCE221H