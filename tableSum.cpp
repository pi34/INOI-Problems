#include <iostream>
#include <set>

using namespace std;


int main () {

    int n;
    cin >> n;

    int arr[n];
    multiset<int> multset;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i] = arr[i] + i + 1;
        multset.insert(arr[i]);
    };

   cout << *multset.rbegin() << " ";

   for (int i = 1; i < n; i++) {
       multset.erase(multset.find(arr[n-i]));
       arr[n-i] = arr[n-i] - n;
       multset.insert(arr[n-i]);
       cout << *multset.rbegin()+i << " ";
   }

   cout << "\n";

}
