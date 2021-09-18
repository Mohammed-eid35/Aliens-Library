//:::: Alien :::://
// Muhammad Eid //
#include <bits/stdc++.h>
using namespace std;

// Start IterativeFastPower
long long IterativeFastPower(long long x, long long p) {
    long long ret = 1;

    while (p) {
        if (p & 1) ret *= x;
        x *= x;
        p >>= 1;
    }

    return ret;
}

int IterativeFastPower(int x, int p, int MOD) {
    int ret = 1;

    while (p) {
        if (p & 1) ret = (1ll * ret * x) % MOD;
        x = (1ll * x * x) % MOD;
        p >>= 1;
    }

    return ret;
}
// End IterativeFastPower


// Start RecursiveFastPower 
long long recursiveFastPower(long long x, long long p) {
    if (!p) return 1;
    long long ret = recursiveFastPower(x, p >> 1);
    ret *= ret;
    if (p & 1) ret *= x;
    return ret;
}

int recursiveFastPower(int x, int p, int MOD) {
    if (!p) return 1;
    int ret = recursiveFastPower(x, p >> 1, MOD);
    ret = (1ll * ret * ret) % MOD;
    if (p & 1) ret = (1ll * x * ret) % MOD;
    return ret;
}
// End RecursiveFastPower

int main() {

    cout << IterativeFastPower(2, 5) << '\n';
    cout << IterativeFastPower(2, 5, 20) << '\n';

    cout << recursiveFastPower(2, 5) << '\n';
    cout << recursiveFastPower(2, 5, 20) << '\n';

return 0;
}