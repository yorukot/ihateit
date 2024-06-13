// this still not slove and i can't find a new way for this
#include <bits/stdc++.h>

using namespace std;

int main() {
    int miny = 0, maxx = 0, maxy = 0;
    int totalMirror = 0;
    cin >> totalMirror;
    vector<vector<int>> userInput;

    for (int i = 0; i < totalMirror; i++) {
        vector<int> temp(3, 0);
        cin >> temp[0] >> temp[1] >> temp[2];
        userInput.push_back(temp);
        maxx = max(maxx, temp[0]);
        miny = min(miny, temp[1]);
        maxy = max(maxy, temp[1]);
    }


    int addy = 0;
    if (miny < 0) {
        addy = -miny;
    }
    maxy += addy;
    
    vector<vector<int>> matrix(maxx + 1, vector<int>(maxy + 1, 2));

    for (int i = 0; i < totalMirror; i++) {
        int tempy = userInput[i][1] + addy;
        matrix[userInput[i][0]][tempy] = userInput[i][2];
    }
    bool stop = false;
    int answer = 0;
    // 1 = up, 2 = down, 3 = left, 4 = right
    int face = 4;
    int laserX = 0, laserY = addy;
    
    while (!stop) {
         if (face == 1) {
            bool subStop = false;
            while (!subStop) {
                laserY++;
                if (laserY > maxy) {
                    subStop = true;
                    stop = true;
                }else if (matrix[laserX][laserY] != 2) {
                    subStop = true;
                    if (matrix[laserX][laserY] == 0) {
                        face = 4;
                    } else if (matrix[laserX][laserY] == 1) {
                        face = 3;
                    }
                    answer++;
                }
            }
        } else if (face == 2) {
            bool subStop = false;
            while (!subStop) {
                laserY--;
                if (laserY < 0) {
                    subStop = true;
                    stop = true;
                }else if (matrix[laserX][laserY] != 2) {
                    subStop = true;
                    if (matrix[laserX][laserY] == 0) {
                        face = 3;
                    } else if (matrix[laserX][laserY] == 1) {
                        face = 4;
                    }
                    answer++;
                }
            }
        } else if (face == 3) {
            bool subStop = false;
            while (!subStop) {
                laserX--;
                if (laserX < 0) {
                    subStop = true;
                    stop = true;
                }else if (matrix[laserX][laserY] != 2) {
                    subStop = true;
                    if (matrix[laserX][laserY] == 0) {
                        face = 2;
                    } else if (matrix[laserX][laserY] == 1) {
                        face = 1;
                    }
                    answer++;
                }
            }
        } else if (face == 4) {
            bool subStop = false;
            while (!subStop) {
                laserX++;
                if (laserX > maxx) {
                    subStop = true;
                    stop = true;
                } else if (matrix[laserX][laserY] != 2) {
                    subStop = true;
                    if (matrix[laserX][laserY] == 0) {
                        face = 1;
                    } else if (matrix[laserX][laserY] == 1) {
                        face = 2;
                    }
                    answer++;
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}