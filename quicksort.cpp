#include <iostream>
#include <chrono>

using namespace std;

int partition (int arr[], int low, int high) {  
    int pivot = arr[high];  
    int i = (low - 1);  
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {  
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }  
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);  
}  

void quickSort(int arr[], int low, int high) {  
    if (low < high) {  
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    auto start = chrono::steady_clock::now();
    
    quickSort(arr, 0, n - 1); 
    
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
    
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    return 0;
}
