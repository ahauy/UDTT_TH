#include <iostream>

using namespace std;

int n, a[100];
bool isFinal;

void ktao() {
	for(int i = 1; i <= n; i ++) {
		a[i] = 0;
	}
}

void sinh() {
	int i = n;
	while(i >= 1 && a[i] == 1) {
		a[i] = 0;
		--i;
	}
	
	if(i == 0) {
		isFinal = true;
	} else {
		a[i] = 1;
	}
}

int main() {
	
	cin >> n;
	isFinal = false;
	ktao();
	while(!isFinal) {
		for(int i = 1; i <= n; i ++) {
			cout << a[i];
		}
		cout << endl;
		sinh();
	}
	
	return 0;
}