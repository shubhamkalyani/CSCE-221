#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;

using Graph = unordered_map<string, vector<pair<string, double>>>;

struct Edge {
  string from;
  string to;
  double weight;
};

struct CompareEdges {
  bool operator() (const Edge& e1, const Edge& e2) {
    return e1.weight > e2.weight;
  }
};

double primMST(Graph& graph) {
  priority_queue<Edge, vector<Edge>, CompareEdges> pq;
  unordered_map<string, bool> visited;

  for (auto edge : graph.begin()->second) {
    pq.push({graph.begin()->first, edge.first, edge.second});
  }

  visited[graph.begin()->first] = true;
  double weight = 0;

  while (!pq.empty()) {
    Edge e = pq.top();
    pq.pop();

    if (visited[e.to]) {
      continue;
    }

    visited[e.to] = true;
    weight += e.weight;

    for (auto edge : graph[e.to]) {
      if (!visited[edge.first]) {
        pq.push({e.to, edge.first, edge.second});
      }
    }
  }

  return weight;
}

int main() {
  ifstream ifs("../data/RC_2019-02-01_edges.ndjson");
  string line;
  Graph graph;
  size_t num_undirected_edges(0);

  while (getline(ifs, line)) {
    auto json = nlohmann::json::parse(line);

    string i = json["i"];
    string j = json["j"];
    double w = json["w"];

    graph[i].push_back({j, w});
    graph[j].push_back({i, w});
    ++num_undirected_edges;
  }

  double mst_weight = primMST(graph);
  cout << "|E| = " << num_undirected_edges << endl;
  cout << "MST weight = " << mst_weight << endl;

  return 0;
}