# 221H Lab 1

## Objectives
* Your project manager has changed requirements again!
  * Change vector::operator() to vector::operator[]
  * Add vector::swap( another ) that swaps the contents of vectors  
  * Add/update associated tests to test_vector.cpp
* Design a Stack that uses your vector class for data storage and modeled after the C++ interfaces (see https://cplusplus.com/reference/stack/stack/).  Implement the following methods:
  * Stack() -- empty constructor
  * push( value )
  * pop()
  * top()
  * clear()
  * swap (stack)
  * size()
  * empty()
* Design a Queue using your own singly linked list and modeled after the C++ interfaces (see https://cplusplus.com/reference/queue/queue/).  You may use std::shared_ptr if you desire.  Implement the following methods:
  * Queue() -- empty constructor
  * push( value )
  * pop()
  * front()
  * back()
  * clear()
  * swap (queue)
  * size()
  * empty()
* Write your own test_stack.cpp and test_queue.cpp add them to the CMake build system.

---
## Pull Instructor Updates Into Your Branch
* You can use the "sync fork" button in your private fork

---
## Compiling and Testing
* After the cmake we previously ran, you should be able to run `make` and `make test` from the build/directory

---
## Deliverables
* Commit and push your changes to vector.hpp, test_vector.cpp, stack.hpp, test_stack.cpp, queue.hpp, test_queue.cpp to your private fork.
