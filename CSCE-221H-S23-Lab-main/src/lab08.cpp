#include <fstream>
#include <iostream>
#include <map>
#include <nlohmann/json.hpp>
#include <set>
#include <string>
#include <queue>

using std::cout;
using std::endl;

void bfs(const std::string& start_node, std::map<std::string, std::vector<std::string>>& str_adj_lists, std::set<std::string>& visited) {
    std::queue<std::string> q;
    q.push(start_node);
    visited.insert(start_node);
    while (!q.empty()) {
        std::string curr_node = q.front();
        q.pop();
        for (std::string neighbor : str_adj_lists[curr_node]) {
            if (visited.count(neighbor) == 0) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

int compute_num_components(std::map<std::string, std::vector<std::string>>& str_adj_lists) {
    int num_components = 0;
    std::set<std::string> visited;
    for (const auto& entry : str_adj_lists) {
        std::string node = entry.first;
        if (visited.count(node) == 0) {
            bfs(node, str_adj_lists, visited);
            num_components++;
        }
    }
    return num_components;
}

int main(int argc, char **argv) {

  //
  // Recommendation:  Define your associative containers here
  std::map<std::string, std::vector<std::string>> str_adj_lists;

  //
  // Parse the reddit ndjson input file
  std::ifstream ifs("../data/RC_2019-02-01_edges.ndjson");
  std::string line;
  size_t num_undirected_edges(0);
  while (std::getline(ifs, line)) {
    auto json = nlohmann::json::parse(line);

    std::string i = json["i"];
    std::string j = json["j"];
    double w = json["w"]; // weight not used in this lab

    str_adj_lists[i].push_back(j);
    str_adj_lists[j].push_back(i);
    ++num_undirected_edges;
  }

  std::cout << "|V| = " << str_adj_lists.size() << std::endl;
  std::cout << "|E| = " << num_undirected_edges << std::endl;

  std::cout << compute_num_components(str_adj_lists) << std::endl;

  //Your Assignment:
  //
  // Compute the # of connected components using your own implementation
  // of BFS.    Output the #.
  //
  // Suggestion:   Write a version of BFS that takes a visited set as a
  // parameter by reference.

  return 0;
}
