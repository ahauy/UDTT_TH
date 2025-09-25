#include <iostream>

using namespace std;

const int N = 5;

int grid[N][N];
bool flag[N][N];

// khoi tao grid
void generateGrid() {
	for(int i = 0; i < N; i ++) {
		for(int j = 0; j < N; j ++) {
			grid[i][j] = rand() % 10;
		}
	}
}

// ktra xem vi tri dang xet co nam trong luoi hay khong
bool valid(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < N);
}


// thuat toan loang
void loang(int i, int j) {
	flag[i][j] = true;
	if(i > 0) {
		if(valid(i - 1, j) && grid[i - 1][j] == grid[i][j] && !flag[i - 1][j]) {
			loang(i - 1, j);
		}
	}
	
	if(i < N) {
		if(valid(i + 1, j) && grid[i + 1][j] == grid[i][j] && !flag[i + 1][j]) {
			loang(i + 1, j);
		}
	}
	
	if(j > 0) {
		if(valid(i, j - 1) && grid[i][j - 1] == grid[i][j] && !flag[i][j - 1]) {
			loang(i, j - 1);
		}
	}
	
	if(j < N) {
		if(valid(i, j + 1) && grid[i][j + 1] == grid[i][j] && !flag[i][j + 1]) {
			loang(i, j + 1);
		}
	}
}

int main() {
	
	generateGrid();
	cout << "Mang luoi ban dau: " << endl;
	for(int i = 0; i < N; i ++) {
		for(int j = 0; j < N; j ++) {
			cout << grid[i][j] << " "; 
		}
		cout << endl;
	}
	
	int region = 0;
	for(int i = 0; i < N; i ++) {
		for(int j = 0; j < N; j ++) {
			if(grid[i][j] == 5 && !flag[i][j]) {
				region ++;
				loang(i, j);
			}
		}
	}
	
	cout << "Mang danh dau: " << endl;
	for(int i = 0; i < N; i ++) {
		for(int j = 0; j < N; j ++) {
			cout << flag[i][j] << " "; 
		}
		cout << endl;
	}
	
	cout << "So mien lien thong la: " << region << endl;
	
	
	return 0;
}