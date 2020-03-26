#include <iostream> 
using namespace std; 
  
void findGrid(int n) { 
    int arr[n][n]; 
    int x = 0; 
  
    for (int i = 0; i < n / 4; i++) for (int j = 0; j < n / 4; j++) for (int k = 0; k < 4; k++) for (int l = 0; l < 4; l++) { 
                    arr[i * 4 + k][j * 4 + l] = x; 
                    x++; 
                }

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) cout << arr[i][j] << " ";  
        cout << "\n"; 
    } 
} 
  
int main() { 
    int n; 
    cin >> n;

    findGrid(n); 
  
    return 0; 
}
