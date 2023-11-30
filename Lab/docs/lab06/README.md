# 221H Lab 6

## DUE DATE
* Friday March 31 prior to lab (1 week).

## Objectives
* Implement your own **hash table** using *chaining* that is templated.  Provide the following *set* interface (same as your naive_set.hpp and avl_set.hpp):
    * insert(T)
    * bool contains(T) const
    * size_t size() const
    * void erase(T)
    * for_each(Function fn)
* Implement a **linear probing hash table** with the same interface as above.   
* Evaluate your *chained hash table* and *linear probing* using in-order and random data by timing the insertion of N elements, where you vary N, and compare to your Lab 4 and 5 results.


## Deliverables
* Implement your **chained hash table** tree in a file called **include/CSCE221H/hash_table_set.hpp** 
* Implement your **linear probe hash table** based in a file called **include/CSCE221H/linear_probe_set.hpp**  
* Implement your tests in a files called **test/test_hash_table_set.cpp** and **test/test_linear_probe_set.cpp**
* Evaluate the performance of your implementations using in-order and random-order insertions, removals and queries
* Vary the size of your container between small to large (size may depend on your system's memory)
* Plot the performance of insertion, queries and removals as a function of N, and compare performance to Lab 4 and Lab 5's sets.
* Experiment with different *growth* thresholds for a reasonably large size N
    * For your chained hash table, this should be a ratio of size / table size
    * For your linear probe table, this should be a ratio of size / capacity
* A writeup of your evaluation should be placed below.

## Rubric
* 50pts for your overall implementation of *hash_table_set.hpp* and *linear_probe_set.hpp* graded on correctness.  (Test your implementation with your own insertion/deletion/query orders).
* 20pts for your evaluation on when to *grow* your hash table.
* 30pts for performance evaluation of your two hash tables compared with previous labs.

## Evaluation
![image](https://user-images.githubusercontent.com/65512390/229597312-73fe87eb-5085-425b-95b3-a5a70ed1a729.png)
*BST unable to go up to N that large with in-order insertions*
![image](https://user-images.githubusercontent.com/65512390/229597096-27d9b7ce-f597-494b-bba2-04a71409141e.png)
