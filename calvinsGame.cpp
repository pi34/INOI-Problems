#include <iostream>

using namespace std;

typedef long long ll;

int main () 
{
    ll n, k;
    cin >> n >> k;
    k--;

    ll arr[n];
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll dpForward[n];
    dpForward[k] = 0;
    if (k+1 < n)dpForward[k+1] = arr[k+1];
    for (ll i = k+2; i < n; ++i) {
        dpForward[i] = arr[i] + max(dpForward[i-1], dpForward[i-2]);
    };

    ll dpBackward[n];
    dpBackward[0] = arr[0];
    if (n > 1) dpBackward[1] = arr[0] + arr[1];
    for (ll i = 2; i < n; ++i) {
        dpBackward[i] = arr[i] + max(dpBackward[i-1], dpBackward[i-2]);
    };

    ll maxima = -1000000000;
    for (ll i = k; i < n; ++i) {
        maxima = max(maxima, dpForward[i] + dpBackward[i] - arr[i]);
    };

    cout << maxima << endl;

}
