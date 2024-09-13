#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> stop;
    int n, max = 0, min = INT_MAX;
    cin >> n;

    for (int i = 0;i < n; i++) {
        int ip1, ip2;
        cin >> ip1 >> ip2;
        vector<int> temp;
        temp.push_back(ip1);
        temp.push_back(ip2);
        stop.push_back(temp);
    }

    for (int i = 0; i < n-1; i++) {
        int next_stop = i + 1;
        int number = abs(stop[i][0] - stop[next_stop][0]) + abs(stop[i][1] - stop[next_stop][1]);
        if (number > max) {
            max = number;
        }
        if (number < min) {
            min = number;
        }
    }

    cout << max << " " << min << endl;
}