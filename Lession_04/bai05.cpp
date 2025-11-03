#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int m; // khoi luong: kg
    int k; // kich thuoc: m3
    double ratio;
};

// sap xep giam dan
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n;
    cout << "Nhập số lượng kiện hàng: ";
    cin >> n;

    Item a[n];
    cout << "Nhập m và k: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> a[i].m >> a[i].k;
        a[i].ratio = (double)a[i].m / a[i].k;
    }

    int K;
    cout << "Nhập kích thước thùng xe K: ";
    cin >> K;

    sort(a, a + n, compare);

    cout << "Các kiện hàng được chọn: " << endl;
    int tongKhoiLuong = 0;
    int tongKichThuoc = 0;
    for(int i = 0; i < n; i ++) {
        if(tongKichThuoc + a[i].k <= K) {
            tongKichThuoc += a[i].k;
            tongKhoiLuong += a[i].m;
            cout << "- " << a[i].m << "kg, " << a[i].k << "m3" << endl;
        }   
    }

    cout << "Tổng khối lượng: " << tongKhoiLuong << "kg" << endl;
    cout << "Tổng kích thước đã dùng: " << tongKichThuoc << "/" << K << "m3" << endl;


    return 0;
}