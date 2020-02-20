#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> vec;
    
    int n, k;
    cin >> n >> k;
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    
    sort(vec.begin(), vec.end(), greater<int>());
    
    for (auto it = vec.begin(); it != vec.begin() + k; ++it) cout << *it << " ";
    cout << endl;
    return 0;
}
