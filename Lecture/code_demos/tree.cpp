#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

class tree {
private:
  struct node {
    node(std::string _name) : name(_name) {}
    std::string name;
    std::vector<node> children;
  };

public:
  tree(const std::string &root_name) : root_node(root_name) {}

  void insert(const std::vector<std::string> &path) {
    assert(not path.empty());
    assert(root_node.name == path[0]);
    node *pcurent_node = &root_node;
    for (size_t p = 1; p < path.size(); ++p) {
      // path[p] is child name we are searching for
      bool child_found(false);
      for (auto &child : pcurent_node->children) {
        if (child.name == path[p]) {
          // found child in existing tree
          pcurent_node = &child;
          child_found = true;
          break;
        }
      }
      if (not child_found) {
        // std::cout << "I'm inserting " << path[p] << std::endl;
        pcurent_node->children.push_back(node(path[p]));
        pcurent_node = &(pcurent_node->children.back());
      }
    }
  }

  template <typename Lambda> void for_each_preorder_recursive(Lambda l) {
    preorder_recursive(l, root_node);
  }

  template <typename Lambda> void for_each_postorder_recursive(Lambda l) {
    postorder_recursive(l, root_node);
  }

  template <typename Lambda> void for_each_preorder_nonrecursive(Lambda l) {
    std::stack<node *> node_stack;
    node_stack.push(&root_node);

    while (not node_stack.empty()) {
      // when to pop the stack?
      node *top = node_stack.top();
      l(top->name);
      node_stack.pop();
      for (auto &child : top->children) {
        // What should we do with the children?
        node_stack.push(&child);
      }
    }
  }

  template <typename Lambda> void for_each_bfs_nonrecursive(Lambda l) {
    std::stack<node *> node_stack;
    std::queue<node *> node_stack2;

    node_stack.push(&root_node);
    node_stack2.push(&root_node);

    while (not node_stack.empty()) {
      // when to pop the stack?
      node *top = node_stack.top();
      node_stack.pop();
      for (auto &child : top->children) {
        // What should we do with the children?
        node_stack.push(&child);
        node_stack2.push(&child);
      }
    }

    while (not node_stack2.empty()) {
      l(node_stack2.front()->name);
      node_stack2.pop();
    }
  }

  template <typename Lambda>
  void for_each_class_attempt_nonrecursive(Lambda l) {
    std::queue<node *> node_queue;

    node_queue.push(&root_node);

    while (not node_queue.empty()) {
      // when to pop the stack?
      node *top = node_queue.front();
      l(top->name);
      node_queue.pop();
      for (auto &child : top->children) {
        // What should we do with the children?
        node_queue.push(&child);
      }
    }
  }

  //
  // 2 stack approach for a nonrecursive postorder visit
  template <typename Lambda> void for_each_postorder_nonrecursive(Lambda l) {
    std::stack<node *> stack1;
    std::stack<node *> stack2;

    stack1.push(&root_node);

    while (not stack1.empty()) {
      // when to pop the stack?
      node *top = stack1.top();
      stack2.push(top);
      stack1.pop();
      for (auto &child : top->children) {
        // What should we do with the children?
        stack1.push(&child);
      }
    }

    while (not stack2.empty()) {
      l(stack2.top()->name);
      stack2.pop();
    }
  }

private:
  // recursive function goes here
  template <typename Lambda> void preorder_recursive(Lambda l, node &cnode) {
    // pre-order means lambda goes BEFORE recursion
    l(cnode.name);
    for (auto &child : cnode.children) {
      preorder_recursive(l, child);
    }
  }

  // recursive function goes here
  template <typename Lambda> void postorder_recursive(Lambda l, node &cnode) {
    for (auto &child : cnode.children) {
      postorder_recursive(l, child);
    }
    // post-order means lambda goes AFTER recursion
    l(cnode.name);
  }

  node root_node;
};

int main(int argc, char **argv) {

  tree t("A");

  t.insert({"A", "B", "D"});
  t.insert({"A", "B", "E", "G"});
  t.insert({"A", "B", "E", "H"});
  t.insert({"A", "C", "F"});

  std::cout << " == PRE ORDER == " << std::endl;
  t.for_each_preorder_recursive(
      [](const std::string &name) { std::cout << name << std::endl; });

  std::cout << " == POST ORDER == " << std::endl;
  t.for_each_postorder_recursive(
      [](const std::string &name) { std::cout << name << std::endl; });

  std::cout << " == PRE ORDER NOT RECURSIVE ==" << std::endl;
  t.for_each_preorder_nonrecursive(
      [](const std::string &name) { std::cout << name << std::endl; });

  std::cout << " == POST ORDER NOT RECURSIVE ==" << std::endl;
  t.for_each_postorder_nonrecursive(
      [](const std::string &name) { std::cout << name << std::endl; });
  return 0;
}