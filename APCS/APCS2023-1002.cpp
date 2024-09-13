#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio;
    cin.tie(0);

    int height, width, answer = 0;
    cin >> height >> width;
    vector<vector<int>> matrix(height, vector<int>(width, 0));
    // 將資料寫入matrix
    for (int h = 0;h < height;h++) {
        for (int w = 0;w < width;w++) {
            int tmp;
            cin >> tmp;
            matrix[h][w] = tmp;
        }
    }

    bool dontstop = true;
    while (dontstop) {
        // 用來表達這次迴圈中matrix是否有進行任何更改
        bool operate = false;
        // 直接遍歷整個matrix 因為matrix最大就40*20 = 800所以還好
        for (int h = 0;h < height;h++) {
            for (int w = 0;w < width;w++) {
                if (matrix[h][w] > -1) {
                    // 往右邊配對
                    // 重複跑到右邊邊界為止
                    for (int r = w + 1;r < width;r++) {
                        // 如果是-1就代表已經被配對過了 所以跳過這一格
                        if (matrix[h][r] < 0) {
                            continue;
                        }
                        // 上面已經檢查過是不是-1 所以這邊如果不同的話就代表沒辦法配對 直接退出迴圈
                        if (matrix[h][w] != matrix[h][r]) {
                            break;;
                        }
                        if (matrix[h][w] == matrix[h][r]) {
                            answer += matrix[h][w];
                            // 將配對的兩個改成-1
                            matrix[h][w] = -1;
                            matrix[h][r] = -1;
                            operate = true;
                        }
                    }
                    // 往下配對
                    // 重複跑到底部邊界為止
                    // 這邊的原理跟往右配對一樣 就不寫解釋了
                    for (int u = h + 1;u < height;u++) {
                        if (matrix[u][w] < 0) {
                            continue;
                        }
                        if (matrix[h][w] != matrix[u][w]) {
                            break;;
                        }
                        if (matrix[h][w] == matrix[u][w]) {
                            answer += matrix[h][w];
                            matrix[h][w] = -1;
                            matrix[u][w] = -1;
                            operate = true;
                        }
                    }
                }
           }
        }
        // 檢查這次迴圈是否進行過操作，如果沒有代表沒配對到，就不需要在跑下一次，所以退出，然後輸出答案
        if (!operate) {
            dontstop = false;
        }
    }
    cout << answer << endl;
}