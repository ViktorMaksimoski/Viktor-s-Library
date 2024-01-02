#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Line container for maximum query

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line &o) { return k < o.k; }
    bool operator<(ll x) { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    const ll inf = LLONG_MAX;

    ll div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }

    bool intersect(iterator x, iterator y) {
        if(y == end()) return x->p = inf, 0;
        if(x->k == y->k) return x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
    };

    void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (intersect(y, z)) z = erase(z);
		if (x != begin() && intersect(--x, y)) intersect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			intersect(x, erase(y));
	}

    ll query(ll x) {
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
}; 