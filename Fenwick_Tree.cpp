#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct BIT {
    int n;
    vector<ll> tree, val;

    void config(int _n) {
        n = _n + 10;
        tree.resize(_n+60);
        val.resize(_n+60);
    }

    void add(int p, int v) {
        val[p] += v;
        for(p++; p<n; p+=p&-p) tree[p] += v;
    }

    ll sum(int p) {
        ll ans = 0;
        for(p++; p>0; p-=p&-p) ans += tree[p];
        return ans;
    }

    ll sum(int l, int r) { return sum(r) - sum(l-1); }
    void set(int p, int v) { add(p, v - val[p]); }
};
