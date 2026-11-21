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

    string left, middle;

    for (const auto& [ch, co] : counter) {
        left.append(co / 2, ch);
        if (co % 2 != 0) middle += ch;
    }

    string right(left.rbegin(), left.rend());
    cout << left << middle << right << '\n';
}
