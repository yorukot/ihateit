#include <bits/stdc++.h>
using namespace std;

vector<int> c[100000];
int answer = 0;

int dfs(int n){
    vector<int> farthest(2);
    for(int ch: c[n]) {
        farthest.push_back(dfs(ch));
    }
    sort(farthest.begin(), farthest.end(), greater<int>());
    answer = max(answer, farthest[0] + farthest[1]);
    return 1 + farthest[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int root, total, f[100000] = {};
    cin >> total;
    while (--total){
        int fn, cn = {};
        cin >> fn >> cn; // fn = father node, cn = child node 
        c[fn].push_back(cn);
        f[cn] = 1;
    }
    for(root = 0;f[root];root++);
    dfs(root);
    cout <<  answer;
}

