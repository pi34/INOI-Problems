#include <iostream>
#include <string>

using namespace std;

int main ()
{
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string num;
        cin >> num;

        int curr0 = 0;
        int curr1 = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                curr0++;
            } else {
                curr1++;
            }
        }

        int big = (curr0>curr1? '0' : '1');

        int sum = 0;
        for (int i = 0; i < n; i++) sum += (num[i]==big?1:-1);

        string fin(n, '0');
        fin[0] = '1';

        int curr = 0;

        for (int i = 0; i < n; ++i) {
            if (sum <= k) break;
            curr = curr + (num[i]==big?1:-1);
            if (curr == k+1) {
                fin[i] = '1';
                sum = sum - (curr - (num[i]==big?1:-1));
                curr = (num[i]==big?1:-1);
            }
        }

        cout << fin << "\n";

    }
}
