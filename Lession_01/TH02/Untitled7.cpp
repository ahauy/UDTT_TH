#include <iostream>

using namespace std;

int n, x[100];

void display()
{
  for (int i = 1; i <= n; i++)
  {
    cout << x[i];
  }
  cout << endl;
}

void Try(int i)
{
  for (int j = 0; j <= 1; j++)
  {
    x[i] = j;
    if (i == n)
    {
      display();
    }
    else
    {
      Try(i + 1);
    }
  }
}

int main()
{

  n = 4;
  Try(1);

  return 0;
}