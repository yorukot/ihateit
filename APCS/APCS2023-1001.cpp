#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    vector<int> food(n);
    cin >> x >> n;

    int left = 0, right = 0, leftac = INT_MAX, rightac = INT_MIN;
    for (int i = 0; i < n;i++) {
        int temp;
        cin >> temp;
        if (temp < x) {
            left++;
            leftac = min(temp, leftac);
        } else {
            right++;
            rightac = max(temp, rightac);
        }
    }
    if (left > right) {
        cout << left << " " << leftac;
    } else {
        cout << right << " " << rightac;
    }
}