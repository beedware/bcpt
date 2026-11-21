#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

const int N = 7;

int grid[N + 2][N + 2];
string path;
int total;

void search(int r, int c, int s) {
    if (grid[r][c]) return;

    if (r == N && c == 1) {
        if (s == N * N) total++;
        return;
    }

    bool down = grid[r + 1][c];
    bool up = grid[r - 1][c];
    bool left = grid[r][c - 1];
    bool right = grid[r][c + 1];
    if (down && up && !left && !right) return;
    if (!down && !up && left && right) return;

    char d = path[s - 1];
    grid[r][c] = 1;
    if (d == '?' || d == 'D') search(r + 1, c, s + 1);
    if (d == '?' || d == 'U') search(r - 1, c, s + 1);
    if (d == '?' || d == 'L') search(r, c - 1, s + 1);
    if (d == '?' || d == 'R') search(r, c + 1, s + 1);
    grid[r][c] = 0;
}

int main() {
    for (int i = 0; i <= N + 1; i++) {
        grid[0][i] = grid[N + 1][i] = 1;
        grid[i][0] = grid[i][N + 1] = 1;
    }

    cin >> path;
    search(1, 1, 1);
    cout << total << "\n";
}