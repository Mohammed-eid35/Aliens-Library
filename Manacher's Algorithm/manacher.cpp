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

string strExtend(const string &s) {
    string ret = "$#";
    for (char i: s) ret += i + string("#");
    return ret + string("^");
}

vector<int> manacher(const string &s) {
    int sz = s.size();
    vector<int> p(sz);
    int m = p[0] = 0;
    for(int i = 1; i < sz; ++i) {
        p[i] = p[2 * m - i];
        p[i] = min(p[i], m + p[m] - i);
        while (s[i + p[i] + 1] == s[i - p[i] - 1]) p[i]++;
        if (p[i] + i > p[m] + m) m = i;
    }
    return p;
}

int main() {  Alien35();

    string str; cin >> str;
    vector<int> res = manacher(strExtend(str));

return 0;
}
