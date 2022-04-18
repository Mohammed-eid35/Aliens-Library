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

int getHashValue(string pat, int patSZ) {
    int patCode = 0;
    for (int i = 0; i < patSZ; ++i) {
        patCode = shiftLeft(patCode);
        patCode = addAt(patCode, 0, valueOf(pat[i]));
    }
    return patCode;
}

vector<int> patternSearch(string str, string pat) {
    int strSZ = str.size(), patSZ = pat.size();
    int patCode = getHashValue(pat, patSZ), subCode = 0;
    vector<int> ret;
    for (int i = 0; i < strSZ; ++i) {
        if (i - patSZ >= 0) subCode = removeAt(subCode, patSZ - 1, valueOf(str[i - patSZ]));

        subCode = shiftLeft(subCode);
        subCode = addAt(subCode, 0, valueOf(str[i]));

        if (patCode == subCode) ret.push_back(i - patSZ + 1);
    }
    return ret;
}

int main() {  Alien35();

    string str, pat; cin >> str >> pat;
    vector<int> res = patternSearch(str, pat);
    for (int i : res) cout << i << ' ';

return 0;
}
