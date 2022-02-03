#include <iostream>
#include <vector>
#include <deque>
#include <map>

typedef long long ll;

using namespace std;

int main () {
    ll r, c, n;
    cin >> r >> c >> n;

    vector<pair<ll, ll>> edges(n);
    map<pair<ll, ll>, bool> mp;
    map<pair<ll, ll>, bool> visited;

    for (ll i = 0; i < n; ++i) {

        ll currx, curry;
        cin >> currx >> curry;
        currx--;
        curry--;
        edges[i].first = currx;
        edges[i].second = curry;
        mp[{currx, curry}] = true;
        visited[{currx, curry}] = false;
        

    }

    ll grTot = 0;

    for (auto j: edges) {

        if (mp[j] && !visited[j]) {

            ll tot = 0;
            deque<pair<ll, ll>> que;
            que.push_back(j);

            while (!(que).empty()) {

                ll fenceing = 0;

                pair<ll, ll> curr = que.front();
                ll nodeX = que.front().first;
                ll nodeY = que.front().second;

                que.pop_front();

                if (!visited[curr]) {

                    visited[curr] = true;

                    if (nodeX+1 < r && nodeY < c) {
                        if (mp[{nodeX+1, nodeY}]) {
                            fenceing++;
                            if (!visited[{nodeX+1, nodeY}]) {
                                que.push_back({nodeX+1, nodeY});
                            }
                        }
                    }
                    
                    if (nodeX-1 >= 0 && nodeY < c) {
                        if (mp[{nodeX-1, nodeY}]) {
                            fenceing++;
                            if (!visited[{nodeX-1, nodeY}]) {
                                que.push_back({nodeX-1, nodeY});
                            }
                        }
                    }

                    if (nodeX < r && nodeY+1 < c) {
                        if (mp[{nodeX, nodeY+1}]) {
                            fenceing++;
                            if (!visited[{nodeX, nodeY+1}]) {
                                que.push_back({nodeX, nodeY+1});
                            }
                        }
                    }
                    
                    if (nodeX < r && nodeY-1 >= 0) {
                        if (mp[{nodeX, nodeY-1}]) {
                            fenceing++;
                            if (!visited[{nodeX, nodeY-1}]) {
                                que.push_back({nodeX, nodeY-1});
                            }
                        }
                    }
                    
                    tot = tot + (4-fenceing);

                }

            }

            grTot = max(tot, grTot);
        }

    }

    cout << grTot << endl;

}
