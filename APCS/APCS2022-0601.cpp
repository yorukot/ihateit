#include <bits/stdc++.h>

using namespace std;

int main() {
    int x,y,z;
    cin >> x >> y >> z;

    int answer = 0;

    vector<int> temp(10, 0);
    vector<bool> dsadsa(10, false);
    vector<int> aaa(3, 0);
    aaa[0] = x;
    aaa[1] = y;
    aaa[2] = z;
    temp[x]++;
    temp[y]++;
    temp[z]++;

    for (int i = 0; i < 10;i++) {
        if (temp[i] > answer) {
            answer = temp[i];
        }
    }

    cout << answer << " ";

    sort(aaa.begin(), aaa.end());


    for (int i = 2; i > -1;i--) {
        if (!dsadsa[aaa[i]]) {
            dsadsa[aaa[i]] = true;
            cout << aaa[i] << " ";
        }
    }

    cout << endl;
    return 0;
}