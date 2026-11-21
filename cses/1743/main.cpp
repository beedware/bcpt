#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s;
    int n = s.size();

    map<char, int> mp;
    for (char c : s)
        mp[c]++;

    string res;

    rep(i, 0, n) {
        int max1 = 0, max2 = 0;
        char maxChar = 'A';

        rep(c, 'A', 'Z' + 1) {
            if (mp[c] > max1) {
                max2 = max1;
                max1 = mp[c];
                maxChar = c;
            } else if (mp[c] > max2) {
                max2 = mp[c];
            }
        }

        bool found = false;
        int m = n - i - 1;

        rep(c, 'A', 'Z' + 1) {
            if (mp[c] == 0) continue;
            if (!res.empty() && res.back() == c)
                continue;

            int maxOther = (c == maxChar ? max2 : max1);

            if (2 * (mp[c] - 1) > m)
                continue;

            if (2 * maxOther > m + 1)
                continue;

            res += c;
            mp[c]--;
            found = true;
            break;
        }

        if (!found) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << res << '\n';
    return 0;
}
