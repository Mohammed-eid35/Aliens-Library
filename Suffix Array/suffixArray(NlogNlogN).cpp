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

const int N = 1e5 + 5, M = 1e3 + 5, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

char str[N];
int suf[N], group[N], sortedGroup[N];
int len;

void buildSuffix() {
    for (len = 0; !len || str[len - 1]; ++len) {
        suf[len] = len;
        group[len] = str[len];
    }
    int h = 1;
    do {
        auto cmp = [h](int a, int b) {
            return group[a] < group[b] || group[a] == group[b] && group[a + h] < group[b + h];
        };
        sort(suf, suf + len, cmp);
        sortedGroup[0] = 0;
        for (int i = 1; i < len; ++i) {
            sortedGroup[i] = sortedGroup[i - 1] + cmp(suf[i - 1], suf[i]);
        }
        for (int i = 0; i < len; ++i) group[suf[i]] = sortedGroup[i];
        h <<= 1;
    } while (sortedGroup[len - 1] != len - 1);
}

int main() {  Alien35();

    cin >> str;
    buildSuffix();

return 0;
}
