#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;
    multiset<int> ts;
    while (n--) {
        int h; cin >> h;
        ts.insert(h);
    }
    while (m--) {
        int t; cin >> t;
        auto ticket = ts.upper_bound(t);
        if (ts.begin() == ticket) {
            cout << -1 << '\n';
            continue;
        }
        --ticket;
        cout << *ticket << '\n';
        ts.erase(ticket);
    }

    return 0;
}
