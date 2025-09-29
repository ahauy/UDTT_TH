#include <iostream>

using namespace std;

int fibonaci(int n) {
  if(n == 1) {
    return 0;
  } else if(n == 2 || n == 3) {
    return 1;
  } else {
    return fibonaci(n - 1) + fibonaci(n - 2);
  }
}

int main() {

  cout << fibonaci(20) << endl;
  return 0;
}