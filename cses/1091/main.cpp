#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

	int n, m; cin >> n >> m;
	vi ts(n);
	for (auto& t : ts) cin >> t;
	vi cs(m);
	for (auto& c : cs) cin >> c;

	sort(all(ts));

	vi res(n);

    return 0;
}
