#include <fstream>
#include <iostream>
#include <map>
#include <nlohmann/json.hpp>
#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class DisjointSet {
public:
    DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);

        if (x_root == y_root) {
            return;
        }

        if (rank[x_root] < rank[y_root]) {
            parent[x_root] = y_root;
        } else if (rank[x_root] > rank[y_root]) {
            parent[y_root] = x_root;
        } else {
            parent[y_root] = x_root;
            rank[x_root]++;
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

double kruskal_mst(vector<tuple<double, string, string>>& edge_list, int n) {
    sort(edge_list.begin(), edge_list.end());

    unordered_map<string, int> id_map;
    int id_counter = 0;

    DisjointSet dsu(n);
    double mst_weight = 0;

    for (auto& edge : edge_list) {
        double weight = get<0>(edge);
        string u = get<1>(edge);
        string v = get<2>(edge);

        int u_id, v_id;
        if (id_map.find(u) == id_map.end()) {
            u_id = id_map[u] = id_counter++;
        } else {
            u_id = id_map[u];
        }

        if (id_map.find(v) == id_map.end()) {
            v_id = id_map[v] = id_counter++;
        } else {
            v_id = id_map[v];
        }

        if (dsu.find(u_id) != dsu.find(v_id)) {
            dsu.unite(u_id, v_id);
            mst_weight += weight;
        }
    }

    return mst_weight;
}

int main() {
    vector<tuple<double, string, string>> edge_list;
    ifstream ifs("../data/RC_2019-02-01_edges.ndjson");
    string line;

    while (getline(ifs, line)) {
        auto json = nlohmann::json::parse(line);

        string i = json["i"];
        string j = json["j"];
        double w = json["w"]; // Edge weight is a double

        edge_list.push_back({w, i, j});
    }

    cout << "|E| = " << edge_list.size() << endl;

    double total_weight = kruskal_mst(edge_list, edge_list.size());

    cout << "MST forest total weight = " << total_weight << endl;

    return 0;
}
