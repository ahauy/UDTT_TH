#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_PACKAGES = 10;

struct Package {
    int id;
    double volume; 
    double mass;   
    double density; // mass / volume
};

// Sắp xếp giảm dần theo density
bool comparePackages(const Package& a, const Package& b) {
    return a.density > b.density;
}

void container_stacking_greedy(double truck_max_volume_k, double truck_max_mass_l, Package packages[], int n) {
    if (n <= 0 || truck_max_volume_k <= 0 || truck_max_mass_l <= 0) {
        cout << "Dữ liệu không hợp lệ." << endl;
        return;
    }

    // Tính density
    for (int i = 0; i < n; ++i) {
        if (packages[i].volume > 0) {
            packages[i].density = packages[i].mass / packages[i].volume;
        } else {
            packages[i].density = -1.0; 
        }
    }

    // Greedy Step: Sắp xếp giảm dần theo density
    sort(packages, packages + n, comparePackages);

    double current_volume = 0;
    double current_mass = 0;
    int selected_package_ids[MAX_PACKAGES];
    int selected_count = 0;

    cout << "Xe tải: Volume Max=" << truck_max_volume_k << ", Mass Max=" << truck_max_mass_l << endl;
    
    for (int i = 0; i < n; ++i) {
        const Package& p = packages[i];
        
        // Kiểm tra cả hai ràng buộc: thể tích và khối lượng
        if (current_volume + p.volume <= truck_max_volume_k && 
            current_mass + p.mass <= truck_max_mass_l) {
            
            if (selected_count < MAX_PACKAGES) {
                selected_package_ids[selected_count++] = p.id;
                current_volume += p.volume;
                current_mass += p.mass;
                cout << "  + Chọn kiện ID " << p.id << " (Density: " << p.density << "). Volume: " << current_volume << ", Mass: " << current_mass << "." << endl;
            }
        } else {
            cout << "  - Bỏ qua kiện ID " << p.id << " (Density: " << p.density << ", không đủ chỗ/tải trọng)." << endl;
        }
    }

    cout << "\n--- Kết quả Xếp kiện hàng (Greedy) ---" << endl;
    cout << "Tổng khối lượng xếp lên xe đạt lớn nhất: " << current_mass << " kg" << endl;
    cout << "Các kiện hàng đã chọn (ID): ";
    for (int i = 0; i < selected_count; ++i) {
        cout << selected_package_ids[i] << (i == selected_count - 1 ? "" : ", ");
    }
    cout << endl;
}

int main() {
    double max_volume_k = 20.0; 
    double max_mass_l = 100.0; 
    // (id, volume, mass, density - density sẽ được tính)
    Package packages[4] = {
        {1, 5.0, 30.0, 0}, {2, 10.0, 60.0, 0}, {3, 4.0, 12.0, 0}, {4, 6.0, 50.0, 0}
    }; 
    container_stacking_greedy(max_volume_k, max_mass_l, packages, 4);
    return 0;
}