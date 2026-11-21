#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)

array <string, 8> board;
array <bool, 8> cols {};
array <bool, 15> up_diags {};
array <bool, 15> down_diags {};
int ans = 0;

void solve(int r) {
    if (r == 8) {
        ans++;
        return;
    }
    rep(c, 0, 8) {
        int ud = r + c;
        int dd = r - c + 7;
        if (board[r][c] != '*' &&
            !cols[c] &&
            !up_diags[ud] &&
            !down_diags[dd]) {
            cols[c] = true;
            up_diags[ud] = true;
            down_diags[dd] = true;

            solve(r + 1);

            cols[c] = false;
            up_diags[ud] = false;
            down_diags[dd] = false;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    for (auto& row : board) cin >> row;

    solve(0);

    cout << ans << '\n';
}
