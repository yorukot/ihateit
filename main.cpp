#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int P[2], C[2], S[2], H[2];
    cin >> P[0] >> P[1];
    cin >> C[0] >> C[1];
    cin >> S[0] >> S[1];
    cin >> H[0] >> H[1];

    int profit[2] = {P[0] - C[0], P[1] - C[1]};

    profit[0] = max(profit[0], 0);
    profit[1] = max(profit[1], 0);

    int maxProfit = max(profit[0] * S[0], profit[1] * S[1]);

    int maxProfitIndex = (profit[0] * S[0] > profit[1] * S[1]) ? 0 : 1;

    int maxSales = min(S[maxProfitIndex], H[maxProfitIndex]);

    cout << maxProfit << endl;
    cout << maxSales << " " << maxSales << endl;

    return 0;
}