#include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertexCount, edgeCount;
    vector<vector<long>> adjList;
    
    void init(long v){
        vertexCount = v;
        edgeCount = 0;

        for(int i=0; i<vertexCount; i++){
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2){
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
        edgeCount++;
    }

    void dfs(vector<long> &result, long start){
        vector<bool> visited(vertexCount, false);
        stack<long> st;

        st.push(start);
        visited[start] = true;
        result.push_back(start);
        int from_start = 0;

        while(!st.empty()){
            long temp = st.top();
            st.pop();

            

            if(!visited[temp]){
                // result.push_back(temp);
                visited[temp] = true;
            }


            for(auto vertex:adjList[temp]){
                if(visited[vertex] && vertex == start && from_start > 1){
                    while (!st.empty()) {
                        result.push_back(st.top());
                        st.pop();
                    }
                    return;
                }
                if (!visited[vertex])
                    st.push(vertex);

            }
            from_start++;
        }
    }

    bool dfs2(long node, long start, vector<bool> &visited, stack<long> &st,int from_start){

        st.push(node);
        visited[node] = true;
        for (auto vertex: adjList[node]) {
            if (vertex == start && from_start > 1) {
                return true;
            }
            // if (dfs2(vertex, start, visited, st)) return true;
            if (!visited[vertex]) {
                if (dfs2(vertex, start, visited, st, from_start+1)) return true;
            }
        }
        
        st.pop();
        return false;

    }

    void bfs(vector<long> &result, long start){
        vector<bool> visited(vertexCount, false);
        queue<long> q;

        q.push(start);
        visited[start] = true;
        result.push_back(start);

        while(!q.empty()){
            long temp = q.front();
            q.pop();

            for(auto vertex:adjList[temp]){
                if (!visited[vertex]){
                    q.push(vertex);
                    visited[vertex] = true;
                    result.push_back(vertex);
                }
            }
        }
    }
};

// int main(){
//     graph g;
//     g.init(6);
//     g.add_edge(0, 1);
//     g.add_edge(1, 2);
//     g.add_edge(2, 3);
//     g.add_edge(3, 4);
//     g.add_edge(4, 1);
//     g.add_edge(1, 5);
//     vector<long> dfs_result, bfs_result;
//     stack<long> st;
//     vector<bool> visited(10, false);
//     for (int i = 0; i < 6; i++) {
//         bool res = g.dfs2(1, 1, visited, st,0);
//         if (res)break;
//     }
//     // cout << res << endl;

//     while (!st.empty()) {
//         // cout << st.top() << " ";
//         dfs_result.push_back(st.top());
//         st.pop();
//     }
//     // cout << endl;
//     sort(dfs_result.begin(),dfs_result.end());
//     for(auto it:dfs_result){
//         cout << it << " ";
//     }
//     cout << endl;

//     // g.bfs(bfs_result, 0);

//     // for(auto it:bfs_result){
//     //     cout << it << " ";
//     // }
//     // cout << endl;

//     // return 0;
// }

// int main() {
//     int TC;
//     cin >> TC;

//     for (int T = 0; T < TC; T++) {
//         int V,N;
//         graph g;
//         cin >> V >> N;
//         g.init(V);
//         for (int i = 0; i < N; i++) {
//             int sc, dt;
//             cin >> sc >> dt;
//             g.add_edge(sc, dt);
            
//         }


//         vector<long> dfs_result, bfs_result;
//         stack<long> st;
//         vector<bool> visited(V, false);
//         bool res;
//         for (int i = 0; i < N; i++) {
//             res = g.dfs2(i, i, visited, st,0);
//             if (res)break;
//         }
//         if (!res) {
//             cout << "VOCALOID CYCLE PROGRAM (VCP) : NO CYCLE DETECTED" << endl;
//         } else {
//                 cout << "VOCALOID CYCLE PROGRAM (VCP) : CYCLE DETECTED ";
//         }
//         // cout << res << endl;

//         while (!st.empty()) {
//             // cout << st.top() << " ";
//             dfs_result.push_back(st.top());
//             st.pop();
//         }
//         // cout << endl;
//         sort(dfs_result.begin(),dfs_result.end());
//         for(auto it:dfs_result){
//             cout << it << " ";
//         }
//         cout << endl;
//     }
// }


int main() {
    int TC;
    cin >> TC;

    for (int test = 0; test < TC; test++) {
        int V, N;
        cin >> V >> N;

        graph g;
        g.init(V);

        for (int i = 0; i < N; i++) {
            int u, v;
            cin >> u >> v;
            g.add_edge(u, v);
        }

        vector<long> cycle_nodes;
        bool found_cycle = false;

        for (int i = 0; i < V && !found_cycle; i++) {
            vector<bool> visited(V, false);
            stack<long> st;

            if (g.dfs2(i, i, visited, st, 0)) {
                while (!st.empty()) {
                    cycle_nodes.push_back(st.top());
                    st.pop();
                }
                sort(cycle_nodes.begin(), cycle_nodes.end());
                found_cycle = true;
            }
        }

        if (found_cycle) {
            cout << "VOCALOID CYCLE PROGRAM (VCP) : CYCLE DETECTED";
            for (long v : cycle_nodes) {
                cout << " " << v;
            }
            cout << "\n";
        } else {
            cout << "VOCALOID CYCLE PROGRAM (VCP) : NO CYCLE DETECTED\n";
        }
    }

    return 0;
}
