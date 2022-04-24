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

const int N = 2e5 + 5, ALPHA = 128 + 5, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

char str[N];
int suf[N], newSuf[N], groups[N], newGroups[N], groupStart[N], lcp[N];
int *head = newGroups, *nxt = newSuf;
int len;

void buildLCP(){
    int cnt=0;
    for (int i = 0; i < len - 1; ++i) {
        int j = suf[groups[i] - 1];
        while (str[i + cnt] == str[j + cnt]) cnt++;
        lcp[groups[i]] = cnt;
        if (cnt) cnt--;
    }
}

void buildSuffix() {
    memset(head, -1, ALPHA * sizeof(head[0]));
    for (len = 0; !len || str[len-1]; ++len) {
        nxt[len] = head[str[len]];
        head[str[len]] = len;
    }
    int curSt = 0, numOfGroups = -1;
    for (int i = 0; i < ALPHA; ++i) {
        if (head[i] == -1) continue;
        groupStart[++numOfGroups] = curSt;
        for (int j =head[i]; ~j; j = nxt[j]) {
            groups[j] = numOfGroups;
            suf[curSt++] = j;
        }
    }
    newGroups[len - 1] = numOfGroups;
    newSuf[0] = suf[0];
    newGroups[0] = 0;
    for (int h = 1; newGroups[len - 1] != len - 1; h <<= 1) {
        for (int i = 0; i < len; ++i) {
            int j = suf[i] - h;
            if (j < 0) continue;
            newSuf[groupStart[groups[j]]++] = j;
        }
        numOfGroups = 1;
        for (int i = 1; i < len; ++i) {
            bool newGroup = groups[newSuf[i - 1]] < groups[newSuf[i]] || groups[newSuf[i - 1]] == groups[newSuf[i]] && groups[newSuf[i - 1] + h] < groups[newSuf[i] + h];
            newGroups[i] = newGroups[i - 1] + newGroup;
            if (newGroup) groupStart[numOfGroups++] = i;
        }
        for (int i = 0; i < len; ++i) groups[suf[i] = newSuf[i]] = newGroups[i];
    }
}

long long numDistinctSubstrings() {
    return len * (len - 1ll) / 2 - accumulate(lcp, lcp + len, 0ll);
}

int main() {  Alien35();

    cin >> str;
    buildSuffix();
    buildLCP();
    cout << numDistinctSubstrings() << '\n';

return 0;
}
