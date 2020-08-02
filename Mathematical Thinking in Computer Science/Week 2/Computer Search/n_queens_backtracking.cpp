#include <bits/stdc++.h>

using namespace std;

bool contains(const vector<int>& v, int el) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        if (v[i] == el)
            return true;
    }
    return false;
}

bool can_be_extended_to_solution(const vector<int>& perm) {
    int i = perm.size() - 1;
    for (int j = 0; j < i; j++) {
        if ((i - j) == abs(perm[i] - perm[j]))
            return false;
    }
    return true;
}

void generate_permutations(vector<int>& perm, int n) {
    if (perm.size() == n) {
        cout << "[";
        for (int i = 0; i < n - 1; i++) {
            cout << perm[i] << ", ";
        }
        cout << perm.back() << "]\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!contains(perm, i)) {
            perm.push_back(i);
            generate_permutations(perm, n);
            perm.pop_back();
        }
    }
}

void extend(vector<int>& perm, int n) {
    if (perm.size() == n) {
        cout << "[";
        for (int i = 0; i < n - 1; i++) {
            cout << perm[i] << ", ";
        }
        cout << perm.back() << "]\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!contains(perm, i)) {
            perm.push_back(i);
            if (can_be_extended_to_solution(perm))
                extend(perm, n);
            perm.pop_back();
        }
    }
}

int main() {
    // TODO: implement solution with backtracking
    vector<int> perm;
    int n;
    cin >> n;
    extend(perm, n);
    return 0;
}