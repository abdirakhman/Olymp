/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define F first
#define S second
#define endl '\n'
#define deb(x) cout<<#x<<' '<<x<<endl;
#define pb push_back

/*
#ifdef IZI_KATKA
#define int __int64_t
#else
#define int __int64
#endif
*/

const long long MOD = 1e9 + 9;
const long long MAXN = 1e5 + 10;
const int MXLOG = 17;
using namespace std;

typedef long long ll;

long long readInt() {
    bool minus1 = false;
    long long result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus1 = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus1)
        return -result;
    else
        return result;
}

struct edge {
	int u, id;
};

vector <edge> g[MAXN]; 
vector <int> G[MAXN];
int tin[MAXN];
int fup[MAXN];
int used[MAXN];
int BRID[MAXN];
int timer;
int n, m;
int tout[MAXN];
int P[MAXN];
int lvl[MAXN];
int rk[MAXN];
int marked[MAXN];
int dp[MAXN];
int up[MAXN][MXLOG + 5];
int par[MAXN];

int getpar(int v) {
	return (par[v] == v ? v : par[v] = getpar(par[v]));
}

bool Merge(int v,int u){
	v = getpar(v);
	u = getpar(u);
	if(v == u)
		return 0;
	if(rk[v] < rk[u])
		swap(v, u);
	rk[v] += rk[u];
	par[u] = v;
	return 1;
}


void dfs (int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i].u;
		if (to == p)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v])
				BRID[g[v][i].id] = 1;
		}
	}
}


void find_bridges() {
	timer = 0;
	for (int i = 1; i <= n; ++i)
		used[i] = false;
	for (int i = 1; i <= n; ++i)
		if (!used[i])
			dfs (i);
}

int cc = 1;

void DFS(int v, int color) {
    used[v] = color;
    for (auto to : g[v]) {
        if (used[to.u] != 0) continue;
        if (BRID[to.id]) {
            cc++;
           	G[color].push_back(cc);
            G[cc].push_back(color);
            DFS(to.u, cc);
        } else {
            DFS(to.u, color);
        }
    }
}

void build_LCA(int v, int p = 0) {
	tin[v] = ++timer;
	up[v][0] = p;
	dp[v] = dp[p] + marked[v];
	for (int i = 1; i <= MXLOG; ++i) {
		up[v][i] = up[up[v][i-1]][i-1];
	}
	lvl[v] = lvl[p] + 1;
	for (int i = 0; i < G[v].size(); ++i) {
		int to = G[v][i];
		if (to != p)
			build_LCA (to, v);
	}
	tout[v] = ++timer;
}

bool upper (int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b) {
	if (upper (a, b))  return a;
	if (upper (b, a))  return b;
	for (int i = MXLOG; i >= 0; --i)
		if (! upper (up[a][i], b))
			a = up[a][i];
	return up[a][0];
}


int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
	n = readInt(), m = readInt();
	P[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		P[i] = (P[i - 1] * 2) % MOD;
	}
	for (int i = 1; i <= n; i++) {
		rk[i] = 1;
		par[i] = i;
	}
	vector <int> cyc;
	for (int i = 1; i <= m; i++) {
		int to = readInt(), from = readInt();
		if (!Merge(to, from)) {
			cyc.pb(to);
		}
		edge tmp1;
		tmp1.u = from;
		tmp1.id = i;
		g[to].pb(tmp1);
		tmp1.u = to;
		g[from].pb(tmp1);	
	}
	find_bridges();
	for (int i = 1; i <= n; i++) {
		used[i] = 0;
	}                          
	
	DFS(1, 1);
	for (int i : cyc) {
		marked[used[i]] = 1;
	}
	timer = 0;
	build_LCA(1);
	int q = readInt();
	while(q--) {
		int a = readInt(), b = readInt();
		a = used[a];
		b = used[b];
		int L = lca(a,b);
		int ans = dp[a] + dp[b] - 2 * dp[L];
		ans += (marked[L]);
		cout << P[ans] << endl;
	}
    return 0;
}