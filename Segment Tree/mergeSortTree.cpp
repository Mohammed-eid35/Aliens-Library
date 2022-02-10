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

typedef vector<int> Node;
const int N = 1 << 17, M = N, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int ar[N];

struct SegmentTree {
    Node tree[N];
    
    Node merge(const Node &lf, const Node &rt) {
        int i = 0, j = 0, k = 0, lfs = lf.size(), rts = rt.size();
        Node ret(lfs + rts);
        while (i < lfs && j < rts) {
            if (lf[i] < rt[j]) {
                ret[k++] = lf[i++];
            }
            else {
                ret[k++] = rt[j++];
            }
        }
        while (i < lfs) {
            ret[k++] = lf[i++];
        }
        while (j < rts) {
            ret[k++] = rt[j++];
        }
        return ret;
    }

    void build(int ni = 0, int ns = 0, int ne = n - 1) {
        if (ns == ne) {
            tree[ni].push_back(ar[ns]);
            return;
        }
        int lf = ni * 2 + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
        build(lf , ns, mid);
        build(rt, mid + 1, ne);
        tree[ni] = merge(tree[lf],  tree[rt]);
    }

    int query(int qs, int qe, int k, int ni = 0, int ns = 0, int ne = n - 1) {
        if (ns > qe || ne < qs) {
            return 0;
        }
        if (ns >= qs && ne <= qe) {
            return tree[ni].end() - upper_bound(tree[ni].begin(), tree[ni].end(), k);
        }
        int lf = ni * 2 + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
        return query(qs, qe, k, lf, ns, mid) + query(qs, qe, k, rt, mid + 1, ne);
    }

    void update(int pos, int val, int ni = 0, int ns = 0, int ne = n - 1) {
        if (ne < pos || ns > pos) return;
        if (ns == ne) {
            tree[ni][0] = val;
            return;
        }
        int lf = ni * 2 + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
        update(pos, val, lf, ns, mid);
        update(pos, val, rt, mid + 1, ne);
        tree[ni] = merge(tree[lf], tree[rt]);
    }
} seg;

int main() {  Alien35();



return 0;
}