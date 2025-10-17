#include <iostream>
#include <time.h>

using namespace std;

int a[100], n;

void init() {
  srand(time(NULL));
  for(int i = 0; i < n; i ++) {
    a[i] = rand() % 20; 
  }
}

void display() {
  for(int i = 0; i < n; i ++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

int max(int a[], int l, int r) {
  if(l == r) {
    return a[l];
  }
  int m = (l + r) / 2;
  int left = max(a, l, m);
  int right = max(a, m + 1, r);
  return left > right ? left : right;
}

int main() {
  n = 10;
  init();
  display();
  cout << "Gia tri lon nhat trong mang: " << max(a, 0, n - 1) << endl;
  return 0;
}