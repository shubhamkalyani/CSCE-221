# Midterm Review

## Modern C++ Review

* Templates
* Modern Loops
```cpp
// Modern C++ loop
std::vector<int> vec;
//....
for(auto& value : vec) {
  //& means by reference and is modifiable
  //Without & is by copy
}
```

## Asymptotic Analysis -- Big $O$
* What is the Big O of $T(n) = 4n^3 + 6n^2 + 51n + 6$ ?
  * $O(n^3)
  * Ignore constants, and look at largest factor
* $O()$ -- worst case
* $\Omega()$ -- Best Case
* $\Theta()$ -- Best & Worst -- tight bound

What is the asymptotic complexity of:
```cpp
size_t sum(0);
for(size_t i = 0; i <N; ++i) {
  for(size_t j = 1; j< N; j *= 2) {
    for( size_t k = N; k > 1; k/=2) {
      sum++;
    }
  }
}
```

```cpp
size_t sum(0);
for(size_t i = 0; i <N; ++i) {
  for(size_t j = i; j< N; ++j) {
      sum++;
  }
}
```
* j is dependent on i
  * N + (N-1) + (N-2) ..+.. (N-N)
  * $O(N^2)$

* Can a $O(N^2)$ algorithm be faster in practice than a $O(N)$ algorithm?   Why?
    * Yes, it can be.   Because Big-O hides constants, and the $O(N)$ algorithm could have large constants and $O(N^2)$ would be faster for small N.


* Step 1:   Look if loops are independent
    * If so, analyze independently
    * i loop is:  $O(N)$
    * j loop is:  $O(lg(N))$
    * k loop is:  $O(lg(N))$
* Total is $O(N * (lg(N))^2)$

## Linked Lists
* Basic complexity of doubly linked list:
    * insert front or back: $O(1)$
    * delete front or back: $O(1)$
    * random element access:   $O(N)$
* In singly linked list, can we insert and delete in front and back in $O(1)$?   
    * No

## Vector
* Basic complexity:
    * push_back:  $O(1)$
    * pop_back:   $O(1)$
    * random element access:  $O(1)$
* Even when we grow our vector with push_back(), how is it $O(1)$?
    * We have to expand by a multiplicative factor > 1.  e.g., 2
    * Amortized constant
    * What happens grow by 1.1x ? Yes, $O(1)$
    * What happens if we grow by += 10?  No, $O(N)$
    * Prove Amortized constant when growth factor > 1.
* If std::list and std::vector have similar push_back() asymptotic complexity, will there experimental runtime performance be identical?   
    * NO, because they have different constants.  Linked Lists require memory allocation every push_back()

## Stack
* Enforces Last In First Out (LIFO)
* push() -- inserts an element
* pop() -- remove last inserted value
* top() -- returns the last inserted value

What does this code print out:
```cpp
std::stack<int> s;
s.push(5);
s.push(10);
s.pop();
s.push(15);
s.pop()
std::cout << s.top();
```
Answer:  5
* Common data structure implementation:   vector

## Queue
* Enforces First in First Out (FIFO)
* push() -- inserts an element to the end
* pop() -- removes the oldest element
* front() -- returns the oldest element

What does this code print out:
```cpp
std::queue<int> q;
q.push(7);
q.push(11);
q.pop();
q.push(15);
std::cout << q.front();
```
11
* Common data structure implementation:   Linked list
    * Can we use a vector efficiently?  NO
    * Can use either single or double linked list efficiently

## Associative Containers
* In C++ we have 2 types of Associative containers
    * std::map, std::multimap
      * Binary Search Tree based
      * *LessThanComparable* keys in an ordered container
    * std::unordered_map
      * Hash Table
      * keys are required to be *hashable*
* What is the difference between std::set and std::multiset?
    * Can contain duplicate keys, non unique


## Binary Search Tree (BST)
* Requirement of our values:  We need some order comparison, e.g., "<"
    * *LessThanComparable*
* In an unbalanced binary search tree
    * insert:  $O(N)$  and  $\Omega(1)$  
    * delete:  $O(N)$  and  $\Omega(1)$  
    * find:    $O(N)$  and  $\Omega(1)$  
    * height:  $O(N)$
* What is an example of a worst case insertion sequence?
    * Sorted, in order sequence.   Increasing or decreasing.
* What is an example 'good' case?
    * Random order
* Tree Traversal Orders
    * Pre-order
    * Post-order
    * In-ORder

```
              A
            /   \
          B       C
        /  \       \
      D      E      F
```

* Pre-Order:  A, B, D, E, C, F
* Post-Order: D, E, B, F, C, A
* In-Order:   D, B, E, A, C, F

* To insert: Start at root, in value less than root go left, else if greater than root go right, else its equal.   
* To delete: Find, if found, find a replacement if it has children.
    * No children, just remove
    * 1 child, replace with child.
    * 2 children, find the greatest-less-than, or the smallest-greater-than value to replace.   

## AVL BST
* In an AVL Binary Search Tree
    * insert:  $O(lg(N))$  and  $\Omega(1)$  
    * delete:  $O(lg(N))$  and  $\Omega(1)$  
    * find:    $O(lg(N))$  and  $\Omega(1)$  
    * height:  $O(lg(N))$
* What additional data do we need beyond a BST?   node height
* Height = max(left, right)+1
* What is rule on height balance?
    * Children's height must differ by 1 or 0, else requires rebalance.
* To insert:   Basic BST insertion, update height while detecting imbalance, repair imbalance.
    * Max number of balance repairs necessary (single or double rotation) per insertion?
        * $O(1)$
* To delete:   Basic BST delete, update height while detecting imbalance, and repair if necessary.
    * Max number of balance repairs necessary (single or double rotation) per deletion?
        * $O(lg(N))$ -- one per level


## PRACTICE 
https://www.cs.usfca.edu/~galles/visualization/AVLtree.html
* insertions and deletions