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

template<typename T> class avl_set {
public:
    avl_set() : root(nullptr), tree_size(0) {}

    void insert(const T& value) {
        root = insertHelper(root, value);
    }

    bool contains(const T& value) const {
        return containsHelper(root, value);
    }

    size_t size() const {
        return tree_size;
    }

    void erase(const T& value) {
        root = eraseHelper(root, value);
    }

    void for_each(std::function<void(const T&)> fn) const {
        for_eachHelper(root, fn);
    }
private:
    struct Node {
        T value;
        shared_ptr<Node> left;
        shared_ptr<Node> right;
        int height;

        Node(T v) : value(v), left(nullptr), right(nullptr), height(1) {}
    };

    shared_ptr<Node> root;
    size_t tree_size;

    int getHeight(const shared_ptr<Node>& node) const {
        return node ? node->height : 0;
    }

    int getBalance(const shared_ptr<Node>& node) const {
        return getHeight(node->right) - getHeight(node->left);
    }

    void updateHeight(shared_ptr<Node>& node) {
        node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    shared_ptr<Node> rotateLeft(shared_ptr<Node>& node) {
        auto newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;

        updateHeight(node);
        updateHeight(newRoot);

        return newRoot;
    }

    shared_ptr<Node> rotateRight(shared_ptr<Node>& node) {
        auto newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;

        updateHeight(node);
        updateHeight(newRoot);

        return newRoot;
    }

    shared_ptr<Node> balance(shared_ptr<Node>& node) {
        updateHeight(node);

        if (getBalance(node) == 2) {
            if (getBalance(node->right) < 0) {
                node->right = rotateRight(node->right);
            }

            return rotateLeft(node);
        }

        if (getBalance(node) == -2) {
            if (getBalance(node->left) > 0) {
                node->left = rotateLeft(node->left);
            }

            return rotateRight(node);
        }

        return node;
    }

    shared_ptr<Node> insertHelper(shared_ptr<Node>& node, const T& value) {
        if (!node) {
            tree_size++;
            return std::make_shared<Node>(value);
        }

        if (value < node->value) {
            node->left = insertHelper(node->left, value);
        } else if (value > node->value) {
            node->right = insertHelper(node->right, value);
        } else {
            return node;
        }

        return balance(node);
    }

    bool containsHelper(const shared_ptr<Node>& node, const T& value) const {
        if (!node) {
            return false;
        }

        if (value < node->value) {
            return containsHelper(node->left, value);
        } else if (value > node->value) {
            return containsHelper(node->right, value);
        } else {
            return true;
        }
    }

    shared_ptr<Node> getMin(shared_ptr<Node>& node) const {
        if (!node->left) {
            return node;
        }

        return getMin(node->left);
    }

    shared_ptr<Node> eraseHelper(shared_ptr<Node>& node, const T& value) {
        if (!node) {
            return node;
        }

        if (value < node->value) {
            node->left = eraseHelper(node->left, value);
        } else if (value > node->value) {
            node->right = eraseHelper(node->right, value);
        } else {
            if (!node->left || !node->right) {
                auto temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }

                tree_size--;
            } else {
                auto temp = getMin(node->right);
                node->value = temp->value;
                node->right = eraseHelper(node->right, temp->value);
            }
        }

        if (!node) {
            return node;
        }

        return balance(node);
    }

    void for_eachHelper(const shared_ptr<Node>& node, std::function<void(const T&)> fn) const {
        if (!node) {
            return;
        }

        for_eachHelper(node->left, fn);
        fn(node->value);
        for_eachHelper(node->right, fn);
    }


};

} // namespace CSCE221H