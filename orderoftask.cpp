#include <bits/stdc++.h> 
using namespace std; 

vector<unordered_set<int> > make_graph(int numTasks, vector<pair<int, int> >& prerequisites) { 
    vector<unordered_set<int> > graph(numTasks);
    for (auto pre : prerequisites) graph[pre.second].insert(pre.first); 
    return graph; 
} 

bool dfs(vector<unordered_set<int> >& graph, int node, vector<bool>& onpath, vector<bool>& visited, vector<int>& toposort) { 
    if (visited[node]) return false; 
    onpath[node] = visited[node] = true; 
    for (int neigh : graph[node]) if (onpath[neigh] || dfs(graph, neigh, onpath, visited, toposort)) return true; 
    toposort.push_back(node); 
    return onpath[node] = false; 
}  
vector<int> findOrder(int numTasks, vector<pair<int, int> >& prerequisites) { 
    vector<unordered_set<int> > graph = make_graph(numTasks, prerequisites); 
    vector<int> toposort; 
    vector<bool> onpath(numTasks, false), visited(numTasks, false); 
    for (int i = 0; i < numTasks; i++) if (!visited[i] && dfs(graph, i, onpath, visited, toposort)) return {}; 
    reverse(toposort.begin(), toposort.end()); 
    return toposort; 
}  
int main() { 
    int numTasks = 3; 
    vector<pair<int, int> > prerequisites; 
    prerequisites.push_back(make_pair(1, 0)); 
    prerequisites.push_back(make_pair(2, 1));
    vector<int> v = findOrder(numTasks, prerequisites); 
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0; 
} 
