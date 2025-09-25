#include <iostream>

using namespace std;

int n, a[100];

void generateArr() {
	for(int i = 0; i < n; i ++) {
		a[i] = rand() % 10;
	}
}

// 1 7 4 0 9
// 0 1 2 3 4
int sumOdd(int n) {
	int sum = 0;
	if(n == -1) {
		return 0;
	}
	
	int eleEnd = a[n - 1];
	if(a[n - 1] % 2 == 1) {
		return eleEnd + sumOdd(n - 1);
	} else {
		return sumOdd(n - 1);
	}
}

//sum + sum(4) -> sum + sum(3)

void display() {
	for(int i = 0; i < n; i ++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	
	cin >> n;
	generateArr();
	display();
	cout << "Tong cac so le trong day la: " << sumOdd(n) << endl;
	
	return 0;
}