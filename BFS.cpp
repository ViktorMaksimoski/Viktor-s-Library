#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > graph;

int bfs(int s, int e) {
    vector<int> dist(n+1, 0);
    vector<bool> vis(n+1, 0);
    queue<int> q;

    vis[s] = 1;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        if(u == e) return dist[e];

        for(int &v : graph[u]) {
            if(vis[v]) continue;
            vis[v] = 1;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    return -1;
}