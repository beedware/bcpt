#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string s; cin >> s;

    vector<string> res;
    sort(s.begin(), s.end());
    do
        res.push_back(s);
    while (next_permutation(s.begin(), s.end()));

    cout << res.size() << '\n';

    for (const auto& x : res)
        cout << x << '\n';
}
