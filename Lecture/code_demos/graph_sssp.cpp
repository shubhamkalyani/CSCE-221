#include <iostream>
#include <limits>
#include <set>
#include <utility>
#include <vector>
#include <queue>

using graph = std::vector<std::vector<std::pair<int, double>>>;

std::vector<double> bellman_ford_sssp(const graph &g, int source)
{
  std::vector<double> path_length(g.size(), std::numeric_limits<double>::max());

  //
  //  Set source's path length to 0
  path_length[source] = 0;

  // Iterate until no improvements or |V| max iterations.
  bool updated = false;
  size_t iteration_count = 0;
  do
  {
    updated = false;
    std::cout << "Iteration " << iteration_count << ": ";
    for(double pl : path_length) {
      std::cout << pl << " ";
    }
    std::cout << std::endl;

    // For all edges, try to improve path length
    for (int64_t edge_source = g.size()-1; edge_source >= 0; --edge_source)
    {
      for (const auto &edge : g[edge_source])
      {
        int edge_target = edge.first;
        double edge_weight = edge.second;

        double edge_source_pl = path_length[edge_source];
        if (edge_source_pl < std::numeric_limits<double>::max() &&
            path_length[edge_target] > edge_source_pl + edge_weight)
        {
          // found improved path length
          path_length[edge_target] = edge_source_pl + edge_weight;
          updated = true;
        }
      }
    }

  } while (updated && iteration_count++ < g.size());

  return path_length;
}

//
// WARNING:   Untested, will continue during Friday's lecture.
std::vector<double>  dijkstra_sssp(const graph& g, int source) {
  std::vector<double> path_length(g.size(), std::numeric_limits<double>::max());

  // Min-Priority Queue
  using pq_elem = std::pair<double,int>;
  std::priority_queue< pq_elem, std::vector<pq_elem>, std::greater<pq_elem> > pq;

  // Init from source
  pq.push({0.0, source});

  
  while(not pq.empty()) {
    pq_elem next = pq.top();
    pq.pop();
    int edge_source = next.second;
    double edge_source_pl = next.first;

    if(edge_source_pl < path_length[edge_source]) {
      path_length[edge_source] = edge_source_pl;
      for( const auto& edge : g[edge_source]) {
        int edge_target = edge.first;
        double edge_weight = edge.second;

        // could speed up here?
        double candidate_target_weight = edge_weight + edge_source_pl;
        if(candidate_target_weight < path_length[edge_target]) {
          pq.push({candidate_target_weight, edge_target});
        }
      }
    }
  }


  return path_length;
}

int main(int argc, char **argv)
{

  graph g(8);

  g[7].push_back({1, 2});
  g[7].push_back({2, 2});
  g[7].push_back({6, 1});

  g[6].push_back({5, 1});
  g[6].push_back({7, 1});

  g[5].push_back({4, 1});
  g[5].push_back({6, 1});
  
  g[0].push_back({1, 10});
  g[0].push_back({2, 10});
  g[0].push_back({3, 1});

  g[1].push_back({0, 10});
  g[1].push_back({7, 2});

  g[2].push_back({0, 10});
  g[2].push_back({7, 2});

  g[3].push_back({0, 1});
  g[3].push_back({4, 1});

  g[4].push_back({3, 1});
  g[4].push_back({5, 1});


  //bellman_ford_sssp(g, 0);
  dijkstra_sssp(g, 0);

  return 0;
}