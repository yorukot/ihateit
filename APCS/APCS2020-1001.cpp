#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A1, B1, C1;
    int A2, B2, C2;
    int n;
    cin >> A1 >> B1 >> C1 >> A2 >> B2 >> C2 >> n;
    int answer = INT_MIN;
    for (int i = 0;i <= n;i++) {
        int X1 = i, X2 = n - i;
        int Y1 = A1 * X1 * X1 + B1 * X1 + C1;
        int Y2 = A2 * X2 * X2 + B2 * X2 + C2;
        answer = max(answer, Y1+Y2);
    }
    cout << answer << endl;
}