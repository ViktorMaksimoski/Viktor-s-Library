#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

ll inv[maxn+1], fac[maxn+1];

ll exp(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

ll getInv(ll x) { return exp(x, mod - 1); }

void setup() {
    fac[0] = 1, inv[0] = 1;
    for(int i=1; i<=maxn; i++) {
        fac[i] = (fac[i-1] * i) % mod;
        inv[i] = getInv(fac[i]);
    }
}

ll choose(ll n, ll k) {
    if(n < k) return 0;
    return fac[n] * inv[k] % mod * inv[n-k] % mod;
}