#include <bits/stdc++.h>

using namespace std;

int main() {
    int answer_one = 0, answer_two = 0;
    int n, d;
    vector<vector<int>> product;
    cin >> n >> d;

    for (int i = 0;i < n; i++) {
        vector<int> temp_three_day;
        int temp;
        cin >> temp;
        temp_three_day.push_back(temp);
        cin >> temp;
        temp_three_day.push_back(temp);
        cin >> temp;
        temp_three_day.push_back(temp);
        product.push_back(temp_three_day);
    }

    for (int i = 0;i < n; i++) {
        int max_number = 0, min_number = 0;
        max_number = max(product[i][0], product[i][1]);
        max_number = max(max_number, product[i][2]);

        min_number = min(product[i][0], product[i][1]);
        min_number = min(min_number, product[i][2]);

        if (max_number - min_number >= d) {
            int total = 0, avager = 0;
            total += product[i][0];
            total += product[i][1];
            total += product[i][2];
            avager = total / 3;
            answer_one++;
            answer_two += avager;
        }
    }

    cout << answer_one << " " << answer_two;
}