#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;
    ll k; cin >> k;
    vector<ll> as(n);
    for (auto& a : as)
        cin >> a;
    vector<ll> bs(m);
    for (auto& b : bs)
        cin >> b;

    sort(all(as)); sort(all(bs));

    int res = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (as[i] - k <= bs[j] && bs[j] <= as[i] + k) {
            res++;
            i++; j++;
            continue;
        }
        if (as[i] - k > bs[j]) {
            j++;
            continue;
        }
        if(bs[j] > as[i] + k) {
            i++;
            continue;
        }
    }

    cout << res << endl;

    return 0;
}