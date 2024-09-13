#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int total = 0;
    int height, width;
    cin >> height >> width;

    total += (width + 1) * 2 * height;
    total += (height + 1) * width;

    cout << total;
}