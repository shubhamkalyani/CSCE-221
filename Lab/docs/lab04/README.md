# 221H Lab 4

## DUE DATE
* Friday March 3rd prior to lab.

## Objectives
* Implement your own **naive** Binary Search Tree (BST) that is templated, and save it under the file "/include/CSCE221H/naive_set.hpp".  Provide the following interface:
    * insert(const T& value)              // only inserts unique values
    * bool contains(const T& value) const
    * size_t size() const
    * void erase(const T& value)
    * for_each(Function fn)  // This is an in_order traversal
* Use recursion to implment all tree traverals.   You may choose to use a parent pointer, or to forward the parent node pointer during the recursion ... hint, hint ;)
* Use std::shared_ptr for all node pointers.
* Evaluate your BST using in-order and random data by timing the insertion of N elements, where you vary N.

## Deliverables
* Implement your naive set in a file called **include/CSCE221H/naive_set.hpp**
* Implement your tests in a file called **test/test_naive_set.cpp**
* Evaluate the performance of your implementation using in-order and random-order insertions, removals and queries
    * Vary the size of your container between small to large (size may depend on your system's memory)
    * Plot the performance of insertion, queries and removals as a function of N, and compare performance to std::set<T>
    * Find the size on your compuer where recursion fails with in-order and random-order insertions.
* A writeup of your evaluation should be placed below.

## Rubric
* 50pts for your overall naive_set implementation graded on correctness.  (Test your implementation with your own insertion/deletion/query orders).
* 20pts for performance evaluation of your naive_set as a function of size of your naive_set
* 20pts for performance evaluation of std::set
* 10pts for evaluation of recursion failure

## Evaluation
   Recursion fails at size of 25,000 with in-order insertions and some number more than 100,000,000 with random-order insertions (tests were taking over 5 minutes at size of 100,000,000).
   ![image](https://user-images.githubusercontent.com/65512390/222699053-1a2ec2c8-0eac-466b-a82f-774838ceca85.png)
   ![image](https://user-images.githubusercontent.com/65512390/222699280-f1c3052f-2adc-461a-828d-e33d20adf26e.png)
