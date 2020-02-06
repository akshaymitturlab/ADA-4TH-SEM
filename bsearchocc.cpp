#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int binsearch(vector<int> &vec, int key) {
    int begr = 0, endr = vec.size() - 1, begl = 0, endle = vec.size() - 1, resultl = -1, resultr = -1, midl, midr;
    while (begr <= endr && begl <= endle) {
        midl = (begl + endle) / 2;
        midr = (begr + endr) / 2;
        
        if (vec[midl] == key) {
            resultl = midl;
            endle = midl - 1;
        }
        
        else if (vec[midr] == key) {
            resultr = midr;
            begr = midr + 1;
        }
        
        else if (vec[midr] > key) endr = midr - 1;
        else if (vec[midl] > key) endle = midl - 1;
        else {
            begr = midr + 1;
            begl = midl + 1;
        }
    }
    if (resultr != -1 && resultl != -1) {
        cout << resultl + 1 << " " << resultr + 1 << endl;
        return (resultr - resultl + 1);
    }
    return -1;
}

int main() {
    vector<int> vec;
    int n, key;
    cin >> n >> key;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    
    cout << binsearch(vec, key) << endl;
    
    return 0;
}
