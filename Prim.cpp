#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
vector<vector<pii> > graph;

ll prim(int s) {
    ll mst = 0;

    vector<bool> vis(n+1);
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    pq.push({ 0, s });
    vis[s] = 1;

    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = 1;

        for(auto &[v, w] : graph[u])
            if(!vis[v]) pq.push({ w, v });
    }

    return mst;
}