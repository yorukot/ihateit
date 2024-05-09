// 數字龍捲風
// https://zerojudge.tw/ShowProblem?problemid=c292
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int total_line;
    int angle;
    cin >> total_line >> angle;
    vector<vector<int>> numbers(total_line, vector<int>(total_line));

    for(int y = 0; y < total_line; y++) {
        for(int x = 0; x < total_line; x++) {
            cin >> numbers[y][x];
        }
    }

    int middle_number = total_line / 2;
    int total_move_cout = total_line*total_line - 1;
    int total_move = 0;

    vector<int> now_local(2);
    now_local[0] = middle_number;
    now_local[1] = middle_number;
    
    cout << numbers[now_local[0]][now_local[1]];
    
    int need_move = 1;
    int temp_total_move = 0;
    while (total_move != total_move_cout){
        if (temp_total_move < 2 || total_move_cout - total_move + 1 == total_line) {
            // left
            if (angle == 0) {
                for(int i = 0;i < need_move;i++) {
                    now_local[1]--;
                    cout << numbers[now_local[0]][now_local[1]];
                }
            // up    
            } else if (angle == 1) {
                for(int i = 0;i < need_move;i++) {
                    now_local[0]--;
                    cout << numbers[now_local[0]][now_local[1]];
                }
            // right
            } else if (angle == 2) {
                for(int i = 0;i < need_move;i++) {
                    now_local[1]++;
                    cout << numbers[now_local[0]][now_local[1]];
                }
            // down
            } else if (angle == 3) {
                for(int i = 0;i < need_move;i++) {
                    now_local[0]++;
                    cout << numbers[now_local[0]][now_local[1]];
                }
            }
            temp_total_move++;
            total_move += need_move;
            angle++;
            if (angle > 3) {
                angle = 0;
            }
        } else if (temp_total_move == 2) {
            need_move++;
            temp_total_move = 0;
        }
    }
    
    cout << endl;

    return 0;
}