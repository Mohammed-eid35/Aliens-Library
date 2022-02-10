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

const int N = (1 << 18) + 5, M = N, OO = 0x3f3f3f3f, MOD = 1e9 + 7;
int n;
int ar[N];

struct SegmentTree {
    struct Node {
        int sum, lazy;

        Node() { sum = lazy = 0; }
        
        void add(int val, int ns, int ne) {
            sum += val * (ne - ns + 1);
            lazy += val;
        }
    } tree[N << 1];

    void build(int ni = 0, int ns = 0, int ne = n - 1) {
        if (ns == ne) {
            tree[ni].sum = ar[ns];
            return;
        }
        int lf = ni * 2 + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
        build(lf, ns, mid);
        build(rt, mid + 1, ne);
    }

    void pushDown(int ni, int ns, int ne) {
        if (!tree[ni].lazy || ns == ne) return;
        int lf = ni * 2 + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
        tree[lf].add(tree[ni].lazy, ns, mid);
        tree[rt].add(tree[ni].lazy, mid + 1, ne);
        tree[ni].lazy = 0;
    }

    int query(int qs, int qe, int ni = 0, int ns = 0, int ne = n - 1) {
        if (ne < qs || ns > qe) return 0;
        if (ns >= qs && ne <= qe) return tree[ni].sum;
        pushDown(ni, ns, ne);
        int lf = ni * 2 + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
        return query(qs, qe, lf, ns, mid) + query(qs, qe, rt, mid + 1, ne);
    }

    void update(int qs, int qe, int val, int ni = 0, int ns = 0, int ne = n - 1) {
        if (ne < qs || ns > qe) return;
        if (ns  >= qs && ne <= qe) {
            tree[ni].add(val, ns, ne);
            return;
        }
        pushDown(ni, ns, ne);
        int lf = ni * 2 + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
        update(qs, qe, val, lf, ns, mid);
        update(qs, qe, val, rt, mid + 1, ne);
        tree[ni].sum = tree[lf].sum + tree[rt].sum;
    }
} seg;

int main() {  Alien35();

    

return 0;
}