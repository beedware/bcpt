#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int add(int lhs, int rhs) { return lhs + rhs; }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;

    for (ll k = 1; k <= n; ++k) {
        ll total = k * k * (k * k - 1) / 2;
        ll attacking = 4 * (k - 1) * (k - 2);
        cout << total - attacking << endl;
    }

    return 0;
}
