#include <bits/stdc++.h> 
using namespace std; 

void floydWarshall (int graph[][4])  {  
    int dist[4][4], i, j, k;  
    for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) dist[i][j] = graph[i][j];  

    for (k = 0; k < 4; k++) for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];  

    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 4; j++)  {  
            if (dist[i][j] == 9999) cout<<"INFINITY"<<"     ";  
            else cout<<dist[i][j]<<"     ";  
        } 
        cout << endl;
    }
}  
//INFINITY = 9999
int main()  {  
    int graph[4][4] = { {0, 4, 9999, 10}, {9999, 0, 6, 9999}, {9999, 9999, 0, 8}, {9999, 9999, 9999, 0} };  
  
    floydWarshall(graph);
    
    return 0;  
}
