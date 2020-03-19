#include <iostream>
#include <vector>
using namespace std;

int main() {
  int ver;
  cin >> ver;

  vector<vector<int> > adjmat(ver, vector<int> (ver, 0));  

  for (int i = 0; i < ver; ++i) {
    for (int j = 0; j < ver; ++j) {
      int k;
      cin >> k;
      adjmat[i].push_back(k);
    }
  }

  for (int k = 0; k < ver; ++k) for (int i = 0; i < ver; ++i) for (int j = 0; j < ver; ++j) {
    if (adjmat[i][j] == 1) continue; 
    else if (adjmat[i][k] == 1 and adjmat[k][j] == 1) adjmat[i][j] = 1;
  }

   for (int i = 0; i < ver; ++i) for (int j = 0; j < ver; ++j) cout << adjmat[i][j] << " ";
}
