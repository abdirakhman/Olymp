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
const long long MAXN = 1e6 + 1;
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


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

pii check(pii a, pii b) {
	if (a.F > b.F) {
		return a;
	} else if (a.F < b.F) {
		return b;
	} 
	if (a.S > b.S) {
		return b;
	} else {
		return a;
	}	
}

pii dp_sub[MAXN];
pii up[MAXN];
int a[MAXN];
int p[MAXN];
vector <int> g[MAXN];
int used[MAXN];



void calc_dp(int v, int par) {
    p[v] = par;
	dp_sub[v] = {-MOD, -1};				
	for (int i : g[v]) {
		if (par == i) continue;
		calc_dp(i, v);
		dp_sub[v] = check(dp_sub[v], make_pair(dp_sub[i].F - 1, dp_sub[i].S));
		dp_sub[v] = check(dp_sub[v], pii(a[i] - 1, i));
	}		
	/// add a[v]
}

void calc_up(int v, int par) {
    up[v] = {-MOD, -1};
	if (par == 0) {
    	up[v] = {-MOD, -1};
    } else {
    	up[v] = check(up[v], pii(up[par].F - 1, up[par].S)); 
    	up[v] = check(up[v], pii(a[par] - 1, par));
    	for (int i : g[par]) {
        	if (i == v || i == p[par]) continue;
    		up[v] = check(up[v], pii(dp_sub[i].F - 2, dp_sub[i].S)); 
    		up[v] = check(up[v], pii(a[i] - 2, i));
    	}
    } 
    for (int i : g[v]) {
    	if (i != par) {
    		calc_up(i, v);
    	} 
    }
}

int get_next(int v) {
	pii res = {-MOD, - 1};
	res = check(res, dp_sub[v]);
	res = check(res, up[v]);
	return res.S;
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt(), k = readInt();
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
    }
    for (int i = 1; i < n; i++) {
    	int u = readInt(), v = readInt();
    	g[u].pb(v);
    	g[v].pb(u);
    }
	calc_dp(1, 0);
	calc_up(1, 0);
	vector <int> tmp;
	int cur = 1;
	int timer = 1;
	while(k--) {
		if (used[cur] != 0) {
			k %= (timer - used[cur]);        	
        } else {
        	used[cur] = timer++;
        }
        cur = get_next(cur);
	}
	cout << cur;
	return 0;
}