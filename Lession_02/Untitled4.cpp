#include <iostream>

using namespace std;

double a;
int n;


// a^7 
// a^(3*2) *a
double hamMu(double a, int n) {
	if(n == 1) {
		return a;
	}
	
	double p = hamMu(a, n / 2);
	if(n % 2 == 0) {
		return p * p; 
	} else {
		return p * p * a;
	}
}

int main() {
	
	cout << hamMu(2, 8) << endl;
	
	return 0;
}