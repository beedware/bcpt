#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        int played = a + b;
        if (played > n || (a == 0) != (b == 0)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << i + 1 << " ";
        cout << "\n";
        for (int i = 0; i < n; i++) {
            if (i < played)
                cout << (i + a) % played + 1 << ' ';
            else
                cout << i + 1 << " ";
        }
        cout << "\n";
    }
}
