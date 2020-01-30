#include <iostream>

using namespace std;

int binarysearch(int arr[], int n, int key) {
    int beg = 0, end = n - 1, mid;
    
    while (beg <= end) {
        mid = (beg + end) / 2;
        
        if (arr[mid] == key) return 1;
        else if (arr[mid] > key) end = mid - 1;
        else beg = mid + 1;
    }
    
    return -1;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    
    // INPUT SORTED ARRAY
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int key;
    cin >> key;
    
    int x = binarysearch(arr, n, key);
    cout << x << endl;
    
    return 0;
}
