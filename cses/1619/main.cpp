#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vi as(n);
    vi ds(n);
    rep(i, 0, n) {
        int a, b; cin >> a >> b;
        as[i] = a; ds[i] = b;
    }

    sort(all(as)); sort(all(ds));
    int res = 0, total = 0;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (as[i] < ds[j]) {
            ++total; ++i;
        } else {
            --total; ++j;
        }
        res = max(res, total);
    }

    cout << res << endl;

    return 0;
}
