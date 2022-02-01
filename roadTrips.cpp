#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;
vector<int> museums;

int ans = 0;

void dfs (int node) {
    
    if (visited[node]) {
        return;
    };

    ans = ans + museums[node];
    visited[node] = true;

    for (auto i: adjList[node]) {
        dfs(i);
    };
}

int main ()
{
    int t;
    cin >> t;

    while (t--) {

        int n, m, k;
        cin >> n >> m >> k;

        adjList.clear();
        visited.clear();
        museums.clear();

        adjList.resize(n);
        visited.resize(n, false);
        museums.resize(n);

        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }

        for (int i = 0; i < n; ++i) {
            cin >> museums[i];
        }

        deque<int> all;

        for (int i = 0; i < n; ++i) {
            if (not visited[i]) {
                ans = 0;
                dfs(i);
                all.push_back(ans);
            }
        }

        sort(all.begin(), all.end());

        int mus = 0;
        
        if (k > all.size()) {
            cout << -1 << "\n";
        } else {
            for (int i = 1; i <= k; ++i) {
                if (i % 2 == 0) {
                    mus = mus + all.front();
                    all.pop_front();
                } else {
                    mus = mus + all.back();
                    all.pop_back();
                }
            }
            
            cout << mus << "\n";
        }

    }
}
