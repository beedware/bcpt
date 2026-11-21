#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;

    constexpr ll MOD = 1'000'000'007;

    ll ans = 1;
    for (int p = 0; p < n; p++) {
        ans = (ans * 2) % MOD;
    }
    cout << ans << '\n';
}
