#include <iostream>

using namespace std;

int a[100];

int fibonaci(int n) {
	if(n == 0) {
		a[n + 1] = 0; 
	} else if(n == 1 || n == 2) {
		a[n + 1] = 1;
	} else {
		a[n + 1] = fibonaci(n - 1) + fibonaci(n - 2);
	}
	return a[n + 1];
}

int main() {
	
	int n;
	cin >> n;
	fibonaci(n);
	for(int i = 1; i <= n; i ++) {
		cout << a[i] << " ";
	}
	
	return 0;
}