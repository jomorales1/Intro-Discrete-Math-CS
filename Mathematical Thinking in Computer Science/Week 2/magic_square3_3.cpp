#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

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
}

int main() {
    magic_square();
    return 0;
}