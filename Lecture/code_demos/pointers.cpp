#include <iostream>
#include <memory>
#include <string>

struct node {
  node(const std::string _name) : name(_name) {
    std::cout << "Constructor -- " << name << std::endl;
  }
  ~node() {
    //
    std::cout << "Destructor -- " << name << std::endl;
  }

  void print() { std::cout << "Print() -- " << name << std::endl; }

  std::string name;
};

int main(int argc, char **argv) {

  //
  //  Raw Pointers
  // {
  //   node *n1 = new node("Howdy");

  //   {
  //     // BST::delete code here
  //     node *node_to_delete = n1;
  //     n1 = nullptr;
  //     delete node_to_delete;
  //     node_to_delete = nullptr;
  //   }

  //   if (n1) {
  //     n1->print();
  //   }

  //   if (n1) {
  //     delete n1;
  //   }
  // }

  {
    // Shared Pointer Example
    std::shared_ptr<node> sp(new node("Shared"));
    std::cout << "sp.use_count()1 = " << sp.use_count() << std::endl;
    {
      // BST::delete code here
      std::shared_ptr<node> node_to_delete = sp;
      std::cout << "sp.use_count()2 = " << sp.use_count() << std::endl;
      node_to_delete.reset();
      std::cout << "sp.use_count()3 = " << sp.use_count() << std::endl;
      sp = nullptr;
      std::cout << "I've reset the shared pointer" << std::endl;
    }
  }

  return 0;
}