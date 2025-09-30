#include <iostream>

using namespace std;

int n, x[100], a[100][100];
bool cot[100], xuoi[100], nguoc[100];

void display() {
  memset(a, 0, sizeof(a));
  for(int i = 1; i <= n; i ++) {
    a[i][x[i]] = 1;
  }

  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= n; j ++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void Try(int i) {
  for(int j = 1; j <= n; j ++) {
    if(cot[j] == false && xuoi[i - j + n] == false && nguoc[i + j - 1] == false) {
      cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = true;
      x[i] = j;
      if( i == n ) {
        display();
      } else {
        Try(i + 1);
      }
      cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = false;
    }
  }
}

int main() {

  n = 8;
  Try(1);
  

  return 0;
}