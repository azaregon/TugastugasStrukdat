#include <bits/stdc++.h>
using namespace std;

struct graph {
    long vertexCount, edgeCount;
    vector<vector<long>> adjList;
    vector<pair<long, pair<long, long>>> edgeList;

    void init(long v) {
        vertexCount = v;
        edgeCount = 0;
        adjList.assign(vertexCount, {});
    }

    void add_edge(long vertex1, long vertex2, long weight) {
        edgeList.push_back({weight, {vertex1, vertex2}});
        edgeCount++;
    }

    long find_parent(vector<long> &parent, long v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_parent(parent, parent[v]);
    }

    void union_set(vector<long> &parent, long u, long v) {
        long pu = find_parent(parent, u);
        long pv = find_parent(parent, v);
        if (pu != pv)
            parent[pv] = pu;
    }

    // DFS to reconstruct path from u to v (excluding the added cycle edge)
    bool dfs_find_path(long curr, long target, vector<bool> &visited, vector<long> &path, long bannedU, long bannedV) {
        visited[curr] = true;
        path.push_back(curr);
        if (curr == target) return true;

        for (long neighbor : adjList[curr]) {
            if ((curr == bannedU && neighbor == bannedV) || (curr == bannedV && neighbor == bannedU)) continue;
            if (!visited[neighbor]) {
                if (dfs_find_path(neighbor, target, visited, path, bannedU, bannedV))
                    return true;
            }
        }
        path.pop_back();
        return false;
    }

    void detect_cycle_and_print() {
        vector<long> parent(vertexCount);
        iota(parent.begin(), parent.end(), 0);
        sort(edgeList.begin(), edgeList.end());

        pair<long, long> cycleEdge = {-1, -1};

        for (auto edge : edgeList) {
            long u = edge.second.first;
            long v = edge.second.second;
            if (find_parent(parent, u) != find_parent(parent, v)) {
                union_set(parent, u, v);
                // add edge to MST
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            } else {
                // Found the edge that creates a cycle
                cycleEdge = {u, v};
                break;
            }
        }

        if (cycleEdge.first == -1) {
            cout << "VOCALOID CYCLE PROGRAM (VCP) : NO CYCLE DETECTED\n";
        } else {
            // Find path from u to v in the current MST
            vector<bool> visited(vertexCount, false);
            vector<long> path;
            dfs_find_path(cycleEdge.first, cycleEdge.second, visited, path, cycleEdge.first, cycleEdge.second);

            path.push_back(cycleEdge.first); // complete the cycle

            sort(path.begin(), path.end());
            path.erase(unique(path.begin(), path.end()), path.end()); // deduplicate in case of revisit

            cout << "VOCALOID CYCLE PROGRAM (VCP) : CYCLE DETECTED";
            for (long v : path) cout << " " << v;
            cout << "\n";
        }
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        long V, N;
        cin >> V >> N;
        graph g;
        g.init(V);
        for (int i = 0; i < N; ++i) {
            long u, v;
            cin >> u >> v;
            g.add_edge(u, v, 1); // weight is irrelevant for cycle detection
        }
        g.detect_cycle_and_print();
    }

    return 0;
}
