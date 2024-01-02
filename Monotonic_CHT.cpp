#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct CHT {
    struct Line {
        ll a, b;
        Line(ll x, ll y): a(x), b(y) {}

        ll val(ll x) { return a * x + b; }
        ll intersect(Line y) { return (y.b - b + a - y.a) / (a - y.a); }
    };

    deque<pair<Line, ll> > q;

    void insert(ll a, ll b) {
        Line line(a, b);
        while(q.size() > 0 && q.back().second >= q.back().first.intersect(line))
            q.pop_back();

        if(q.empty()) {
            q.push_back({ line, 0 });
            return ;
        }

        q.push_back({ line, q.back().first.intersect(line) });
    }

    ll query(ll x) {
        while(q.size() > 1) {
            if(q[1].second <= x) q.pop_front();
            else break;
        }

        return q.front().first.val(x);
    }
};