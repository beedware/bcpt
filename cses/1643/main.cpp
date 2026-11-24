#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<ll> xs(n);
    for (auto& x : xs) cin >> x;

    ll t = xs[0];
    ll mt = t;
    rep(i, 1, n) {
        if (t + xs[i] < xs[i]) {
            t = xs[i];
        } else {
            t += xs[i];
        }
        mt = max(mt, t);
    }

    cout << mt << endl;

    return 0;
}
