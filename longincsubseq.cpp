#include <iostream> 
#include <vector> 
using namespace std; 

void printLIS(vector<int>& arr) { 
    for (int x : arr) cout << x << " "; 
    cout << endl; 
} 

void LIS(int arr[], int n) { 
    vector<vector<int> > L(n); 
    L[0].push_back(arr[0]); 
    for (int i = 1; i < n; i++) { 
        for (int j = 0; j < i; j++) {
            if ((arr[i] > arr[j]) && (L[i].size() < L[j].size() + 1)) L[i] = L[j]; 
        } 
        L[i].push_back(arr[i]); 
    } 
    vector<int> max = L[0]; 

    for (vector<int> x : L) if (x.size() > max.size()) max = x; 

    printLIS(max); 
} 
  
 
int main() { 
    int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 12 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    LIS(arr, n); 
    return 0; 
} 
