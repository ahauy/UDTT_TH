#include <iostream>

using namespace std;

int n;

int sum(int n) {
	if(n < 10) {
		return n;
	} else {
		return n % 10 + sum(n / 10);
	}
}

int main() {
	cin >> n;
	cout << "Tong cac chu so cua " << n << " la: " << sum(n);
	return 0;
}