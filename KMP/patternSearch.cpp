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

const int N = 1e5 + 5, M = 1e4 + 5, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

string str, pat;
vector<int> fail;

int newK(int k, char c) {
    while (k && pat[k] != c) k = fail[k - 1];
    return k + (c == pat[k]);
}

void computeFailure() {
    if (pat.empty()) return;
    fail = vector<int> (pat.size());
    for (int i = 1; pat[i]; ++i) {
        fail[i] = newK(fail[i - 1], pat[i]);
    }
}

vector<int> patternSearch() {
    computeFailure();
    int k = 0;
    vector<int> ret;
    for (int i = 0; str[i]; ++i) {
        k = newK(k, str[i]);
        if (!pat[k]) ret.push_back(i - k + 1);
    }
    return ret;
}

int main() {  Alien35();

    cin >> str >> pat;
    vector<int> res = patternSearch();
    for (int i : res) cout << i << ' ';

return 0;
}
