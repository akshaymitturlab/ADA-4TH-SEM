#include <iostream>

using namespace std;

void tower_hanoi(int n, char src, char temp, char dest) {
  if(n == 1) {
		cout << "Move " << n << " disc from " << src << " to " << dest << endl;
		return ;
    }
  
	tower_hanoi(n - 1, src, dest, temp);
  
	cout << "Move " << n <<  " disc from " << src <<  " to " << dest << endl;
  
	tower_hanoi(n - 1, temp, src, dest);
}

int main() {
    int x;
  
	cout << "Enter no of disc" << endl;
	cin >> x;
  
	tower_hanoi(x, 'A', 'B', 'C');

    return 0;
}
