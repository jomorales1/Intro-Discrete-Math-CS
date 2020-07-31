#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

// Brute force search
bool check_square(const vector<int>& permutation) {
    int n = permutation.size();
    int sum = 0;
    // First diagonal
    for (int i = 0; i < n; i += 4) {
        sum += permutation[i];
    }
    //cout << sum << " ";
    // Second diagonal
    int sum2 = 0;
    for (int i = 2; i < n - 1; i += 2) {
        sum2 += permutation[i];
    }
    if (sum2 != sum)
        return false;
    //cout << sum2 << " ";
    // Rows
    sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum2 += permutation[i];
        if ((i + 1) % 3 == 0){
            if (sum2 != sum){
                return false;
            }
            sum2 = 0;
        }
    }
    //cout << sum2 << " ";
    // Columns
    sum2 = 0;
    for (int i = 0; i < n; i += 3) {
        sum2 += permutation[i];
        if (i >= 6 && i != 8) {
            if (sum2 != sum){
                return false;
            }
            sum2 = 0;
            if (i == 6){
                i = -2;
            } else {
                i = -1;
            }
        }
    }
    //cout << sum2 << " ";
    //cout << "\n";
    return true;
}

void magic_square() {
    vector<int> permutation;
    for (int i = 0; i < 9; i++) {
        permutation.push_back(i + 1);
    }
    do {
        if(check_square(permutation)) {
            for (int i = 0; i < 9; i++) {
                cout << permutation[i] << " ";
                if ((i + 1) % 3 == 0)
                    cout << "\n";
            }
            cout << "------------------------------" << "\n";
        }
    } while(next_permutation(permutation.begin(), permutation.end()));
}

void method_two() {
    // TODO: implement
    int goal = 15;
    int matrix[3][3];

    // 5 should be in the middle
    matrix[1][1] = 5;

    vector<pair<int, int>> pos_one = {{0, 1}, {1, 0}, {1, 2}, {2, 1}};

    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                matrix[k][l] = -1;
            }
        }
        matrix[1][1] = 5;
        matrix[pos_one[i].first][pos_one[i].second] = 1;
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                if (pos_one[i].first == 0 || pos_one[i].first == 2) {
                    matrix[pos_one[i].first][pos_one[i].second - 1] = 6;
                    matrix[pos_one[i].first][pos_one[i].second + 1] = 8;
                } else {
                    matrix[pos_one[i].first - 1][pos_one[i].second] = 6;
                    matrix[pos_one[i].first + 1][pos_one[i].second] = 8;
                }
            } else {
                if (pos_one[i].first == 0 || pos_one[i].first == 2) {
                    matrix[pos_one[i].first][pos_one[i].second - 1] = 8;
                    matrix[pos_one[i].first][pos_one[i].second + 1] = 6;
                } else {
                    matrix[pos_one[i].first - 1][pos_one[i].second] = 8;
                    matrix[pos_one[i].first + 1][pos_one[i].second] = 6;
                }
            }
            vector<pair<int, int>> pendent;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (matrix[k][l] == -1) {
                        if (k == 0 && l == 0) {
                            matrix[k][l] = goal - (5 + matrix[2][2]);
                        } else if (k == 0 && l == 2) {
                            matrix[k][l] = goal - (5 + matrix[2][0]);
                        } else if (k == 2 && l == 0) {
                            matrix[k][l] = goal - (5 + matrix[0][2]);
                        } else if (k == 2 && l == 2) {
                            matrix[k][l] = goal - (5 + matrix[0][0]);
                        } else {
                            if (k == 0 && matrix[2][1] != -1) {
                                matrix[k][l] = goal - (matrix[2][1] + 5);
                            } else if (k == 1 && l == 0 && matrix[1][2] != -1) {
                                matrix[k][l] = goal - (matrix[1][2] + 5);
                            } else if (k == 1 && l == 2 && matrix[1][0] != -1) {
                                matrix[k][l] = goal - (matrix[1][0] + 5);
                            } else if(k == 2 && matrix[0][1] != -1) {
                                matrix[k][l] = goal - (matrix[0][1] + 5);
                            } else {
                                pendent.push_back(make_pair(k, l));
                            }
                        }
                    }
                }
            }
            for (auto p: pendent) {
                if (p.first == 0 || p.first == 2) {
                    matrix[p.first][p.second] = goal - (matrix[p.first][p.second - 1] + matrix[p.first][p.second + 1]);
                } else {
                    matrix[p.first][p.second] = goal - (matrix[p.first - 1][p.second] + matrix[p.first + 1][p.second]);
                }
            }

            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    cout << matrix[k][l] << " ";
                }
                cout << "\n";
            }
            cout << "----------------------------------\n";
        }
    }
}

int main() {
    magic_square();
    method_two();
    return 0;
}