#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int from, int to, int helper) {
    if (n == 0) return;
    hanoi(n - 1, from, helper, to);
    cout << from << ' ' << to << '\n';
    hanoi(n - 1, helper, to, from);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;

    cout << (1 << n) - 1 << '\n';
    hanoi(n, 1, 3, 2);
}
