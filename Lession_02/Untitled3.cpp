#include <iostream>

using namespace std;

int n;
float a[100];

void ktao() {
	for(int i = 0; i < n; i ++) {
		a[i] = rand()%20;
	}
}

void hthi() {
	for(int i = 0; i < n; i ++) {
		cout << a[i] << " ";
	}
	cout  << endl;
}

// 1 7 14 0 9 4 18 18 2 4 5 5 1 7 1
int max(float a[], int l, int r) {
	if(l == r) {
		return l;
	}
	
	int mid = (l + r) / 2;
	int maxLeft = max(a, l , mid);
	int maxRight = max(a, mid + 1, r);
	 return (a[maxLeft] >= a[maxRight]) ? maxLeft : maxRight;
}

int main() {
	
	n = 15;
	ktao();
	hthi();
	cout << a[max(a, 0, n - 1)];
	
	return 0;
}