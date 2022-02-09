#include<bits/stdc++.h>
#include <iostream>

using namespace std;

const long long N = 702;
long long dp[N][N];
long long brackets[N];
long long values[N];
long long k;

long long brack (long long left, long long right) {

    if (left >= right) return 0;

    if (dp[left][right] != -1) {
        return dp[left][right];
    }

    long long curr = 0;
    curr = max(curr, brack(left+1, right));

    if (brackets[left] <= k) {
        for (long long i = left+1; i <= right; ++i) {
            if (brackets[i] == brackets[left]+k) {
                curr = max(curr, brack(left+1, i-1) + values[i] + values[left] + brack(i+1, right));
            }
        }
    }

    dp[left][right] = curr;
    return dp[left][right];

}

int main () {
    long long n;
    cin >> n;

    cin >> k;

    for (long long i = 1; i <= n; ++i) {
        cin >> values[i];
    }

    for (long long i = 1; i <= n; ++i) {
        cin >> brackets[i];
    }

    memset(dp,-1,sizeof(dp));
    cout << brack(1, n) << "\n";

}
