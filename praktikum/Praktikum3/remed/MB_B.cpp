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

        while(!st.empty()){
            long temp = st.top();
            st.pop();

            if(!visited[temp]){
                result.push_back(temp);
                visited[temp] = true;
            }

            for(auto vertex:adjList[temp]){
                if (!visited[vertex])
                    st.push(vertex);
            }
        }
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
    int bfs2(vector<long> &result, long start, long target){
        vector<bool> visited(vertexCount, false);
        queue<long> q;

        if (start == target) return 0;

        q.push(start);
        visited[start] = true;
        result.push_back(start);
        int distance = 1;
        int layerSize = q.size();

        while(!q.empty()){
            layerSize = q.size();

            for (int ly = 0; ly < layerSize; ly++) {

                long temp = q.front();
                q.pop();
                
                for(auto vertex:adjList[temp]){
                    if (!visited[vertex]){
                        q.push(vertex);
                        visited[vertex] = true;
                        result.push_back(vertex);


                        if (vertex == target) {
                            return distance;
                        }
                    }
                }
            }

            distance++;
        }


        return -1;
    }

    void bfs3(vector<long> &result, long start, int target){
        vector<bool> visited(vertexCount, false);
        queue<long> q;
        vector<long> distance(vertexCount, -1);


        q.push(start);
        visited[start] = true;  
        distance[start] = 0;
        // result.push_back(start);
        int layer = 0;


        while(!q.empty()){
            int layerSize = q.size();
            // printf("Layer %d: %d   \\", layer, layerSize);

            // if (layer == target) {
            //     return;
            // };


            for ( int i = 0 ; i < layerSize; i++) {
                // if (i == 0) layerSize = 0;
                long temp = q.front();
                q.pop();
                
                for(auto vertex:adjList[temp]){
                    if (!visited[vertex]){
                        visited[vertex] = true;
                        if ( distance[vertex] == -1) {
                            distance[vertex] = distance[temp] + 1;
                        }
                        q.push(vertex);
                        // layerSize++;
                        // printf("%d \n",distance);
                    }
                }
            }
            
        }

        for (int i = 0; i < vertexCount;i++) {
            // cout << i << "  " << distance[i] << endl;
            if (distance[i] == target){
                result.push_back(i);
            }
        }
    }
};

int main(){
    graph g;
    // g.init(5);
    // g.add_edge(0, 1);
    // g.add_edge(0, 2);
    // g.add_edge(0, 3);
    // g.add_edge(1, 3);
    // g.add_edge(1, 4);

    int N, V;
    int Sc, Ds;

    cin >> N >> V >> Sc >> Ds;
    g.init(N+3);
    for (int i = 0; i < V; i++) {
        int Fr, To;

        cin >> Fr >> To;
        g.add_edge(Fr, To);

    }



    vector<long> bfs_result;
    // g.dfs(dfs_result, 0);

    // for(auto it:dfs_result){
    //     cout << it << " ";
    // }
    // cout << endl;

    int a = g.bfs2(bfs_result, Sc, Ds);
    cout << a;

    // for(auto it:bfs_result){
    //     cout << it << " ";
    // }
    // cout << endl;

    return 0;
}