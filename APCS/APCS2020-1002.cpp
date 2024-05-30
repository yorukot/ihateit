#include<bits/stdc++.h>

using namespace std;

int main() {
    int R, C, k, m;
    cin >> R >> C >> k >> m;
    vector<vector<int>> org_city(R, vector<int>(C, 0));
    vector<vector<int>> add_array(R, vector<int>(C, 0));
    vector<vector<int>> empty_array(R, vector<int>(C, 0));

    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cin >> org_city[y][x];
        }
    }

    for (int run_times = 0; run_times < m; run_times++) {
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                if (org_city[y][x] < 0 || org_city[y][x] == 0 ) {
                    continue;
                }

                int add = org_city[y][x] / k;
                if (add > 0) {
                    int total_add = 0;
                    if (y > 0 && org_city[y - 1][x] != -1) {
                        add_array[y - 1][x] += add;
                        total_add++;
                    }
                    if (x > 0 && org_city[y][x - 1] != -1) {
                        add_array[y][x - 1] += add;
                        total_add++;
                    }
                    if (x != C - 1 && org_city[y][x + 1] != -1) {
                        add_array[y][x + 1] += add;
                        total_add++;
                    }
                    if (y != R - 1 && org_city[y + 1][x] != -1) {
                        add_array[y + 1][x] += add;
                        total_add++;
                    }
                    add_array[y][x] -= total_add*add;
                }
            }
        }


        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                if (org_city[y][x] < 0) {
                    continue;
                }
                org_city[y][x] += add_array[y][x];
            }
        }

        add_array = empty_array;
    }

    int minans=INT_MAX,maxans=0;
    for(int y = 0;y < R;y++) {
        for(int x = 0;x < C;x++){
    	    if(org_city[y][x]!=-1) {
                minans=min(minans,org_city[y][x]);
        	    maxans=max(maxans,org_city[y][x]);
            }
        }
    }


    cout << minans << endl << maxans << endl;

    return 0;
}