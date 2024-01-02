#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

int n;
vector<vector<pii> > graph;

ll dijkstra(int s, int e) {
    vector<bool> vis(n+1);
    vector<ll> dist(n+1, 1e18);
    priority_queue<pll, vector<pll>, greater<pll> > pq;

    pq.push({ 0, s });
    dist[s] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = 1;

        for(auto &[v, w] : graph[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }

    return (vis[e] ? dist[e] : -1);
}