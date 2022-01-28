#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int modExp (int pow, int m) 
{
    int res = 1;
    for (int i = 1; i <= pow; i++) {
        res = res * 2;
        res = res % m;
    }
    return res;
}

int main ()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> factors;

    for (ll i = 1; i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
        }
    }

    vector<ll> dp;

    for (ll i = 0; i < factors.size(); i++) {
        ll curr = modExp(factors[i], m);
        for (ll j = 0; j < i; j++) {
            if (factors[i] % factors[j] == 0) {
                curr = curr - dp[j];
            }
        }
        while (curr < 0) {
            curr = curr + m;
        }
        dp.push_back(curr);
    }

    cout << dp[dp.size() - 1] << endl;

}
