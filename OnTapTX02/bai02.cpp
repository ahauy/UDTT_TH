/*
p: so tien
danh sach d gom n chiec quat ban
quat ban: brand, color, price
KL: voi so tien p co the ban duoc it nhat bao nhieu chiec quat trong danh sach d de so tien ban quat dung bang p, cac chiec quat(brand, price)
*/

#include <iostream>
#include <time.h>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Fan {
  string brand;
  string color;
  int price;
};

// kho du lieu hang va mau sac
string brands[5] = {"Brand A", "Brand B", "Brand C", "Brand D", "Brand D"};
string colors[5] = {"Red", "Blue", "Green", "Black", "White"};
int prices[5] = {100000, 350000, 200000, 600000, 400000};

// khai bao p, d, n;
int p;
int n = 7;
Fan d[100];

void ktaop() {
  srand(time(NULL));
  p = rand() % 1200000 + 1;
}

void ktaod() {
  srand(time(NULL));
  for(int i = 0; i < n; i ++) {
    string brand = brands[rand() % 5];
    string color = colors[rand() % 5];
    int price = prices[rand() % 5];
    d[i] = {brand, color, price};
  }
}

void hienthi() {
  cout << left 
      << setw(7) << "STT"
      << setw(15) << "Brand"
      << setw(15) << "Color"
      <<setw(15) << "Price" << endl;
  for(int i = 0; i < n ; i ++) {
    cout << left 
      << setw(7) << (i + 1)
      << setw(15) << d[i].brand 
      << setw(15) << d[i].color
      <<setw(15) << d[i].price << endl;
  }
}

void sapxep() {
  // sap xep theo chieu tang dan cua price
  for(int i = 0; i < n - 1;  i++) {
    for(int j = n - 1; j > i; j --) {
      if(d[j].price > d[j - 1].price) {
        swap(d[j], d[j - 1]);
      }
    }
  }
}


int main() {
  // ktaop();
  p = 1100000;
  cout << "Số tiền bạn có là: " << p << endl;
  ktaod();
  cout << "Danh sách quạt bàn mà cửa hàng có: " << endl;
  hienthi();
  sapxep();

  int tongSoQuat = 0;
  int soTienDaBan = 0;
  Fan luu[n];
  for(int i = 0; i < n; i ++) {
    if(soTienDaBan + d[i].price <= p) {
      soTienDaBan += d[i].price;
      luu[tongSoQuat] = d[i];
      tongSoQuat ++;
    }
  }
  if(soTienDaBan == p) {
    cout << "Danh sách quạt có thể bán là: " << endl;
    for(int i = 0; i < tongSoQuat; i ++) {
      cout << " - " << luu[i].brand << ", " << luu[i].price << "VND" << endl;
    }
    cout << "Tổng số quạt bạn có thể bán là: " << tongSoQuat << " chiếc" << endl; 
  } else {
    cout << "Không thể bán các chiếc quạt trong danh sách sao cho số tiền bán đúng bằng " << p << endl;
  }
  return 0;
}