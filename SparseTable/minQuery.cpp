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

const int N = 1e5 + 5, LG = 17, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int ar[N];

struct SparseTable {
    int sp[LG][N], lg[N];
    
    SparseTable() {
        init();
    }

    void init() {
        lg[0] = -1;
        for (int i = 0; i < N - 1; ++i) {
            sp[0][i] = i;
            lg[i + 1] = lg[i] + !(i & (i + 1));
        }
    }

    void build() {
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                int a = sp[j - 1][i];
                int b = sp[j - 1][i + (1 << (j - 1))];
                sp[j][i] = ar[a] < ar[b] ? a : b;
            }
        }
    }

    int getMinIdx(int st, int en) {
        int sz = en - st + 1;
        int l = lg[sz];
        int a = sp[l][st];
        int b = sp[l][en - (1 << l) + 1];
        return ar[a] < ar[b] ? a : b;
    }
};

int main() {  Alien35();



return 0;
}