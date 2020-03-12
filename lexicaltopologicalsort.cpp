#include <bits/stdc++.h> 
using namespace std; 

class Graph { 
    int V;
    list<int>* adj; 
  
public: 
    Graph(int V);
    void addEdge(int u, int v); 
    void topologicalSort(); 
}; 

Graph::Graph(int V) { 
    this->V = V; 
    adj = new list<int>[V]; 
} 

void Graph::addEdge(int u, int v) { 
    adj[u].push_back(v); 
} 

void Graph::topologicalSort() { 
    vector<int> in_degree(V, 0); 
    
    for (int u = 0; u < V; u++) { 
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) in_degree[*itr]++; 
    } 

    multiset<int> s; 
    for (int i = 0; i < V; i++) if (in_degree[i] == 0) s.insert(i); 

    int cnt = 0; 
    vector<int> top_order; 

    while (!s.empty()) { 
        int u = *s.begin(); 
        s.erase(s.begin()); 
        top_order.push_back(u); 
  
        list<int>::iterator itr; 
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) if (--in_degree[*itr] == 0) s.insert(*itr); 
  
        cnt++; 
    } 

    if (cnt != V) { 
        cout << -1; 
        return; 
    } 

    for (int i = 0; i < top_order.size(); i++) cout << top_order[i] << " "; 
} 

int main() { 
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 

    g.topologicalSort(); 
  
    return 0; 
}
