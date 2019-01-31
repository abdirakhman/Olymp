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

const long long MOD = 1e9 + 7;
const long long MAXN = 1e5 + 1;
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

deque <pair <int, int> > chain[MAXN];
vector <int> g[MAXN];
int par[MAXN];
int deg[MAXN];
int nxt[MAXN];
int in[MAXN];
int out[MAXN];
int a[MAXN];
int sz[MAXN];


void dfs_sz(int v = 1) {
	sz[v] = 1;
	for (int &i : g[v]) {
		par[i] = v;
		deg[i] = deg[v] + 1;
		dfs_sz(i);
		sz[v] += sz[i];
		if (sz[i] > sz[g[v][0]]) {
			swap(i, g[v][0]);
		}
	}
}

void dfs_hld(int v = 1) {
	for (int i : g[v]) {
		nxt[i] = (i == g[v][0] ? nxt[v] : i);
		dfs_hld(i);
	}
}


int fen[MAXN];
int N;

void init(int n)
{
	N = n;
	for(int i = 0; i <= N; i++) fen[i] = 0;
}

void update(int pos, int v)
{
	pos++;
	for(;pos <= N;pos += (pos&(-pos)))
	{
		fen[pos] += v;
	}
}


int query(int pos)
{
	pos++;
	int sum = 0;
	for(;pos; pos -= (pos&(-pos)))
	{
		sum += fen[pos];
	}
	return sum;
}


ll calc_path(int u) {
	vector <pair <int, int> > V;
	vector <int> coord;
	while(u != -1) {
		int next_u = nxt[u];
		int Sz = deg[u] - deg[next_u] + 1;
		vector <pair <int, int> > tmp;
		for (int i = 0; i < chain[next_u].size(); i++) {
			int cnt = chain[next_u][i].first;
			int v = chain[next_u][i].second;
			if (cnt <= Sz) {
				tmp.pb({cnt, v});
				Sz -= cnt;
			} else {
				tmp.pb({Sz, v});
				break;
			}
		}
		for(int i = int(tmp.size()) - 1; i >= 0; i--) {
			V.pb(tmp[i]);
			coord.pb(tmp[i].second);
		}
		u = par[next_u];
	}
	reverse(V.begin(), V.end());
	sort(coord.begin(), coord.end());
	coord.erase(unique(coord.begin(), coord.end()), coord.end());
	init(int(coord.size()));
	ll res = 0, tot = 0;
	for (pair <int, int> i : V) {
		i.second = lower_bound(coord.begin(), coord.end(), i.second) - coord.begin();
		res += i.first * (tot - query(i.second));
		tot += i.first;
		update(i.second, i.first);
	}
	return res;
}


void addedge(int u, int v)
{
	while(u != -1) {
		int next_u = nxt[u];
		int Sz = deg[u] - deg[next_u] + 1;
		while(chain[next_u].size() > 0) {
			int cnt = chain[next_u][0].first;
			if (cnt <= Sz) {
			    chain[next_u].pop_front();
			    Sz -= cnt;
			} else {
				chain[next_u].front().first -= Sz;
				break;
			}
		}
		chain[next_u].push_front({deg[u] - deg[next_u] + 1, v});
		u = par[next_u];
	}
}


int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
    }
    nxt[1] = 1;
    chain[1].pb({1, a[1]});
    par[1] = -1;
    vector <pair <int, int> > Q;
    for (int i = 1; i < n; i++) {
    	int u = readInt(), v = readInt();
    	g[u].pb(v);
    	Q.pb({u, v});
    }
    dfs_sz();
    dfs_hld();
    for (int i = 0; i < n - 1; i++) {
    	cout << calc_path(Q[i].first) << endl;
    	addedge(Q[i].second, a[Q[i].second]);
    }
    return 0;
}
