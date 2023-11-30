# 221H Lab 5

## DUE DATE
* Friday March 24 prior to lab (3 weeks).
* WARNING:  This is the most complex lab to date, start early and commit often!
    * You can refer to the textbook and/or internet for help with AVL tree rotations.
    * https://www.cs.usfca.edu/~galles/visualization/AVLtree.html

## Objectives
* Implement your own **AVL** tree that is templated.  Provide the following *set* interface (same as your naive_set.cpp in Lab 4):
    * insert(T)
    * bool contains(T) const
    * size_t size() const
    * void erase(T)
    * for_each(Function fn)
* Evaluate your AVL tree using in-order and random data by timing the insertion of N elements, where you vary N, and compare to your naive_set from Lab 4.
* Use recursion to implement all tree traversals.   You may choose to use a parent pointer, but it is not required or recommended.
* Use std::shared_ptr for all node pointers.
* Evaluate your AVL using in-order and random data by timing the insertion of N elements, where you vary N.


## Deliverables
* Implement your naive set in a file called **include/CSCE221H/avl_set.hpp**
* Implement your tests in a file called **test/test_avl_set.cpp**
* Evaluate the performance of your implementations using in-order and random-order insertions, removals and queries
* Vary the size of your container between small to large (size may depend on your system's memory)
* Plot the performance of insertion, queries and removals as a function of N, and compare performance to Lab 4's naive_set.hpp and std::set.
* A writeup of your evaluation should be placed below.

## Rubric
* 60pts for your overall AVL implementation (avl_set.hpp) graded on correctness.  (Test your implementation with your own insertion/deletion/query orders).
* 40pts for performance evaluation of avl_set, naive_set, std::set.
    * Compare avl_set and std::set together using 1 plot for insert/erase/contains.

## Evaluation
![image](https://user-images.githubusercontent.com/65512390/227645675-b672ce95-9853-48c5-b7a6-550e60c78513.png)
![image](https://user-images.githubusercontent.com/65512390/227645580-43b61e72-e0e3-4e43-8833-f1fdf4babbbc.png)
