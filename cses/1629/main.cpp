#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef pair<int, int> pii;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<pii> pq(n);
    for (auto& [b, a] : pq) cin >> a >> b;

    sort(all(pq));
    int last = 0, res = 0;
    for (const auto& [e, b] : pq) {
        if (last <= b) {
            last = e;
            res++;
        }
    }

    cout << res << endl;

    return 0;
}
