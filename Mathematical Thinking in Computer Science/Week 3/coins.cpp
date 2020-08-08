#include <bits/stdc++.h>

using namespace std;

vector<int> change(int amount) {
    if (amount < 8) {
        vector<int> v = {-1};
        return v;
    }
    if (amount == 8) {
        vector<int> v = {3, 5};
        return v;
    }
    if (amount == 9) {
        vector<int> v = {3, 3, 3};
        return v;
    }
    if (amount == 10) {
        vector<int> v = {5, 5};
        return v;
    }

    vector<int> coins = change(amount - 3);
    coins.push_back(3);
    return coins;
}

vector<int> change2(int amount) {
    
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> coins = change(n);
    for (auto coin : coins) {
        cout << coin << " ";
    }
    cout << '\n';
    return 0;
}