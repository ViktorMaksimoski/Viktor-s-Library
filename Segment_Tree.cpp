#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector<ll> tree, lazy;

    void config(int _n) {
        n = _n;
        tree.resize(4*n+5);
        lazy.resize(4*n+5);
    }

    void push(int u, int tl, int tr) {
        if(!lazy[u]) return ;
        tree[u] += (tr - tl + 1) * lazy[u];

        if(tl != tr) {
            lazy[2*u] += lazy[u];
            lazy[2*u+1] += lazy[u];
        }

        lazy[u] = 0;
    }

    void update(int u, int tl, int tr, int l, int r, int val) {
        push(u, tl, tr);
        if(tl > tr || tl > r || l > tr) return ;

        if(l <= tl && tr <= r) {
            lazy[u] += val;
            push(u, tl, tr);
            return ;
        }

        int tm = (tl + tr) / 2;
        update(2*u, tl, tm, l, r, val);
        update(2*u+1, tm+1, tr, l, r, val);
        tree[u] = tree[2*u] + tree[2*u+1];
    }

    int query(int u, int tl, int tr, int l, int r) {
        if(tl > tr || l > tr || tl > r) return 0;
        push(u, tl, tr);
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        return query(2*u, tl, tm, l, r)
        + query(2*u+1, tm+1, tr, l, r);
    }

    void point_add(int p, int v) { update(1, 0, n-1, p, p, v); }
    void range_add(int l, int r, int v) { update(1, 0, n-1, l, r, v); }
    int query(int l, int r) { return query(1, 0, n-1, l, r); }
    int query(int p) { return query(1, 0, n-1, p, p); }
};