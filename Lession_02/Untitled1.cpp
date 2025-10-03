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

// 1 2 3 4 5 6 
void merge(float a[], int l, int mid, int r) {
	
	int lengthLeft = mid - l + 1;
	int lengthRight = r - mid;
	
	float left[lengthLeft], right[lengthRight];
	
	
	for(int i = 0; i < lengthLeft; i ++) {
		left[i] = a[l + i];
	}
	for(int i = 0; i < lengthRight; i ++) {
		right[i] = a[mid + 1 + i];
	}
	
	
	int i = 0, j = 0, k = l;
	while(i < lengthLeft && j < lengthRight) {
		if(left[i] <= right[j]) {
			a[k] = left[i];
			i ++;
		} else {
			a[k] = right[j];
			j ++;
		}
		
		k ++;
	}
	
	while(i < lengthLeft) {
		a[k] = left[i];
		i ++;
		k ++;
	}
	
	while(j < lengthRight) {
		a[k] = right[j];
		j ++;
		k ++;
	}
}


void mergeSort(float a[], int l, int r) {
	if(l == r) {
		return;
	}
	int mid = (l + r) / 2;
	mergeSort(a, l, mid);
	mergeSort(a, mid + 1, r);
	merge(a, l, mid, r);
}

int main() {
	
	n  = 15;
	ktao();
	hthi();
	mergeSort(a, 0, n - 1);
	hthi();
	return 0;
}