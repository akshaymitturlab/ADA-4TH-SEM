#include <iostream>

using namespace std;

int binarySearch(int arr[], int beg, int end, int key) { 
  if (end < beg) return -1; 
  
  int mid = (beg + end) / 2;
  
  if (key == arr[mid]) return mid; 
      
  if (key > arr[mid]) return binarySearch(arr, mid + 1, end, key); 
  
  return binarySearch(arr, beg, (mid -1), key); 
} 

int findPivot(int arr[], int beg, int end) { 
  if (end < beg) return -1; 
  if (end == beg) return beg; 
  
   int mid = (beg + end) / 2;
   
   if (mid < end && arr[mid] > arr[mid + 1]) return mid; 
   if (mid > beg && arr[mid] < arr[mid - 1]) return (mid-1); 
   if (arr[beg] >= arr[mid]) return findPivot(arr, beg, mid-1); 
   
   return findPivot(arr, mid + 1, end); 
} 
  
int pivotedBinarySearch(int arr[], int n, int key) { 
  int pivot = findPivot(arr, 0, n-1); 
  
  if (pivot == -1) return binarySearch(arr, 0, n - 1, key); 
  
  if (arr[pivot] == key) return pivot; 
      
  if (arr[0] <= key) return binarySearch(arr, 0, pivot - 1, key); 
  
  return binarySearch(arr, pivot + 1, n-1, key); 
}

int main() {
    int n, key;
    cin >> n >> key;
    
    int arr[n];
    
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    cout << "Index of the element is : " <<  pivotedBinarySearch(arr, n, key) << endl;
  
    return 0;
}
