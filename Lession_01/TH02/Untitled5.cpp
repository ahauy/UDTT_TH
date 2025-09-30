#include <iostream>

using namespace std;

void towerOfHaNoi(int n, char goc, char trungGian, char dich) {
  if(n == 1) {
    cout << "Chuyển 1 đĩa tử " << goc << " tới " << dich << endl;
    return;
  } else {
    towerOfHaNoi(n - 1, goc, dich, trungGian);
    towerOfHaNoi(1, goc, trungGian, dich);
    towerOfHaNoi(n- 1, trungGian, goc, dich);
  }
}

int main() {

  towerOfHaNoi(3, 'A', 'B', 'C');

  return 0;
}