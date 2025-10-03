#include <iostream>

using namespace std;

int n, a[100];

void ktao() {
	for(int i = 0; i < n; i ++) {
		a[i] = rand() &  20;
	}
}

void hthi() {
	for(int i = 0; i < n; i ++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int min(int a[], int l, int r) {
	if(l == r) {
		if(a[l] % 2 == 0) {
			return a[l];
		} else {
			return 0;
		}
	}
	
	int mid = (l + r) / 2;
	
	int minLeft = min(a, l, mid);
	int minRight = min(a, mid + 1, r);
	return minLeft < minRight ? minLeft : minRight;
}

int main() {
	
	n = 20;
	ktao();
	hthi();
	cout << min(a, 0, n - 1);
	return 0;
}