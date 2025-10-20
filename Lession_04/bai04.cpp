#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_TRUCKS = 10;

// Sắp xếp giảm dần cho kiểu double
bool compare_double_desc(double a, double b) {
    return a > b;
}

void truck_selection_greedy(double total_goods_m, double capacities[], int n) {
    if (total_goods_m <= 0 || n <= 0) {
        cout << "Dữ liệu không hợp lệ." << endl;
        return;
    }

    // Greedy Step: Sắp xếp sức tải giảm dần
    sort(capacities, capacities + n, compare_double_desc);

    cout << "Tổng lượng hàng cần vận chuyển (m): " << total_goods_m << " tấn" << endl;
    cout << "Danh sách sức tải (sắp xếp giảm dần): ";
    for (int i = 0; i < n; ++i) {
        cout << capacities[i] << " ";
    }
    cout << endl;

    double remaining_goods = total_goods_m;
    int trucks_used = 0;
    double selected_capacities[MAX_TRUCKS];

    cout << "\nQuá trình chọn xe tải:" << endl;
    for (int i = 0; i < n; ++i) {
        if (remaining_goods <= 0) break; 

        double capacity = capacities[i];
        
        if (capacity > 0) {
            selected_capacities[trucks_used] = capacity;
            trucks_used++;
            remaining_goods -= capacity;
            
            cout << "  - Chọn xe tải sức tải: " << capacity << " tấn. Lượng hàng còn lại: " 
                 << max(0.0, remaining_goods) << " tấn." << endl;
        }
    }

    cout << "\n--- Kết quả Chọn xe tải (Greedy) ---" << endl;
    cout << "Tổng số xe tải cần sử dụng (tối thiểu): " << trucks_used << endl;
    
    if (remaining_goods > 0) {
        cout << "⚠️ Không đủ sức tải để vận chuyển hết lượng hàng! (Còn lại: " 
             << remaining_goods << " tấn)" << endl;
    } else {
        cout << "Đã vận chuyển hết hàng." << endl;
    }
}

int main() {
    double goods_m = 100.0; 
    double truck_capacities[5] = {20.0, 50.0, 10.0, 30.0, 40.0}; 
    truck_selection_greedy(goods_m, truck_capacities, 5);
    return 0;
}