#include <iostream>
using namespace std;

void displaySubset(int subSet[], int size) {
   for(int i = 0; i < size; i++) cout << subSet[i] << "  ";
   cout << endl;
}

void subsetSum(int set[], int subSet[], int n, int subSize, int total, int nodeCount ,int sum) {
   if( total == sum) {
      displaySubset(subSet, subSize);
      subsetSum(set, subSet, n, subSize - 1, total-set[nodeCount], nodeCount + 1, sum);
      return;
   } else {
      for( int i = nodeCount; i < n; i++ ) { 
         subSet[subSize] = set[i];
         subsetSum(set, subSet, n, subSize + 1, total + set[i], i + 1, sum);
      }
   }
}

void findSubset(int set[], int size, int sum) {
   int *subSet = new int[size];
   subsetSum(set, subSet, size, 0, 0, 0, sum);
   delete[] subSet;
}

int main() {
   int n, k;
   cin >> n >> k;
   int arr[n];
   for (int i = 0; i < n; ++i) cin >> arr[i];
   findSubset(arr, n, k);
}
