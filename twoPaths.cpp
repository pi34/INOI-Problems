#include <iostream>
#define INF 1000000000;
using namespace std;

int main ()
{
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
    
        int arr[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }

        int pref[n][m];

        pref[0][0] = arr[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j) {
                    pref[i][j] = pref[i][j-1] + arr[i][j];
                } else {
                    pref[i][j] = arr[i][j];
                }
            }
        }

        int dp1[n][m][k+1];
        int dp2[n][m][k+1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int l = 0; l <= k; l++) {
                    dp1[i][j][l] = pref[i][j];
                    dp2[i][j][l] = pref[i][j] - arr[i][j];
                    if (!i) continue;
                    if (!j || !l) {
                        dp1[i][j][l] += dp1[i-1][j][l];
                        dp2[i][j][l] += dp2[i-1][j][l];
                    } else {
                        dp1[i][j][l] += max(dp1[i-1][j][l], dp1[i-1][j-1][l-1]);
                        dp2[i][j][l] += min(dp2[i-1][j][l], dp2[i-1][j-1][l-1]);
                    }
                }
            }
        }

        int fin = -INF;
        for (int i = 0; i < m; i++) {
            for (int j = i+k+1; j < m; j++) {
                fin = max(fin, dp1[n-1][j][k] - dp2[n-1][i][k]);
            }
        }

        cout << fin << "\n";

    }
}
