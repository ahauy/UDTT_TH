#include <iostream>

using namespace std;

int n;



void hthi(double a[]) {
	for(int i = 0; i < n; i ++) {
		cout << a[i] << " ";
	}
	cout  << endl;
}

double sum(double a[], int l, int r) {
	if(l == r) {
		if(a[l] > 0) {
			return a[l];
		} else {
			return 0;
		}
	}
	
	int mid = (l + r) / 2;
	double sumLeft = sum(a, l, mid);
	double sumRight = sum(a, mid + 1, r);
	return sumLeft + sumRight;
}

int main() {
	
	n = 5;
	double a[5] = {-5, 10, -4, 0, 5};
	hthi(a);
	cout << sum(a, 0, n - 1);
	
	
	return 0;
}