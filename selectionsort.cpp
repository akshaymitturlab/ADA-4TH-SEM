#include <iostream>
#include <chrono>

using namespace std;

void selectionSort(int arr[], int n) {  
    int i, j, small;
    for (i = 0; i < n - 1; i++) {
        small = i;
        for (j = i + 1; j < n; j++) if (arr[j] < arr[small]) small = j;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    auto start = chrono::steady_clock::now();
    
    selectionSort(arr, n);
    
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    return 0;
}
