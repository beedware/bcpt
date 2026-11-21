#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;    
    vector<vi> grid(n, vi(n, -1));
    vi dr = {-2, -2, -1, -1,  1, 1,  2, 2};
    vi dc = {-1,  1, -2,  2, -2, 2, -1, 1};
    queue<pii> q;

    grid[0][0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        rep(i, 0, 8) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                continue;
            if (grid[nr][nc] != -1)
                continue;
            grid[nr][nc] = grid[r][c] + 1;
            q.push({nr, nc});
        }
    }

    for (const auto& row : grid) {
        for (const auto& move : row) {
            cout << move << " ";
        }
        cout << endl;
    }

    return 0;
}
