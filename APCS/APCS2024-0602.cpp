#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> canvas(h, vector<int>(w, 0));

    for (int i = 0;i<n;i++) {
        int r,c,t,x;
        cin >> r >> c >> t >> x;
        for (int th = 0;th < h; th++){
            int hr = abs(th-r);
            if(hr <= t) {
                for (int tw = 0;tw < w; tw++){
                    int wr = abs(tw-c);
                    if (wr + hr <= t ) {
                        canvas[th][tw] += x;
                    }
                }
            }
        }
    }

    for (int th = 0;th < h; th++){
        for (int tw = 0;tw < w; tw++){
            if (tw == w-1) {
                cout << canvas[th][tw] << endl;
            } else {
                cout << canvas[th][tw] << " ";
            }
        }
    }
}