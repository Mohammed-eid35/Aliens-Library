//:::: Alien :::://
// Muhammad Eid //
#include <bits/stdc++.h>
using namespace std;

void Mo35() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("test.in", "rt", stdin);
    freopen("test.out", "wt", stdout);
#endif
}

const int N = 2e5 + 5, M = N, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

struct BIT {
    int tree[N];

    void init() {
        memset(tree, 0, sizeof(tree));
    }

    void add(int pos, int val) {
        for (++pos; pos <= N; pos += (pos & (-pos))) {
            tree[pos - 1] += val;
        }
    }

    int get(int pos) {
        int ret = 0;
        for (++pos; pos; pos -= (pos & (-pos))) {
            ret += tree[pos - 1];
        }
        return ret;
    }
} bit;


int main() {  Mo35();



return 0;
}