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

const int N = 1e5 + 5, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

int Power(int x, int p) {
    int ret = 1;
    while (p) {
        if (p & 1) ret = (ret * 1LL * x) % MOD;
        x = (x * 1LL * x) % MOD;
        p >>= 1;
    }
    return ret;
}

const int BASE = 128, BASE_INV = Power(BASE, MOD - 2);

int valueOf(char c) {
    return c;
}

int removeAt(int code, int idx, int val) {
    return (code - (val * 1LL * Power(BASE, idx)) % MOD + MOD) % MOD;
}

int addAt(int code, int idx, int val) {
    return (code + (val * 1LL * Power(BASE, idx)) % MOD) % MOD;
}

int shiftLeft(int code) {
    return (code * 1LL * BASE) % MOD;
}

int shiftRight(int code) {
    return (code * 1LL * BASE_INV) % MOD;
}

int numberOfPalindrome(string str, int len) {
    int n = str.size(), longestSuffix = 0;
    int strCode = 0, strRevCode = 0;

    for (int i = 0, j = len - 1; i < len; ++i, --j) {
        strCode = shiftLeft(strCode);
        strCode = addAt(strCode, 0, valueOf(str[i]));

        strRevCode = shiftLeft(strRevCode);
        strRevCode = addAt(strRevCode, 0, valueOf(str[j]));
    }
    int res = (strCode == strRevCode);
    for (int i = len; i < n; ++i) {
        strCode = removeAt(strCode, len - 1, valueOf(str[i - len]));
        strCode = shiftLeft(strCode);
        strCode = addAt(strCode, 0, valueOf(str[i]));

        strRevCode = removeAt(strRevCode, 0, valueOf(str[i - len]));
        strRevCode = shiftRight(strRevCode);
        strRevCode = addAt(strRevCode, len - 1, str[i]);

        res += (strCode == strRevCode);
    }
    return res;
}

int main() {  Alien35();

    int len; cin >> len;
    string str; cin >> str;
    cout << numberOfPalindrome(str, len);

return 0;
}
