#include <iostream>

using namespace std;

int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
}

int main() {
  cout << gcd(15, 10) << endl;
  return 0;
}