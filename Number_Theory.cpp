#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int maxn = 1e6 + 5;

bool sieve[maxn+1];
int mpf[maxn+1];

void setup() {
    sieve[1] = 1;
    for(int i=2; i<=maxn; i++) {
        if(sieve[i]) continue;
        mpf[i] = i;
        for(int j=2*i; j<=maxn; j+=i) {
            sieve[j] = 1;
            mpf[j] = i;
        }
    }
}

vector<pii> factorize(int x) {
    map<int, int> cnt;
    vector<pii> ans;

    while(x > 1) {
        cnt[mpf[x]]++;
        x /= mpf[x];
    }

    for(auto &x : cnt)
        ans.push_back({ x.first, x.second });
    return ans;
}