#include <bits/stdc++.h> 
#include <iostream>

using namespace std; 

int fibonacci (int n)  {
    int first = 0, second = 1, third = 1;
    if (n == 1) return first;
    else if (n == 2) return second;
    else if (n == 3) return third;
    else {
        for (int i = 4; i <= n; ++i) {
            first = second;
            second = third;
            third = first + second;
        }
        return third;
    }
    
}  

int main()  {  
    vector<int> arr = {0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0};
    int n = arr.size();
    vector<int> fibs;
    
    for (int i = 1; i <= n; ++i) fibs.push_back(fibonacci(i));
    arr.push_back(1);

    vector<int> jumps(n + 1, n);
    
    for (int i = 0; i <= n; ++i) {
        if (arr[i] == 1) for (int x: fibs) {
            if (i - x == -1) jumps[i] = 1;
            else if (i - x > -1) jumps[i] = min(jumps[i], jumps[i - x] + 1);
        }
    }
    
    cout << jumps[n];
    
    return 0;  
}
