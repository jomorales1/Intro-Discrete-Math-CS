#include <bits/stdc++.h>

using namespace std;

// 0: UL -> BR
// 1: UR -> BL
// 2: ND

int grid[5][5];

vector<pair<int, int>> coordinates(int x, int y) {
    vector<pair<int, int>> res;
    for (int i = x - 1; i <= (x + 1); i++) {
        for (int j = y - 1; j <= (y + 1); j++) {
            if ((i >= 0 && i <= 4) && (j >= 0 && j <= 4) && !(i == x && j == y)) {
                if (grid[i][j] == 0 || grid[i][j] == 1 || grid[i][j] == 2) {
                    res.push_back(make_pair(i, j));
                }
            }
        }
    }
    return res;
}

bool check_nd() {
    int nd = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (grid[i][j] == 2)
                nd++;
        }
    }
    return nd <= 9;
}

bool check(int x, int y) {
    if (grid[x][y] == 2)
        return check_nd();
    vector<pair<int, int>> neighboors = coordinates(x, y);
    for (auto p: neighboors) {
        if (grid[p.first][p.second] == 2) {
            continue;
        }
        if (p.first == x || p.second == y) {
            if (grid[p.first][p.second] != grid[x][y]) {
                return false;
            }
        } else {
            if (grid[x][y] == 0) {
                if ((p.first == x - 1 && p.second == y + 1) ||
                    (p.first == x + 1 && p.second == y - 1))
                    continue;
            } else {
                if ((p.first == x - 1 && p.second == y - 1) ||
                    (p.first == x + 1 && p.second == y + 1))
                    continue;
            }
            if (grid[p.first][p.second] == grid[x][y]) {
                return false;
            } 
        }
    }
    return true;
}

bool check_all() {
    int lines = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (grid[i][j] == 0 || grid[i][j] == 1)
                lines++;
        }
    }
    return lines == 16;
}

void backtrack(int x, int y) {
    if (check_all()) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }
    for (int k = 0; k < 3; k++) {
        int prev = grid[x][y];
        grid[x][y] = k;
        if (check(x, y)) {
            if (y < 4) {
                backtrack(x, y + 1);
            } else {
                backtrack(x + 1, 0);
            }
        }
        grid[x][y] = prev;
    }
}

int main() {
    // TODO: Implement the solution using the backtrack technique
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            grid[i][j] = -1;
        }
    }
    backtrack(0, 0);
    return 0;
}