#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vi apples;
    ll total = 0;
    while (n--) {
        ll p; cin >> p;
        total += p;
        apples.push_back(p);
    }
    n = apples.size();

    ll res = total + 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        ll group_total = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                group_total += apples[i];
            }
        }
        res = min(res, abs(total - (2 * group_total)));
    }
     
    cout << res << endl;

    return 0;
}
