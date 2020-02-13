#include <iostream>
#include <chrono>

using namespace std;

void bubbleSort(int arr[], int n) {  
    int i, j;  
    for (i = 0; i < n - 1; i++)      
        for (j = 0; j < n - i - 1; j++)  
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    auto start = chrono::steady_clock::now();
    
    bubbleSort(arr, n);
    
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    return 0;
}
