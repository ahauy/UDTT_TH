#include <iostream>

using namespace std;

int n;
char a[100];
bool isFinal;

void ktao() {
	for(int i = 1; i <= n; i ++) {
		a[i] = 'a';
	}
}

void sinh() {
	int i = n;
	while(i >= 1 && a[i] == 'b') {
		a[i] = 'a';
		--i;
	}
	
	if(i == 0) {
		isFinal = true;
	} else {
		a[i] = 'b';
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