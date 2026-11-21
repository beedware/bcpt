#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int N; cin >> N;
    vi ns(N);
    for (auto& n : ns)
        cin >> n;

    set<int> distinct(all(ns));
    
    cout << sz(distinct) << endl;   

    return 0;
}