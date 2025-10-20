#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Container {
    int id;
    double capacity; // Dung tích (ví dụ: m^3)
    double value_per_unit; // Giá trị/đơn vị dung tích (ví dụ: tiền/m^3)
    double total_value;
};

// Custom comparison function for the greedy strategy: 
// prioritize containers with higher value_per_unit
bool compareContainers(const Container& a, const Container& b) {
    return a.value_per_unit > b.value_per_unit;
}

// Greedy algorithm for a "water problem" (maximize value with limited water supply)
void water_filling_greedy(double water_supply, vector<Container>& containers) {
    cout << "Nguồn cung cấp nước tối đa: " << water_supply << endl;

    // Greedy Step: Sort by value_per_unit in descending order
    sort(containers.begin(), containers.end(), compareContainers);

    double total_value_filled = 0;
    double water_used = 0;
    vector<pair<int, double>> filled_amounts; // <Container ID, Amount filled>

    cout << "Quyết định lấp đầy (ưu tiên giá trị/đơn vị cao nhất):" << endl;
    for (const auto& c : containers) {
        if (water_supply <= 0) break;

        // Take the minimum of remaining supply and container's capacity
        double fill_amount = min(water_supply, c.capacity);

        if (fill_amount > 0) {
            water_used += fill_amount;
            double value_gained = fill_amount * c.value_per_unit;
            total_value_filled += value_gained;
            water_supply -= fill_amount;
            
            filled_amounts.push_back({c.id, fill_amount});
            cout << "  - Container " << c.id << ": Lấp đầy " << fill_amount 
                 << " (Giá trị/đơn vị: " << c.value_per_unit << ")" << endl;
        }
    }

    cout << "\n--- Tóm tắt ---" << endl;
    cout << "Tổng lượng nước đã sử dụng: " << water_used << endl;
    cout << "Tổng giá trị đạt được: " << total_value_filled << endl;
}

int main() {
    vector<Container> containers = {
        {1, 10.0, 5.0, 0}, // id, capacity, value_per_unit, total_value
        {2, 5.0, 12.0, 0},
        {3, 20.0, 3.0, 0},
        {4, 8.0, 7.0, 0}
    };
    double initial_water_supply = 25.0; // Giả sử có 25 đơn vị nước

    water_filling_greedy(initial_water_supply, containers);
    
    // system("pause");
    return 0;
}