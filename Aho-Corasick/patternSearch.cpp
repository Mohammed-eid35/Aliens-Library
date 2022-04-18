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

const int N = 1e6 + 5, ALPHA = 128, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

char str[int(1e5) + 9], pat[int(1e3) + 9], childChars[N][ALPHA];
int child[N][ALPHA], fail[N], nxt[N], patID[N], childCharsSZ[N];
int numNodes;

int addNode() {
    memset(child[numNodes], -1, sizeof(child[numNodes]));
    patID[numNodes] = -1;
    childCharsSZ[numNodes] = 0;
    return numNodes++;
}

void init() {
    numNodes = 0;
    addNode();
}

int insert(char *pat, int ID) {
    int cur;
    for (cur = 0; *pat; ++pat) {
        char c = *pat;
        int &node = child[cur][c];
        if (!~node) {
            node = addNode();
            childChars[cur][childCharsSZ[cur]++] = c;
        }
        cur = node;
    }
    return ~patID[cur] ? patID[cur] : (patID[cur] = ID);
}

int nxtF(int f, char c) {
    while (!~child[f][c]) f = fail[f];
    f = child[f][c];
    return f;
}

void computeFail() {
    queue<int> qu;
    for (int i = 0; i < ALPHA; ++i) {
        int &node = child[0][i];
        if (~node) {
            fail[node] = nxt[node] = 0;
            qu.push(node);
        }
        else {
            node = 0;
        }
    }
    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        for (int i = 0; i < childCharsSZ[u]; ++i) {
            char c = childChars[u][i];
            int v = child[u][c];
            fail[v] = nxt[v] = nxtF(fail[u], c);
            qu.push(v);
        }
    }
}

int Nxt(int u) {
    if (!u) return u;
    int &v = nxt[u];
    return ~patID[v] ? v : v = Nxt(v);
}

vector<vector<int>> match(int numPat) {
    vector<vector<int>> ret(numPat);
    int cur = 0;
    for (int i = 0; str[i]; ++i) {
        char c = str[i];
        cur = nxtF(cur, c);
        for (int p = cur; p; p = Nxt(p)) {
            int x = patID[p];
            if (~x) ret[x].push_back(i);
        }
    }
    return ret;
}

void printTrie() {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < childCharsSZ[i]; j++) {
            char c = childChars[i][j];
            int x = child[i][c];
            cout << i << "," << nxt[i] << " " << x << "," << nxt[x] << " " << c << endl;
        }
    }
    for (int i = 1; i < numNodes; i++) {
        int x = fail[i];
        cout << i << "," << nxt[i] << " " << x << "," << nxt[x] << endl;
    }

}

int names[N];

void test() {
    init();
    int q; cin >> str >> q;
    for (int i = 0; i < q; ++i) {
        cin >> pat;
        names[i] = insert(pat, i);
    }
    // printTrie();
    computeFail();
    auto ret = match(q);
    for (int i = 0; i < q; ++i) {
        auto &res = ret[names[i]];
        cout << (res.empty() ? 'n' : 'y') << '\n';
    }
}

int main() {  Alien35();

    int t; cin >> t;
    while (t--) {
        test();
    }

return 0;
}
