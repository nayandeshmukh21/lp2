#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;



void prims(){
    ifstream fin("./input.txt");
    
    int n, edges;
    fin >> n;
    fin >> edges;
    
    vector<vector<pair<int, int>>> graph(n);    
    for(int i = 0; i < edges; i++){
        int u, v, w;
        fin >> u >> v >> w;
        
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int count = 0;
    
    // weight, node, parent
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> visited(n, 0);
    
    pq.push({0, 0, -1});
    
    while(!pq.empty() && count < n - 1){
        int node = pq.top()[1];
        int parent = pq.top()[2];
        pq.pop();
        
        // check if it forms cycle or not
        if(visited[node]) continue;
        visited[node] = 1;
        
        if(parent != -1){
            count++;
            cout << parent << " " << node << endl;
        }
        
        // go to it's neighbour
        for(auto p: graph[node]){
            int neighbour = p.first;
            int weight = p.second;
            
            if(visited[neighbour]) continue;
            pq.push({weight, neighbour, node});
        }
    }
}

int getParent(int u, vector<int> &parent){
    if(u == parent[u]) return u;
    return parent[u] = getParent(parent[u], parent);
}

void unionNode(int u, int v, vector<int> &parent, vector<int> &rank){
    u = getParent(u, parent);
    v = getParent(v, parent);
    
    if(u == v) return;
    
    if(rank[u] < rank[v]){
       parent[u] = v;
    }else if(rank[u] > rank[v]){
        parent[v] = u;
    }else{
        parent[u] = v;
        rank[v]++;
    }
}



int main(){
    // selectionSort();
     prims();
    //kruskal();

    return 0;
}
//nput.txt
4
5
0 1 5
0 2 8
1 2 10 
1 3 15
2 3 20
