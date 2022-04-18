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

const int N = 1e4 + 5, M = 1e3 + 5, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

vector<int> computeZ(const string &s) {
    int sz = s.size();
    vector<int> z(sz);
    for (int i = 1, l = 0, r = 0; i < sz; ++i) {
        if (i <= r) z[i] = min (r - i + 1, z[i - l]);

        while (i + z[i] < sz && s[z[i]] == s[i + z[i]]) z[i]++;

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

vector<int> patternSearch(const string &str, const string &pat) {
    return computeZ(pat + "#" + str);
}

int main() {  Alien35();

    string str, pat; cin >> str >> pat;
    vector<int> z = patternSearch(str, pat);
    int patSZ = pat.size(), zSZ = z.size();
    for (int i = 0; i < zSZ; ++i) {
        if (z[i] == patSZ) {
            cout << i - patSZ - 1 << ' ';
        }
    }

return 0;
}
