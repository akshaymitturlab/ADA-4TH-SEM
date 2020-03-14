#include<iostream>
#include<set>

using namespace std;

int arr[30][30];

bool dfs(int vertex, set<int>&visited, int parent,int n) {
	visited.insert(vertex);
  	for(int v = 0; v<n; v++) {
        	if(arr[vertex][v]) {
         		if(v == parent)    //if v is the parent not move that direction
            			continue;
         		if(visited.find(v) != visited.end())    //if v is already visited
            			return true;
         		if(dfs(v, visited, vertex,n))
            			return true;
      		}
   	}
   	return false;
}

bool hasCycle(int n) {
	set<int>visited;
        for(int v = 0; v<n; v++) {
      		if(visited.find(v) != visited.end())
         		continue;
     		if(dfs(v, visited, -1,n)) {
         		return true;
      		}
  	}	
   	return false;
}

int main() {
	bool res;
  int n;
	cin>>n;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>arr[i][j];

	
   	res = hasCycle(n);
   	if(res) cout << "Cycle" << endl;
   	else cout << "No Cycle" << endl;
    	return 0;
}
