#include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertexCount, edgeCount;
    vector<vector<pair<long, long>>> adjList;
   
    void init(long v){
        vertexCount = v;
        edgeCount = 0;


        adjList.resize(vertexCount);
    }

    void add_edge(long vertex1, long vertex2, long weight){
        adjList[vertex1].push_back(make_pair(vertex2, weight));
        // adjList[vertex2].push_back(make_pair(vertex1, weight));
        edgeCount++;
    }

    void dijkstra(vector<long> &result, vector<long> &predecessor, long start){
        vector<bool> visited(vertexCount, false);
        priority_queue <pair<long, long>,
                        vector <pair<long, long>>,
                        greater <pair<long, long>> > pq;
        result = vector<long>(vertexCount, LONG_MAX);
        predecessor = vector<long>(vertexCount, -1); // predecessor is a vector to store the predecessor (pendahulu) of each node
       
        pq.push(make_pair(0, start));
        result[start] = 0;


        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();


            long u = temp.second;
            if (visited[u]) continue;
            visited[u] = true;


            for(auto vertex:adjList[u]){
                long nextVertex = vertex.first;
                long weight = vertex.second;


                if(!visited[nextVertex] && result[u] + weight < result[nextVertex]){
                    result[nextVertex] = result[u] + weight;
                    pq.push(make_pair(result[nextVertex], nextVertex));
                    predecessor[nextVertex] = u; // store the predecessor of nextVertex
                }
            }
        }
    }

    vector<long> trace_path(long start, long end, const vector<long>& predecessor) {
        vector<long> path;
        // loop from end to start using predecessor 
        for (long at = end; at != -1; at = predecessor[at]) {
            path.push_back(at);
        }
        // reverse the path to get it from start to end
        reverse(path.begin(), path.end());
        if (path.front() == start) {
            // if the path starts with the start node, return the path
            return path;
        }
        return {}; // return an empty path if there is no path from start to end
    }
};


// int main(){
//     graph g;
//     g.init(6);
//     g.add_edge(0, 1, 2);
//     g.add_edge(0, 5, 4);
//     g.add_edge(1, 3, 9);
//     g.add_edge(5, 3, 2);
//     g.add_edge(3, 4, 1);
//     g.add_edge(3, 2, 5);

//     vector<long> dijkstra_result;
//     vector<long> predecessor;

//     long start = 0;
//     long end = 4;

//     g.dijkstra(dijkstra_result, predecessor, start);

//     cout << "Shortest distances from node " << start << " to all other nodes:" << endl;
//     for(int i = 0; i < dijkstra_result.size(); i++){
//         cout << "Node " << i << ": " << dijkstra_result[i] << endl;
//     }

//     vector<long> path = g.trace_path(start, end, predecessor);
   
//     if (!path.empty()) {
//         cout << "Shortest path from node " << start << " to node " << end << ":" << endl;
//         for (auto node : path) {
//             cout << node << " ";
//         }
//         cout << endl;
//     } else {
//         cout << "No path exists from node " << start << " to node " << end << "." << endl;
//     }
//     return 0;
// }


int main() {
    graph g;


    int V,N;
    scanf("%d %d",&V,&N);
    
    g.init(V);
    
    
    for (int i = 0; i < N; i++) {
        int s, d, w;
        scanf("%d %d %d",&s,&d,&w);
        
        g.add_edge(s,d,w);
    }
    
    int St, Ed;
    scanf("%d", &St);
    scanf("%d", &Ed);
    
    vector<long> dijkstra_result;
    vector<long> predecessor;


    g.dijkstra(dijkstra_result, predecessor,St);

    // for(int i=0; i<dijkstra_result.size(); i++){
    //     cout << i << " " << dijkstra_result[i] << endl;
    // }

    
    vector<long> path = g.trace_path(St, Ed, predecessor);
   
    if (!path.empty()) {
        // ada path
        // string pathstring;
        char pathstring[100];
        int cost;

        // cout << "Shortest path from node " << St << " to node " << Ed << ":" << endl;
        cout << "Path found with cost "  << dijkstra_result[Ed] << ": ";
        for (auto node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        // cout << "No path exists from node " << St << " to node " << Ed << "." << endl;
        cout << "Impossible to find the path\n";
    }
    return 0;
}
