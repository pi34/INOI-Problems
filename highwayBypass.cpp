#include <iostream>
#include <vector>

using namespace std;

int grid[305][305];
int dp[305][305][305][2] = { };

int main () {

    int r, c, d;
    cin >> r >> c >> d;

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i <= d; i++) {
        dp[r][c][i][0] = dp[r][c][i][1] = 1;
    }

    for (int i = r; i > 0; i--) {
        for (int j = c; j > 0; j--) {
            if (i == r && j == c) continue;
            if (grid[i][j] == 1) {
                dp[i][j][d][0] = dp[i+1][j][1][1];
                dp[i][j][d][1] = dp[i][j+1][1][0];
                for (int k = 0; k < d; k++) {
                    dp[i][j][k][0] = (dp[i+1][j][1][1]+dp[i][j+1][k+1][0]) % 20011;
                    dp[i][j][k][1] = (dp[i+1][j][k+1][1]+dp[i][j+1][1][0]) % 20011;
                }
            }
        }
    }

    cout << dp[1][1][0][0] << "\n";

}

