#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    
    const ll MOD = 1e9 + 7;

    ll ans = 1;
    for (int p = 0; p < n; p++) {
       ans = (ans * 2) % MOD;
    }
    cout << ans << endl;

    return 0;
}
