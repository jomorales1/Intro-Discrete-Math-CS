#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b > a)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    cout << "Is there any number in [100000, 100999] which is divisible by 9127?\n";
    int n = 100000;
    for (int i = 1; i < 1000; i++) {
        if ((n + i) % 9127 == 0) {
            cout << (n + i) << "\n";
        }
    }
    cout << "Is there any three digit number which produces remainder 1 when divided by 2, 3, 4, 5, 6, 7\n";
    cout << (20 * 42 / gcd(20, 42) + 1) << "\n";
    cout << (40 * 42 / gcd(20, 42) + 1) << "\n";

    cout << "Integer linear combinations\n";
    cout << " ax + by = c\n";
    int a, b, c;
    cout << "Enter a and b\n";
    cin >> a >> b;
    cout << "Enter c\n";
    cin >> c;
    if (c % gcd(a, n) == 0){
        cout << "The number can be generated\n";
    } else {
        cout << "The number can't be generated\n";
    }
    return 0;
}