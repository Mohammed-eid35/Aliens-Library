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

const int N = (1 << 18) + 5, M = N, OO = 0x3f3f3f3f, MOD = 1e9 + 7;
int n;
int ar[N];

struct SegmentTree {
    int tree[N];

    void build(int ni = 0, int ns = 0, int ne = n - 1) {
        if (ns == ne) {
            tree[ni] = ar[ns];
            return;
        }
        int L = ni * 2 + 1, R = L + 1, mid = ns + (ne - ns) / 2;
        build(L, ns, mid);
        build(R, mid + 1, ne);
        tree[ni] = max(tree[L], tree[R]);
    }

    void update(int pos, int val, int ni = 0, int ns = 0, int ne = n - 1) {
        if (ne < pos || ns > pos) return;
        if (ns == ne) {
            tree[ni] = val;
            return;
        }
        int L = ni * 2 + 1, R = L + 1, mid = ns + (ne - ns) / 2;
        update(pos, val, L, ns, mid);
        update(pos, val, R, mid + 1, ne);
        tree[ni] = max(tree[L], tree[R]);
    }

    int query(int qs, int qe, int ni = 0, int ns = 0, int ne = n - 1) {
        if (ne < qs || ns > qe) return INT_MIN;
        if (ns >= qs && ne <= qe) return tree[ni];
        int L = ni * 2 + 1, R = L + 1, mid = ns + (ne - ns) / 2;
        return max(query(qs, qe, L, ns, mid), query(qs, qe, R, mid + 1, ne));
    }
} seg;


int main() {  Mo35();

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    seg.build();
    int q; cin >> q;
    while (q--) {
        int typ; cin >> typ;
        if (typ == 0) { // Update
            int pos, val; cin >> pos >> val;
            seg.update(pos, val);
        }
        else { // Query (max)
            int st, en; cin >> st >> en;
            cout << seg.query(st, en) << '\n';
        }
    }

return 0;
}