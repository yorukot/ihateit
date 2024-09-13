#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int height, width, n, total_block = 0, total_waste = 0;
    cin >> height >> width >> n;
    vector<int> matrix(height, 0);

    for (int i = 0;i < n;i++) {
        char sharp;
        int h;
        cin >> sharp >> h;

        if (sharp == 'A') {
            int temp = max({matrix[h] + 1, matrix[h+1] + 1, matrix[h+2] + 1, matrix[h+3] + 1});
            if (temp > width) {
                total_waste++;
                continue;
            }
            matrix[h]=temp;
            matrix[h+1]=temp;
            matrix[h+2]=temp;
            matrix[h+3]=temp;
            total_block+=4;
        }

        if (sharp == 'B') {
            if (matrix[h] + 3 > width) {
                total_waste++;
            } else {
                matrix[h] += 3;
                total_block+=3;
            }
        }

        if (sharp == 'C') {
            int temp = max({matrix[h] + 2, matrix[h+1] + 2});
            if (temp > width) {
                total_waste++;
                continue;
            }
            matrix[h]=temp;
            matrix[h+1]=temp;
            total_block+=4;
        }

        if (sharp == 'D') {
            int temp = max({matrix[h] + 1, matrix[h+1] + 3});
            if (temp > width) {
                total_waste++;
                continue;
            }
            matrix[h]=temp;
            matrix[h+1]=temp;
            total_block+=4;
        }
        
        if (sharp == 'E') {
            int temp = max({matrix[h] + 1, matrix[h+1] + 2, matrix[h+2] + 2});
            if (temp > width) {
                total_waste++;
                continue;
            }
            matrix[h]=temp;
            matrix[h+1]=temp;
            matrix[h+2]=temp;
            total_block+=5;
        }
    }
    cout << (width * height - total_block) << " " << total_waste << endl;

}
