# Final Review

## Hash Tables
### Chained Collisions
* Hash mod to get bucket index, and insert into linked list for that bucket
* std::vector< std::list< T >> as example.
* As size increases, expanding the table is necessary which causes a rehash.
* Load factor = Total number of items in hash table / size of table
* Load factor > 1; Example 2 - 5 range

### Linear Probing
* Two arrays
   * Tombstone array {empty, full, deleted}
   * Data array
* Initial Probe location = Hash mod array length 
* If probe is full, find next available spot
* We need the tombstone mark an element was there, and to keep searching for elements.
* Load Factor = Total number of elements / array length (not count tombstones)
* Toad factor < 1;   Example is 0.5
* Alternative to tombstone is the max-probe technique where every insert updates a max-probe length to bound search distance.

### Complexity
* Insert / Find / Delete = O(1)
  * Assume a good hash function
  * Keep the probe distance (or chain length) small.   Do this by controlling load factor.

## Heaps (Binary Heap)
* Priority Queue -- min or max
* Can be visualized as a tree, but implemented as an array
* ParentIndex(i) = (i - 1) / 2
* LeftChild(i) = 2 * i + 1
* RightChild(i) = 2 * i + 2
* MinHeap Rules:   Parent < Children
* MaxHeap Rules:   Parent > Children
* push_heap: adds a new element to the end of the array, and check if needs to swap with parents.
* pop_heap: Removes root by replacing with last element in the array, then recursively swaps with best child.

### Complexity
* height: $O(lg(n))$
* push_heap: $O(lg(n))$
* pop_heap:  $O(lg(n))$
* make_heap: $O(n * log(n))$ -- transforms an unordered sequence into a heap ordered sequence.
* sort_heap: $O(n * log(n))$ -- transform a heap ordered sequence into a sorted sequence.

## Sorting

### Heap Sort
* make_heap followed by sort_heap
* $O(n * log(n))$
* $\Omega{(n)}$ if all elements are equal
* in-pace
* can be implemented with recursion
* *NOT* stable
* *NOT* divide and conqueror 

### Merge Sort
* Recursively split array in half until single-element pieces, then merge together with sorted merge
* divide and conqueror
* $O(n * lg(n))$
* $\Omega(n * lg(n))$ --  $\Theta{n * lg(n)}$
* Can be parallelized
* *NOT* in place
* Stable Sort

### Quick Sort
* Picks a pivot value (ideally the median) to partition the sequence in half.   Swaps values between the front and back around the pivot value.
* Picking the pivot -- heuristic is to pick first/middle/last value and choose median.
* Picking actual median is as expensive as sorting, so heuristic is needed.
* $O(N^2)$ -- choosing a min/max value of sequence as the pivot
* $O(n * lg(n))$ -- If we pick 'good' pivots
* In Place
* *NOT* stable
* Divide and conqueror


## Graphs
### Data Structures 
* Edge List
   * array of tuples (i,j)
   * std::vector < std::pair < int, int> >
   * Slow at finding neighbors of a particular vertex
* Adjacency List
   * std::vector< std::vector < int >>
   * Set of vertex adjacency lists
   * Fast as finding neighbors of a particular vertex
* Adjacency Matrix
   * 2d matrix (array) where we put a 1 if edge (i,j) exists, otherwise 0 if the edge doesn't exist
   * Good for dense graphs, where E is close to V^2
   * Slow at finding neighbors of a particular vertex for sparse graphs
### Terms
* vertex degree -- number of edges connected to a vertex in an undirected graph
    * out-degree outgoing edges for a directed graph
    * in-degree incoming edges for a directed graph
* multigraph -- Multiple edges between same pair of nodes (i, j)
* weighted graph -- Edges have a weighted associated with them
* tree vs graph -- Tree cannot have cycles.   Tree has at most V - 1 edges.
* connected component -- Set of vertices in an undirected graph where a path exists between all pairs
* spanning tree -- Subset of edges that connect all vertices in a connected component without cycles.
* spanning forest -- A collection of spanning trees.

### Algorithms
* SSSP -- Single Source Shortest Path
  * Bellman-Ford SSSP
      * Set all vertex distances to infinity
      * Set source distance to 0
      * Loop up to V times:
      * Loop over all edges to 'relax' path distance  
      * $O(V * E)$
      * Stop early:  if no path length was updated last iteration
      * NOT Greedy
      * Can work with negative edges weights as long as no negative cycles
      * Detect negative cycles:   if loops more than V times.
      
  * Dijkstra's SSSP
     * Min priority queue by path length
     * Starting from source, push in neighbors to priority queue.
     * Loop until queue is empty
     * $O(E * lg (V))$
     * Doesn't work with negative edge weights
     * Is greedy

* MST -- Minimum Spanning Tree
   * Prim's
        * Min priority queue, similar to Dijkstra's, but store edge weight (not path length)
        * Needs an arbitrary starting vertex
        * Needs an Adjacency list to loop over neighbors
        * Greedy
        * $O(E * lg(V))$  
   * Kruskal's
        * Uses Disjoint Set / Union Find
        * Uses a sorted edge list (sorting take $O(E * lg (V))$
        * Doesn't need a priority queue
        * Doesn't need a source vertex
        * Disjoint Set needs Path Compression to make Kruskal's runtime $O(E * lg(V))$
* BFS
   * Starting from a source, expand vertices level-by-level
   * SSSP ignoring edge weights
   * $O(E + V)$
* DFS
    * Starting from a source, visit vertices depth-wise
    * $O(E + V)$