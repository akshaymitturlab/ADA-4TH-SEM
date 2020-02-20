#include <iostream>
#include <chrono>

using namespace std;

void modBubbleSort(int arr[], int n) {  
    int i, j;  
    for (i = 0; i < n - 1; i++) {
        int flag = 0;
        for (j = 0; j < n - i - 1; j++)  
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                flag++;
            }
        if (flag == 0) break;
    }
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    modBubbleSort(arr, n);
    
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}
