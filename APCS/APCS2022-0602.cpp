#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    string password;
    cin >> m >> n;
    vector<string> input(m);

    for (int i = 0;i < m;i++) {
        string temp;
        cin >> temp;
        input[i] = temp;
    }
    cin >> password;

    for (int i = m - 1;i >= 0;i--) {
        int total_number = 0;
        for (int sl = 0;sl < n;sl++) {
            if (input[i][sl] == '1') {
                total_number++;
            }
        }
        string temp_string = "";
        temp_string = password;
        string temp_password = "";
        for (int sl = n - 1;sl > -1;sl--) {
            if (input[i][sl] == '1') {
                temp_password += temp_string[temp_string.length() - 1];
                temp_string.erase(temp_string.length() - 1);
            } else {
                temp_password = temp_string[temp_string.length() - 1] + temp_password ;
                temp_string.erase(temp_string.length() - 1);
            }
        }
        password = temp_password;
        if (total_number % 2 != 0) {
            string front_password = temp_password.substr(0,abs(n/2));
            string end_password = "";
            if (n % 2 != 0) {
                front_password = temp_password[abs(n/2)] + front_password;
                end_password = temp_password.substr(abs(n/2) + 1,abs(n/2));
            } else {
                end_password = temp_password.substr(abs(n/2),abs(n/2));
            }
            front_password = end_password + front_password;
            password = front_password;
        }
    }
    cout << password << endl;
}