#include <iostream>
#include <algorithm>

using namespace std;

int soLuongXeTai = 0;

bool thamlam(int a[], int n, int m, int luu[]) {
    for(int i = 0; i < n; i ++) {
        if(m >= a[i]) {
            m = m - a[i];
            luu[soLuongXeTai] = a[i];
            soLuongXeTai ++;
        }
    }
    if(m == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cout << "Nhập số lượng xe tải: ";
    cin >> n;
    int a[n]; 
    cout << "Nhập trọng lượng cho các xe tải: ";
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int m;
    cout << "Nhập số tấn hàng mà công ty A cần vận chuyển: ";
    cin >> m;
    sort(a, a + n, greater<int>());
    int luu[n];
    memset(luu, 0, sizeof(luu));
    if(thamlam(a, n, m, luu)) {
        cout << "Ta cần ít nhất " << soLuongXeTai << " xe tải để vận chyển " << m << " tấn hàng." << endl;
        cout << "Ta chọn các xe có tải trọng là: " << endl;
        for(int i = 0; i < soLuongXeTai; i ++) {
            cout << luu[i] << endl;
        }
    } else {
        cout << "404" << endl;
    }
    return 0;
}