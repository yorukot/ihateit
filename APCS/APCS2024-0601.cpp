#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int temp_answer = 0,min = 0,total = 0,answer = 0;
    
    cin >> total;

    vector<int> building;
    for (int i = 0; i < total; i++)
    {
        int temp;
        cin >> temp;
        building.push_back(temp);
    }

    for (int i = 0; i < total; i++)
    {
        if (building[i] < min || min == 0) {
            min = building[i];
            temp_answer++;
        } else {
            if (temp_answer > answer) {
                answer = temp_answer;
            }
            temp_answer = 1;
            min = building[i];            
        }
    }
    if (temp_answer > answer) {
        answer = temp_answer;
    }
    cout << answer;
}