#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n; cin >> n;

    ll sum = (n + 1) * n / 2;

    if (sum % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    sum /= 2;
    vi lhs, rhs;
    for (int i = n; i > 0; --i) {
        if (sum >= i) {
            lhs.push_back(i);
            sum -= i;
        } else {
            rhs.push_back(i);
        }
    }
    for (const auto* group : {&lhs, &rhs}) {
        cout << group->size() << '\n';
        for (int num : *group) cout << num << ' ';
        cout << '\n';
    }
}
