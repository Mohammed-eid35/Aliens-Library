//:::: Alien :::://
// Muhammad Eid //
#include <bits/stdc++.h>
using namespace std;

void Alien35() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("test.in", "rt", stdin);
    freopen("test.out", "wt", stdout);
#endif
}

const int OO = 0x3f3f3f3f;

void Dijkstra_n2(int src, vector<vector<int>> adjMat) {
    int n = adjMat.size();

    vector<int> dis(n, OO);
    dis[src] = 0;

    vector<bool> vis(n, false);

    while (true) {
        int node = -1, nodeDis = OO;

        for (int i = 0; i < n; ++i) {
            if (!vis[i] && nodeDis > dis[i]) {
                nodeDis = dis[i];
                node = i;
            }
        }

        if (node == -1)
            break;
        
        vis[node] = true;

        for (int i = 0; i < n; ++i) {
            if (dis[i] > dis[node] + adjMat[node][i])
                dis[i] = dis[node] + adjMat[node][i];
        }
    }
}

int main() {  Alien35();
    


return 0;
}
