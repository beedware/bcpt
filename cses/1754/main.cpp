#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
        ll tmp = a;
        a = min(a, b);
        b = max(tmp, b);
        if ((a + b) % 3 == 0 && b <= 2 * a) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}