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

const int N = 2e5 + 5, M = N, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

struct DSU {
    int par[N], sz[N], cnt;

    void init(int n) {
        iota(par, par + n, 0);
        fill(sz, sz + n, 1);
        cnt = n;
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return false;
        if(sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        cnt--;
        return true;
    }
} dsu;

int main() {  Alien35();



return 0;
}
