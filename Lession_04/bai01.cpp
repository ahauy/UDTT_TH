#include <iostream>
#include <algorithm> // Dùng cho std::sort

using namespace std;

const int MAX_DENOMINATIONS = 10;

// Sắp xếp giảm dần (hỗ trợ cho std::sort)
bool compare_desc(int a, int b) {
    return a > b;
}

void coinChanging(int amount, int denominations[], int n) {
    if (amount < 0 || n <= 0) {
        cout << "Dữ liệu không hợp lệ." << endl;
        return;
    }

    // Sao chép mảng mệnh giá để sắp xếp mà không làm thay đổi mảng gốc
    int sorted_denominations[MAX_DENOMINATIONS];
    for(int i = 0; i < n; ++i) {
        sorted_denominations[i] = denominations[i];
    }

    // Sắp xếp giảm dần để áp dụng chiến lược tham lam
    sort(sorted_denominations, sorted_denominations + n, compare_desc);

    int remaining = amount;
    int counts[MAX_DENOMINATIONS] = {0}; // Mảng lưu số lượng mỗi loại đồng xu

    cout << "Số tiền cần đổi: " << amount << endl;
    cout << "Các mệnh giá (sắp xếp): ";
    for (int i = 0; i < n; ++i) {
        cout << sorted_denominations[i] << " ";
    }
    cout << endl;

    cout << "Kết quả:" << endl;
    for (int i = 0; i < n; ++i) {
        int coin = sorted_denominations[i];
        if (remaining >= coin) {
            int count = remaining / coin;
            remaining %= coin;
            counts[i] = count;
            if (count > 0) {
                cout << "  " << count << " đồng " << coin << endl;
            }
        }
    }

    if (remaining > 0) {
        cout << "Không thể đổi hết số tiền (còn lại: " << remaining << ")." << endl;
    }
}

int main() {
    int denominations[] = {1, 2, 5, 10, 20, 50, 100};
    int n = 7;
    int target_amount = 938; 
    coinChanging(target_amount, denominations, n);
    return 0;
}