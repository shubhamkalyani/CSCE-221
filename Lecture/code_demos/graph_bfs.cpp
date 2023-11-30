#include <iostream>
#include <vector>
#include <utility>
#include <set>

int main(int argc, char** argv) {

  std::vector< std::vector< int > >  adj_list(7);

  adj_list[0].push_back(1);
  adj_list[0].push_back(2);
  adj_list[0].push_back(6);

  adj_list[1].push_back(0);
  adj_list[1].push_back(3);

  adj_list[2].push_back(0);
  adj_list[2].push_back(3);

  adj_list[3].push_back(1);
  adj_list[3].push_back(2);
  adj_list[3].push_back(4);

  adj_list[4].push_back(3);
  adj_list[4].push_back(5);

  adj_list[5].push_back(6);
  adj_list[5].push_back(4);

  adj_list[6].push_back(5);

  adj_list[6].push_back(0);



  // 
  //  Breadth-First Search
  std::set<int> visited; //poor choice for efficiency
  std::vector<int>  current_level;
  std::vector<int>  next_level;
  int level_no = 0;

  //
  // insert source vertex
  current_level.push_back(2);
  visited.insert(2);

  do {
    // print current level
      std::cout << "BFS Level " << level_no << " = ";
      for(int i : current_level) {
        std::cout << i << " ";
      }
      std::cout << std::endl;
    // visit next level
    while(not current_level.empty()) {
      int vert = current_level.back();
      current_level.pop_back();

      for(int neighbor : adj_list[vert]) {
        if(visited.count(neighbor) == 0) {
          visited.insert(neighbor);
          next_level.push_back(neighbor);
        }
      }
    }
    current_level.swap(next_level);
    ++level_no;
  } while(not current_level.empty());






  return 0;
}