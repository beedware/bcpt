
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    cin >> s;

    map<char, int> counter;

    for (char c : s) {
        counter[c]++;
    }

    int oddCount = 0;

    for (const auto& [ch, co] : counter) {
        if (co % 2 != 0) {
            oddCount++;
        }
    }

    if (oddCount > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    string left = "";

    for (const auto& [ch, co] : counter) {
        for (int i = 0; i < co / 2; ++i) {
            left += ch;
        }
    }

    string middle = "";

    for (const auto& [ch, co] : counter) {
        if (co % 2 == 1) {
            middle += ch;
            break;
        }
    }

    string right = "";

    for (int i = (int)left.size() - 1; i >= 0; --i) {
        right += left[i];
    }

    cout << left << middle << right << '\n';

    return 0;
}