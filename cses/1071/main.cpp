
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        ll y, x;
        cin >> y >> x;

        ll n = max(x, y);
        ll ans = n * n - n + 1;

        if (n % 2 == 0) {
            ans += y - x;
        } else {
            ans += x - y;
        }

        cout << ans << '\n';
    }

    return 0;
}