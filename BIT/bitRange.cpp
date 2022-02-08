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

struct BITrange {
    long long m[N], c[N];
    
    void init(int n) {
        memset(m, 0, n * sizeof(m[0]));
        memset(c, 0, n * sizeof(m[0]));
    }
    
    void add(int pos, long long mVal, long long cVal) {
        for (++pos; pos <= N; pos += (pos & (-pos))) {
            m[pos - 1] += mVal;
            c[pos - 1] += cVal;
        }
    }
    
    long long get(int pos) {
        long long ret = 0;
        int x = pos;
        for (++pos; pos; pos -= (pos & (-pos))) {
            ret += m[pos - 1] * x + c[pos - 1];
        }
        return ret;
    }
    
    void addRange(int st, int en, long long val) {
        add(st, val, -val * (st - 1));
        add(en + 1, -val, val * en);
    }
};

int main() {  Alien35();



return 0;
}