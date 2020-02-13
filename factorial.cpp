#include <iostream>

using namespace std;

long fact(int n) {
	if (n == 1) return 1;
	else return n * fact(n-1);
}

int main() {
    int num;
    cin >> num;
    cout << fact(num) << endl;

    return 0;
}
