#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    set<int> distinct;
    while (n--) {
        int value;
        cin >> value;
        distinct.insert(value);
    }
    cout << distinct.size() << '\n';
}
