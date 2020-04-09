#include <iostream> 
#include <limits.h> 
using namespace std;

int max(int a, int b) { return (a > b)? a : b;} 

int cutRod(int price[], int n) { 
   int val[n+1]; 
   val[0] = 0; 
   int i, j; 

   for (i = 1; i<=n; i++) { 
       int max_val = INT_MIN; 
       for (j = 0; j < i; j++) max_val = max(max_val, price[j] + val[i-j-1]); 
       val[i] = max_val; 
   } 
   return val[n]; 
} 
  
int main() {
    int len;
    cin >> len;
    int arr[len]; 
    for (int i = 0; i < len; ++i) cin >>arr[i]; 
    cout << cutRod(arr, len); 
    return 0; 
} 
