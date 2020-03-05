#include<iostream>

using namespace std;

int graph[5][5] = {{0, 1, 1, 0, 0},
{1, 0, 1, 1, 0},
{1, 1, 0, 1, 1},
{0, 1, 1, 0, 1},
{0, 0, 1, 1, 0}};

void dfs(int u, bool visited[]) {
   visited[u] = true;
   for(int v = 0; v < 5; v++) {
      if(graph[u][v]) {
         if(!visited[v])
            dfs(v, visited);
      }
   }
}

bool isConnected() {
   bool *vis = new bool[5];

   for(int u; u < 5; u++) {
      for(int i = 0; i < 5; i++) vis[i] = false;
      dfs(u, vis);
      for(int i = 0; i < 5; i++) if(!vis[i]) return false;
   }
   return true;
}
int main() {
   if(isConnected()) cout << "The Graph is connected.";
   else cout << "The Graph is not connected.";
}
