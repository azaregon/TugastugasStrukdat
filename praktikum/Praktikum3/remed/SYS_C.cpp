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
        adjList[vertex2].push_back(make_pair(vertex1, weight));
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


int main() {
    graph g;


    int V,N;
    scanf("%d %d",&V,&N);
    
    g.init(N);
    
    
    for (int i = 0; i < V; i++) {
        int s, d, w;
        scanf("%d %d %d",&s,&d,&w);
        
        g.add_edge(s,d,w);
    }

    int TC; 
    cin >> TC;


    for (int j = 0; j < TC; j++) {
        // cout << j;
        int St;
        cin >> St;

        // cout << TC << " ||| " << St << " " << N << endl;

        if (St > N-1) {
            cout << "Invalid starting point\n";
            break;
        }
        
        
        // int St, Ed;
        // scanf("%d", &St);    
        // scanf("%d", &Ed);
        
        vector<long> dijkstra_result;
        vector<long> predecessor;

    
        g.dijkstra(dijkstra_result, predecessor,St);
    
        // for(int i=0; i<dijkstra_result.size(); i++){
        //     cout << i << " " << dijkstra_result[i] << endl;
        // }
        
        for (int i = 0; i < dijkstra_result.size(); i++) { 
            if ( i == St) continue;
            cout << "---From " << St << " to " << i << "---" << endl;
            vector<long> path = g.trace_path(St, i, predecessor);
            // for (auto node:path ) {
            for (int i = 0; i < path.size(); i++) {
                if ( i != path.size()-1) {
                    cout << path[i] << " - ";
                } else {
                    cout << path[i];
                }
            }
            cout << "";

            cout << endl;
        }
        

    }
}