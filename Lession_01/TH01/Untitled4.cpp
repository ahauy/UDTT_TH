#include <iostream>

using namespace std;

int n, k, a[100];
bool isFinal;

string students[6] = {"Trang", "Cong", "Trung", "Binh", "Hoang", "Mai"};

void ktao() {
	for(int i = 1; i <= k; i ++) {
		a[i] = i;
	}
}

// 1 2 3 4 5
// 1 2 
// 2 3 4

void sinh() {
	int i = k;
	while(i >= 1 && a[i] == n - k + i) {
		-- i;
	}
	
	if( i == 0 ) {
		isFinal = true;
	} else {
		a[i] ++;
		for(int j = i + 1; j <= k; j ++) {
			a[j] = a[j - 1] + 1;
		}
	}
}


int main() {
	
	n = 6; 
	k = 4;
	isFinal = false;
	ktao();
	while(!isFinal) {
		for(int i = 1; i <= k; i ++) {
			cout << students[a[i] - 1] << " ";
		}
		cout << endl;
		sinh();
	}
	return 0;
}