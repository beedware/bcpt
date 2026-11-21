#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<vi> grid(n, vi(n));

    rep(r, 0, n) {
        rep(c, 0, n) {
            set<int> seen;
            rep(i, 0, r)
                seen.insert(grid[i][c]);
            rep(i, 0, c)
                seen.insert(grid[r][i]);
            int i = 0;
            while (seen.contains(i))
                i++;
            cout << i << " ";
            grid[r][c] = i;
        }
        cout << "\n";
    }
}
