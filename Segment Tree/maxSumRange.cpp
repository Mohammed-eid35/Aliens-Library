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

const int N = 1 << 17, M = N, OO = 0x3f3f3f3f, MOD = 1e9 + 7;
int n;
int ar[N];

struct SegmentTree {
    struct Node {
        int pre, suf, sum, mx;
    } tree[N << 1];

    Node merge(const Node &lf, const Node &rt) {
        Node ret;
        ret.sum = lf.sum + rt.sum;
        ret.pre = max(lf.pre, lf.sum + rt.pre);
        ret.suf = max(rt.suf, rt.sum + lf.suf);
        ret.mx = max({lf.mx, rt.mx, lf.suf + rt.pre});
        return ret;
    }

    void build(int ni = 0, int ns = 0, int ne = n - 1) {
        if (ns == ne) {
            // tree[ni].pre = tree[ni].suf = tree[ni].mx = max(tree[ni].sum = ar[ns], 0); allows empty sub-array
            tree[ni].pre = tree[ni].suf = tree[ni].mx = tree[ni].sum = ar[ns];
            return;
        }
        int lf = ni * 2 + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
        build(lf, ns, mid);
        build(rt, mid + 1, ne);
        tree[ni] = merge(tree[lf], tree[rt]);
    }

    Node query(int qs, int qe, int ni = 0, int ns = 0, int ne = n - 1) {
        if (ne < qs || ns > qe) return {-OO, -OO, 0, -OO};
        if (ns >= qs && ne <= qe) return tree[ni];
        int lf = ni * 2 + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
        return merge(query(qs, qe, lf, ns, mid), query(qs, qe, rt, mid + 1, ne));
    }

    void update(int pos, int val, int ni = 0, int ns = 0, int ne = n - 1) {
        if (ne < pos || ns > pos) return;
        if (ns == ne) {
            tree[ni].pre = tree[ni].suf = tree[ni].mx = tree[ni].sum = ar[ns] = val;
            return;
        }
        int lf = ni * 2 + 1, rt = lf + 1, mid = ns + (ne - ns) / 2;
        update(pos, val, lf, ns, mid);
        update(pos, val, rt, mid + 1, ne);
        tree[ni] = merge(tree[lf], tree[rt]);
    }
} seg;

int main() {  Alien35();

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    seg.build();
    int q; cin >> q;
    while (q--) {
        int typ, x, y; cin >> typ >> x >> y;
        if (typ) cout << seg.query(--x, --y).mx << '\n';
        else seg.update(--x, y);
    } 

return 0;
}