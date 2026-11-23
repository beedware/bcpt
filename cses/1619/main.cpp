#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef pair<int, int> pii;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;

    vector<pii> es;

    while (n--) {
        int a, b; cin >> a >> b;
        es.emplace_back(a,  1);
        es.emplace_back(b, -1);
    }

    sort(all(es));

    int high = 0, total = 0;
    for (auto& [_, v] : es) {
        total += v;
        high = max(high, total);
    }

    cout << high << endl;

    return 0;
}
