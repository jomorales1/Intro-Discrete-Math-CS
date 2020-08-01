#include <bits/stdc++.h>

using namespace std;

bool is_solution(const vector<int>& permutation) {
    int n = permutation.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(i - j) == abs(permutation[i] - permutation[j]) && i != j)
                return false;
        }
    }
    return true;
}

int main() {
    // TODO: implement brute force solution
    int n = 4;
    vector<int> permutation;
    for (int i = 0; i < n; i++) {
        permutation.push_back(i);
    }
    do {
        if (is_solution(permutation)) {
            for (int i = 0; i < n; i++) {
                cout << permutation[i] << " ";
            }
            cout << "\n";
        }
    } while(next_permutation(permutation.begin(), permutation.end()));
    return 0;
}