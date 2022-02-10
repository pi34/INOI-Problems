#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	// your code goes here
	ll n;
	cin >> n;
	
	ll a[n];
	ll b[n];
	ll maxVal = -10000000000;
	
	for (ll i = 0; i < n; i++) {
	    cin >> a[i];
	    maxVal = max(maxVal, a[i]);
	    
	}
	for (ll i = 0; i < n; i++) {
	    cin >> b[i];
	    if (i != 0) b[i] = b[i] + b[i-1];
	};
	
	ll diffs[n];
	
	for (ll i = 0; i < n; i++) {
	    diffs[i] = a[i]-b[i];
	    if (i != 0) diffs[i] = max(diffs[i-1], diffs[i]);
	};
	
	for (ll i = 1; i < n; i++) {
	    maxVal = max(maxVal, a[i]+diffs[i-1]+b[i-1]);
	}
	
	ll sums[n];
	for (ll i = 0; i < n; i++) {
	    sums[i] = a[i];
	    if (i != 0) sums[i] = sums[i] + b[i-1];
	    if (i != 0) sums[i] = max(sums[i-1], sums[i]);
	};
	
	for (ll i = 1; i < n; i++) {
	    maxVal = max(maxVal, sums[i-1]+a[i]+b[n-1]-b[i]);
	}

    cout << maxVal << "\n";
	
}
