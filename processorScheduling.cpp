#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll INF = 1e15;

int main ()
{
    ll t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;

        ll arrN[n+1];
        vector<pair<ll, ll>> arrM (m+1);

        for (ll i = 1; i <= n; ++i) {
            cin >> arrN[i];
        }

        for (ll i = 1; i <= m; ++i) {
            cin >> arrM[i].second;
        }

        for (ll i = 1; i <= m; ++i) {
            cin >> arrM[i].first;
        }

        sort(arrM.begin(), arrM.end());

        ll dp[n+1][m+1];

        for (ll i = 0; i <= n; i++) {
            for (ll j = 0; j <= m; j++) {
                dp[i][j] = INF;
            }
        }

        dp[0][0] = 0;

        for (ll i = 0; i <= n; i++) {
            for (ll j = 0; j <= m; j++) {
                if (j) {
                    if (dp[i][j-1] > arrM[j].first) dp[i][j] = INF;
                    else if (dp[i][j-1] + arrM[j].second < arrM[j].first) dp[i][j] = arrM[j].first;
                    else dp[i][j] = dp[i][j-1] + arrM[j].second;
                }
                if (i) {
                    dp[i][j] =  min (dp[i][j], dp[i-1][j]+arrN[i]);
                }
            }
        }

        dp[n][m] == INF ? cout << -1 : cout << dp[n][m];
        cout << "\n";

    }
}
