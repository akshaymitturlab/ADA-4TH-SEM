#include <iostream>
#include <chrono>

using namespace std;

int binarySearch(int arr[], int beg, int end, int key) { 
    if (end >= beg) { 
        int mid = beg + (end - beg) / 2; 
  
        if (arr[mid] == key) 
            return mid; 
  
        if (arr[mid] > key) 
            return binarySearch(arr, beg, mid - 1, key); 
  
        return binarySearch(arr, mid + 1, end, key); 
    } 
  
    return -1; 
}
int linSearch(int arr[], int beg, int end, int key) { 
    if (end < beg) return -1;
    
    if (arr[beg] == key) return beg;
    
    if (arr[end] == key) return end;
    
    return linSearch(arr, beg + 1,  end - 1, key); 
} 

int main() {
    int n, choice, key;
    cin >> n >> key;
    
    int arr[n];
    
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    
    cin >> choice;
    auto start = chrono::steady_clock::now();
    
    if (choice == 1) {
        int x = binarySearch(arr, 0, n - 1, key);
        cout << x << endl;
    }
    else if (choice == 2) {
        int x = linSearch(arr, 0, n - 1, key);
        cout << x << endl;
    }
    else cout << "Invalid" << endl;
    
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    return 0;
}
