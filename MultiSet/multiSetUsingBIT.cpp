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

const int N = 1 << 18, M = N, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

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
    
    int find(int target) {
        int st = 0;
        for (int sz = N >> 1; sz; sz >>= 1) {
            if (tree[st + sz - 1] < target) {
                target -= tree[(st += sz) - 1];
            }
        }
        return st;
    }
};

struct MultiSet {
    BIT bit;
    MultiSet() {
        bit.init();
        bit.add(0, -1);
    }
    
    void insert(int val) { bit.add(val, 1); }
    
    void erase(int val) { bit.add(val, -1); }
    
    int count(int val) { return bit.get(val) - bit.get(val - 1); }
    
    int size() { return bit.get(N - 1) + 1; }
    
    int at(int idx) { return bit.find(idx); }
};

int main() {  Alien35();



return 0;
}