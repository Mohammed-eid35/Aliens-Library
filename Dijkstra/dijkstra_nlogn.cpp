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

void Dijkstra_nlogn(int src, vector<vector<pair<int, int>>> adjList) {
    int n = adjList.size();

    vector<int> dis(n, OO);
    dis[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<int>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [nodeDis, node] = pq.top();
        pq.pop();
        
        if (nodeDis != dis[node])
            continue;
        
        for (auto [child, weight] : adjList[node]) {
            if (dis[child] > dis[node] + weight) {
                dis[child] = dis[node] + weight;
                pq.push({dis[child] , child});
            }
        }
    }
}

int main() {  Alien35();
    


return 0;
}
