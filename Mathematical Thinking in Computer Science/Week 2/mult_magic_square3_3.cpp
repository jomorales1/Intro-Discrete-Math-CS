#include <bits/stdc++.h>

using namespace std;

int main() {
    int a[3][3] = {{1, 2, 0},
                   {0, 1, 2},
                   {2, 0, 1}};
    int b[3][3] = {{0, 2, 1},
                   {2, 1, 0},
                   {1, 0, 2}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a[i][j] = pow(2, a[i][j]);
            b[i][j] = pow(3, b[i][j]);
            cout << (a[i][j] * b[i][j]) << "\t"; 
        }
        cout << "\n";
    }
    return  0;
}