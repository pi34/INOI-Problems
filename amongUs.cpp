
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N = 5 * 100000;
vector<vector<pair<int, int>>> adjList;
vector<bool> visited;

int typ1 = 0;
int typ2 = 0;

vector<int> color;

bool contradict = false;

void dfs (int node, int type) {

    color[node] = type;

    if (type == 1) {
        typ1++;
    } else {
        typ2++;
    }

    visited[node] = true;

    for (auto i: adjList[node]) {
        if (!visited[i.first]) {
            if (i.second == 1) {
                if (type == 1) {
                    dfs(i.first, 2);
                } else {
                    dfs(i.first, 1);
                }
            } else {
                dfs(i.first, type);
            }
        } else {
            if (i.second == 1 && color[node] == color[i.first]) {
                contradict = true;
            } else if (i.second == 2 && color[node] != color[i.first]) {
                contradict = true;
            }
        }
    };
}

int main () {
    int t;
    cin >> t;

    while (t--) {

        int n, q;
        cin >> n >> q;
        
        adjList.clear();
        adjList.resize(n);

        visited.clear();
        visited.resize(n, false);

        color.clear();
        color.resize(n);

        for (int i = 0; i < q; ++i) {

            int typ, x, y;
            cin >> typ >> x >> y;
            x--;
            y--;
            adjList[x].push_back(make_pair(y, typ));
            adjList[y].push_back(make_pair(x, typ));

        }

        int totParasites = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                contradict = false;
                typ1 = 0;
                typ2 = 0;
                dfs(i, 1);
                totParasites = totParasites + max(typ1, typ2);
                if (contradict) {
                    break;
                };
            }
        }

        if (contradict) {
            cout << "-1" << "\n";
        } else {
            cout << totParasites << "\n";
        }

    }

}
