#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<string> codes {""};

    while (n--) {
        int len = codes.size();
        vector<string> new_codes;
        for (int i = 0; i < len; i++) {
            new_codes.push_back('0' + codes[i]);
        }
        for (int i = len - 1; i >= 0; i--) {
            new_codes.push_back('1' + codes[i]);
        }
        codes.swap(new_codes);
    }

    for (const string& code : codes) {
        cout << code << '\n';
    }
}
