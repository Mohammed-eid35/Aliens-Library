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

const int N = 1e5 + 5, SQ = 317, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int ar[N];

struct SQRTdecomposition {
    int sq, pre[SQ];

    SQRTdecomposition() {
       sq = ceil(sqrt(n)); 
    }
    
    void build() {
        for (int i = 0, j = 0; i < n; i += sq, ++j) {
            pre[j] = INT_MAX;
            for (int k = 0; k < sq && k + i < n; ++k) {
                pre[j] = min(pre[j], ar[i + k]);
            }
        }
    }

    int RMQ(int st, int en) {
        int stB = st / sq, enB = en / sq;
        
        if (stB == enB) return *min_element(ar + st, ar + en + 1);
        
        int ret = min(
            *min_element(ar + st, ar + (stB + 1) * sq),
            *min_element(ar  + enB * sq, ar + en + 1)
        );
        
        if (stB + 1 != enB) ret = min(
            ret,
            *min_element(pre + stB + 1, pre + enB)
        );
        return ret;
    }
};

int main() {  Alien35();



return 0;
}