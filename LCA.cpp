#include <bits/stdc++.h>
using namespace std;
const int LOG = 20;

vector<vector<int> > graph, up;
vector<int> depth;

int jmp(int x, int d) {
    for(int j=LOG-1; j>=0; j--)
        if(d & (1 << j)) x = up[x][j];
    return x;
}

int get_lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);

    a = jmp(a, depth[a] - depth[b]);
    if(a == b) return a;
    for(int j=LOG-1; j>=0; j--)
        if(up[a][j] != up[b][j])
            a = up[a][j], b = up[b][j];

    return up[a][0];
}