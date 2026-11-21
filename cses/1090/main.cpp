#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, x; cin >> n >> x;
    vi ws(n);
    for (auto& w : ws) cin >> w;

    sort(all(ws));
    int l = 0, r = n - 1;
    int res = 0;
    while (l <= r) {
        if (l < r && ws[l] + ws[r] <= x) {
            ++l;
        }
        --r;
        ++res;
    }

    cout << res << '\n';
}
