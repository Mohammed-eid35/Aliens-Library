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

int trie[N][ALPHA], strID[N];
int numNodes;

int addNode() {
    memset(trie[numNodes], -1, sizeof(trie[numNodes]));
    strID[numNodes] = -1;
    return numNodes++;
}

void init() {
    numNodes = 0;
    addNode();
}

void insert(char *str, int ID) {
    int cur;
    for (cur = 0; *str; ++str) {
        char c = *str;
        int &node = trie[cur][c];
        if (!~node) node = addNode();
        cur = node;
    }
    strID[cur] = ID;
}

bool findWord(char *str) {
    int cur;
    for (cur = 0; *str; ++str) {
        char c = *str;
        int &node = trie[cur][c];
        if (!~node) return false;
        cur = node;
    }
    return ~strID[cur];
}

bool findPrefix(char *pre) {
    int cur;
    for (cur = 0; *pre; ++pre) {
        char c = *pre;
        int &node = trie[cur][c];
        if (!~node) return false;
        cur = node;
    }
    return true;
}

int main() {  Alien35();



return 0;
}
