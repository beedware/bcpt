#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string s; cin >> s;
    int n = s.size();

    int cur = 1;
    int res = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i - 1] != s[i]) cur = 0;
        cur++;
        res = max(res, cur);
    }

    cout << res << '\n';
}
