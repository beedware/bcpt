#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, x; cin >> n >> x;
    vi as(n);
    for (auto& a : as) cin >> a;

    map<int, int> mp;

    rep (i, 0, n) {
        if (mp.contains(x - as[i])) {
            cout << mp[x - as[i]] + 1 << " " << i + 1 << endl;
            return 0;
        }
        mp[as[i]] = i;
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
