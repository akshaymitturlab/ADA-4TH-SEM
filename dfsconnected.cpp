#include <bits/stdc++.h> 

using namespace std; 
  
vector<int> gr[100]; 
  
bool vis[100]; 
  
void Add_edge(int u, int v) { 
    gr[u].push_back(v); 
} 

void dfs(int x) { 
    vis[x] = true; 
  
    for (auto i : gr[x]) if (!vis[i]) dfs(i); 
} 
  
bool Is_Connected(int n) { 
    memset(vis, false, sizeof vis); 
    dfs(1); 
  
    for (int i = 1; i <= n; i++) if (!vis[i]) return false; 
  
    return true; 
} 
  
int main() { 
    int n = 4; 
  
    Add_edge(1, 2); 
    Add_edge(1, 3); 
    Add_edge(2, 3); 
    //Add_edge(3, 4); 
  
    if (Is_Connected(n)) cout << "Yes"; 
    else cout << "No"; 
  
    return 0; 
}
