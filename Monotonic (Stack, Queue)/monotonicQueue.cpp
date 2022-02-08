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

const int N = (1 << 18) + 5, M = N, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

struct MonoStack {
    stack<pair<int, int>> st;
    
    MonoStack() { st.emplace(INT_MIN, INT_MIN); }

    void push(int x) { st.emplace(x, ::max(x, st.top().second)); }
    void pop() { st.pop(); }
    int top() { return st.top().first; }
    int max() { return st.top().second; }
    int size() { return st.size() - 1; }
    bool empty() { return st.size() == 1; }
};

struct MonoQueue {
    MonoStack add, rem;

    void push(int x) { add.push(x); }
    void pop() {
        if (rem.empty()) move();
        rem.pop();
    }
    int top() {
        if (rem.empty()) move();
        return rem.top();
    }
    int max() { return ::max(add.max(), rem.max()); }
    int size() { return add.size() + rem.size(); }
    bool empty() { return !size(); }
    void move() {
        while (add.size()) {
            rem.push(add.top());
            add.pop();
        }
    }
};

int main() {  Alien35();

    

return 0;
}