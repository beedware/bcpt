#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    rep(i, 0, n) {
        string line; cin >> line;
        rep(j, 0, m) {
            set<char> allow {'A', 'B', 'C', 'D'};
            allow.erase(line[j]);
            if (i > 0)
                allow.erase(grid[i - 1][j]);
            if (j > 0)
                allow.erase(grid[i][j - 1]);
            if (allow.empty()) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
            grid[i][j] = *allow.begin();
        }
    }

    for (const auto& row : grid) {
        for (char colour : row) cout << colour;
        cout << '\n';
    }
}
