#include <bits/stdc++.h>
using namespace std;

struct graph{
    long vertexCount, edgeCount;
    vector<vector<pair<long, long>>> adjList;
    
    void init(long v){
        vertexCount = v;
        edgeCount = 0;

        for(int i=0; i<vertexCount; i++){
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2, long weight){
        adjList[vertex1].push_back(make_pair(vertex2, weight));
        adjList[vertex2].push_back(make_pair(vertex1, weight)); // for undirected
        edgeCount++;
    }

    void dfs(vector<long> &result, long start){
        vector<bool> visited(vertexCount, false);
        stack<long> st;
        stack<long> distance;

        st.push(start);
        visited[start] = true;
        result.push_back(start);
        distance.push(0);

        while(!st.empty()){
            long temp = st.top();
            st.pop();
            distance.pop();

            
            if(!visited[temp]){
                result.push_back(temp);
                visited[temp] = true;
            }
            
            for(auto vertex:adjList[temp]){
                if (!visited[vertex.first]);
                else return
                st.push(vertex.first);
                distance.push(vertex.second);
                cout << vertex.first << endl;
                // cout << distance.top() << endl;
            }
        }
    }

    bool dfs2(long node, vector<bool> &visited){


        // cout << node << endl;
        visited[node] = true;
        for(auto vertex:adjList[node]){
            if (!visited[vertex.first]) {
                if (dfs2(vertex.first, visited, ) == true) {
                    return true;
                }
            }
        }
        visited[node] = false;

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
                if (!visited[vertex.first]){
                    q.push(vertex.first);
                    visited[vertex.first] = true;
                    result.push_back(vertex.first);
                }
            }
        }
    }

    void bruteForceSameTarget(int start, int target) {
        
    }

    void dijkstra(vector<long> &result, long start){
        vector<bool> visited(vertexCount, false);
        priority_queue <pair<long, long>, 
                        vector <pair<long, long>>, 
                        greater <pair<long, long>> > pq;
        result = vector<long>(vertexCount, LONG_MAX);
        
        pq.push(make_pair(0, start));
        result[start] = 0;

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            visited[temp.second] = true;

            for(auto vertex:adjList[temp.second]){
                long nextVertex = vertex.first;
                long weight = vertex.second;

                if(!visited[nextVertex]){
                    if(temp.first + weight < result[nextVertex]) {
                        result[nextVertex] = temp.first + weight;
                        pq.push(make_pair(result[nextVertex], nextVertex));
                    }
                }
            }
        }
    }
};

int wrapper(graph g,int tgt_w, int total) {
    for (int i= 0; i < total;i++) {
        vector<bool> visited(100, false);
        unordered_map<int, unordered_set<int>> memo;
        bool a  = g.dfs2(i,tgt_w,0,visited,memo);
        if (a) {
            cout << "YES" << endl;
            return 0;
            
        }else {
            // cout << "NO" << endl;

        }
    }
    cout << "NO" <<endl;


}

int main(){
    int TC;
    scanf("%d",&TC);
    int total;

    for ( int i = 0; i < TC; i++) {    
        graph g;
        g.init(100);

        while (1) {
            int s,d,w;
            scanf("%d %d %d", &s, &d, &w);

            if (s == 0 && d == 0 && w == 0) break;

            g.add_edge(s, d, w);
            total++;
        }
        int tgt_w;
        scanf("%d", &tgt_w);

        wrapper(g,tgt_w,total);
        // void dfs(vector<long> &result, long start){
        // for (int i= 0; i < g.adjList.size();i++) {
        //     vector<bool> visited(100, false);
        //     bool a  = g.dfs2(i,tgt_w,0,visited);
        //     if (a) {
        //         cout << "YES" << endl;
                
        //     }else {
        //         // cout << "NO" << endl;
    
        //     }
        // }



    }    // vector <long> res;
    // g.dfs(res,1);
    // for(int i=0; i< res.size(); i++){
    //     cout << i << " " << res[i] << endl;

    // }
    //

    // g.add_edge(0, 1, 2);
    // g.add_edge(0, 5, 4);
    // g.add_edge(1, 3, 9);
    // g.add_edge(5, 3, 2);
    // g.add_edge(3, 4, 1);
    // g.add_edge(3, 2, 5);

    // vector<long> dijkstra_result;

    // g.dijkstra(dijkstra_result, 0);

    // for(int i=0; i<dijkstra_result.size(); i++){
    //     cout << i << " " << dijkstra_result[i] << endl;
    //     if (dijkstra_result[i] == tgt_w) {
    //         cout << "ada";
    //     }
    // }

    return 0;
}