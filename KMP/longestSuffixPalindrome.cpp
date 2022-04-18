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

int longestSuffixPalindrome() {
    pat = str;
    reverse(pat.begin(), pat.end());
    pat = pat + '@' + str;
    computeFailure();
    return fail.back();
}

int main() {  Alien35();

    cin >> str;
    cout << longestSuffixPalindrome();

return 0;
}
