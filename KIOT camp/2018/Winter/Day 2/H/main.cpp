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
const long long MAXN = 2e6 + 1;
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


vector <int> g[MAXN];
int P[2][MAXN];
int p[MAXN];
int tin[MAXN];
int par[MAXN];
int deg[MAXN];
int tout[MAXN];
int t[2][MAXN];
int timer = 0;

int add (int x, int y) {
//	return (x + y) % mod;
	long long res = x + y;
	if (res < 0) res += MOD;
	if (res >= MOD) res -= MOD;
	return res; 
}

int mult (int x, int y) {
//	return (x * y) % mod;
	long long res = 1ll * x * y;
	while (res < 0) res += MOD;
	if (res >= MOD) res = res % MOD;
	return res;    
}


void dfs(int v, int par = 0) {
	timer++;
	tin[v] = timer;
	deg[v] = deg[par] + 1;
	for (int i : g[v]) {
		if (par != i) {
			dfs(i, v);
		}
	}		
	tout[v] = timer;
}


void push(int type, int v, int tl, int tr) {
	if (P[type][v]) {
		t[type][v] = add(t[type][v], (mult((tr - tl + 1), P[type][v])));
		if (tl != tr) {
			P[type][v * 2] = add(P[type][v * 2], P[type][v]);
			P[type][v * 2 + 1] = add(P[type][v * 2 + 1], P[type][v]);
		}
		P[type][v] = 0;
	}
}

void upd(int type, int v, int tl, int tr, int l, int r, int x) {
	push(type, v, tl, tr);
	if (tr < l) return;
	if (r < tl) return;
	if (l <= tl && tr <= r) {
	    P[type][v] = add(P[type][v], x);
		push(type, v, tl, tr);
		return;
	}	
	int tm = (tl + tr) / 2;
	upd(type, v * 2, tl, tm, l, r, x);
	upd(type, v * 2 + 1, tm + 1, tr, l, r, x);
	t[type][v] = add(t[type][v * 2], t[type][v * 2 + 1]);
}


int get(int type, int v, int tl, int tr, int l, int r) {
	push(type, v, tl, tr);
	if (tr < l) return 0;
	if (r < tl) return 0;
	if (l <= tl && tr <= r) {
		return t[type][v];		
	}
	int tm = (tl + tr) / 2;
	return add(get(type, v * 2, tl, tm, l, r), get(type, v * 2 + 1, tm + 1, tr, l, r));
}

main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
    for (int i = 2; i <= n; i++) {
    	p[i] = readInt();
    	g[i].pb(p[i]);
    	g[p[i]].pb(i);
    }
    dfs(1);
	int q = readInt();
	while(q--) {
		int type = readInt();
		if (type == 1) {
			int v = readInt(), x = readInt(), k = readInt();
			upd(1, 1, 1, timer, tin[v], tout[v], add(x, mult(k, deg[v])));
			upd(0, 1, 1, timer, tin[v], tout[v], (-k + MOD)%MOD);					
		} else {
			int v=  readInt();
			cout << add(get(1, 1, 1, timer, tin[v], tin[v]), mult(deg[v], get(0, 1, 1, timer, tin[v], tin[v]))) << endl;
		}
	}
    return 0;
}