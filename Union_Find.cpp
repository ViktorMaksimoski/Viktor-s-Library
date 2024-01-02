#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n, comp;
    vector<int> par, size;

    void config(int _n) {
        n = _n + 1;
        comp = _n;
        par.resize(n+1);
        size.resize(n+1, 1);
        for(int i=1; i<=n; i++) par[i] = i;
    }

    int get(int u) {
        if(u == par[u]) return u;
        return par[u] = get(par[u]);
    }

    bool uni(int u, int v) {
        u = get(u), v = get(v);

        if(u == v) return false;
        if(size[u] < size[v]) swap(u, v);

        size[u] += size[v];
        par[v] = u;
        comp--;

        return true;
    }

    int getComp() { return comp; }
    int getSize(int u) { return size[get(u)]; }
    bool sameSet(int u, int v) { return get(u) == get(v); }
};
