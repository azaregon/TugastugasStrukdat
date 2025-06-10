#include <bits/stdc++.h>
#include <iostream>
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
    
    
    void bfs2(vector<long> &result, long start, int target){
        vector<bool> visited(vertexCount, false);
        queue<long> q;

        q.push(start);
        visited[start] = true;
        result.push_back(start);
        int layer = 0;


        while(!q.empty()){
            int layerSize = q.size();
            // printf("Layer %d: ", layer);

            if (layer == target) {
                return;
            };


            for ( int i = 0 ; i < layerSize; i++) {
                if (i == 0) layerSize = 0;
                long temp = q.front();
                q.pop();
                
                for(auto vertex:adjList[temp]){
                    if (!visited[vertex]){
                        q.push(vertex);
                        visited[vertex] = true;
                        result.push_back(vertex);
                        layerSize++;
                        // printf("%d \n",distance);
                    }
                }
            }

            layer++;
        }
    }

    // void modbfs(vector<long> &result, queue<long> &q, long start, int layer_target){
    //     vector<bool> visited(vertexCount, false);
    //     queue<long> q;

    //     q.push(start);
    //     visited[start] = true;
    //     result.push_back(start);
    //     int layerSize = 1;
    //     int  distance = 0;

    //     while(!q.empty()){
    //         for (int i = 0; i < layerSize; i++) {
    //             if (i == 0 ) layerSize = 0;
    //             long temp = q.front();
    //             q.pop();
    
    //             for(auto vertex:adjList[temp]){
    //                 if (!visited[vertex]){
    //                     q.push(vertex);
    //                     visited[vertex] = true;
    //                     result.push_back(vertex);
    //                     layerSize++;
    //                 }
    //             }
    //         }

    //         distance++;
    //     }
    // }
};

int main(){
    graph g;
    int N, Edg, Dist;
    int Start;

    scanf("%d %d %d",&N,&Edg,&Dist);
    scanf("%d", &Start);
    g.init(Edg);

    int Sc, Dst;
    for (int i = 0; i < Edg; i++){
        scanf("%d %d", &Sc, &Dist);

        g.add_edge(Sc, Dist);
    }

    vector<long> dfs_result, bfs_result;
    g.dfs(dfs_result, 0);

    for(auto it:dfs_result){
        cout << it << " ";
    }
    cout << endl;
    
    queue<long> que;
    g.bfs2(bfs_result, Start,2);

    // for(auto it:que){
    //     cout << it << " ";
    // }
    // cout << "A" <<endl<<endl;

    while (!que.empty()) {
        // cout << que.front() << endl;
        que.pop();
    }

    // cout << bfs_result.size() <<  endl;
    // cout << endl;

    // queue<long> curr_qbfs;
    // g.modbfs(modbfs_result, curr_qbfs, Start, Dist);
    // for(auto it:bfs_result){
    //     cout << it << " ";
    // }
    // cout << endl;
    // cout << endl;
    // cout << endl;
    // cout << endl;
    // while (!curr_qbfs.empty()) {
    //     cout << curr_qbfs.front() << " ";
    //     curr_qbfs.pop();
    // }

    // cout << endl;


    return 0;
}