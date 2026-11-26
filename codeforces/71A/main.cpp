#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;

    while (n--) {
        string word; cin >> word;
        int length = sz(word);
        if (length > 10) {
            cout << word.front() << length - 2 << word.back() << '\n';
        } else {
            cout << word << '\n';
        }
    }

    return 0;
}
