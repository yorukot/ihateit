// still not done
#include <bits/stdc++.h>
using namespace std;

set<string> as; // asnswerset

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string k, s;
    int l;
    set<string> answer;

    cin >> k >> l >> s;

    for (int i = 0;i < s.size() - 1; i++) {
        answer.insert((s.substr(i, l)));
    }

    for (int i = 0;i < k.size() - 1; i++) {
        vector<string> answera(l);
        answera[0] = k[1];
        for (int q = 1;q < l;q++) {
            for (int b = 0;b < k.size() - 1; b++) {
                answera[q] = k[b];
                if (q == l - 1) {
                    string temp;
                    for (const auto& ss : answera) {
                        temp += ss;
                    }
                    if (!answer.count(temp)) {
                        cout << temp << endl;
                    }
                }
            }
        }
    }
}