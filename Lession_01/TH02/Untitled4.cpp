#include <iostream>

using namespace std;

int fibonaci(int n)
{
    if (n == 1) return 0;
    if (n == 2) return 1;

    int f1 = 0, f2 = 1, fn;
    for (int i = 3; i <= n; i++) {
        fn = f1 + f2;  // F(n) = F(n-1) + F(n-2)
        f1 = f2;
        f2 = fn;
    }
    return fn;
}


int main()
{
  cout << fibonaci(3) << endl;
  return 0;
}