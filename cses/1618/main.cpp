#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;

    int ans = 0;
    while (n > 0) {
        n /= 5;
        ans += n;
    }

    cout << ans << '\n';
}
