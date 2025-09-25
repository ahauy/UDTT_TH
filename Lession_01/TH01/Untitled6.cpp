#include <iostream>
#include <algorithm>

using namespace std;

int n, a[100];
bool isFinal;

string students[6] = {"Trang", "Cong", "Trung", "Binh", "Hoang", "Mai"};

void ktao() {
	for(int i = 1; i <= n; i ++) {
		a[i] = i;
	}
}

// 1 3 4 | 9 8 7 5 2

// 1 3 5 | 2 4 7 8 9

void sinh() {
	int i = n - 1;
	while(i >= 1 && a[i] > a[i + 1]) {
		--i;
	}
	
	if(i == 0) {
		isFinal = true;
	} else {
		for(int j = n; j >= i + 1; -- j) {
			if(a[i] < a[j]) {
				swap(a[i], a[j]);
				break;
			}
		}
		reverse(a + i + 1, a + n + 1);
	}
}

int main() {
	n = 6;
	
	isFinal = false;
	ktao();
	
	while(!isFinal) {
		for(int i = 1; i <= n; i++) {
			cout << students[a[i] - 1] << " ";
		}
		cout << endl;
		sinh();
	}
	return 0;
}