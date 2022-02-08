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

const int N = 1e3 + 5, M = N, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

struct BIT2D {
    int tree[N][N];

    void init() {
        memset(tree, 0, sizeof(tree));
    }

    void add(int x, int y, int val) {
        for (int i = x + 1; i <= N; i += (i & (-i))) {
            for (int j = y + 1; j <= N; j += (j & (-j))) {
                tree[i - 1][j - 1] += val;
            }
        }
    }

    int get(int x, int y) {
        int ret = 0;
        for (int i = x + 1; i; i -= (i & (-i))) {
            for (int j = y + 1; j; j -= (j & (-j))) {
                ret += tree[i - 1][j - 1];
            }
        }
        return ret;
    }

    int get(int sx, int sy, int ex, int ey) {
        return get(ex, ey) - get(ex, sy - 1) - get(sx - 1, ey) + get(sx - 1, sy - 1);
    }
} bit;


int main() {  Alien35();



return 0;
}