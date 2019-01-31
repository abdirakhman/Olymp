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
const long long MAXN = 1e3 + 228;
const long long INF = 1e15;
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;


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


vector <pii> g[MAXN];
ll p[MAXN];
ll d[MAXN];
ll mn_edg[MAXN];
ll dist[MAXN][MAXN];
int n, m;

void dijkstra(int s) {
	d[s] = 0;
	set < pii > q;
	q.insert ({d[s], s});
	while (!q.empty()) {
		ll v = q.begin()->second;
		q.erase (q.begin());
		for (int j = 1; j <= n; j++) {
			ll to = j;
			ll len = dist[v][j];
			if (d[v] + len <= d[to]) {
				if (len > mn_edg[to] && d[v] + len == d[to]) continue;
				q.erase({d[to], to});
				d[to] = d[v] + len;
				p[to] = v;
				mn_edg[to] = len;
				q.insert({d[to], to});
			}
		} 	
	}
}                          

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt(), m = readInt();
    for (int i = 1; i <= n; i++) {
    	d[i] = INF;
    }
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		dist[i][j] = INF;
    	}
    }
    for (int i = 1; i <= m; i++) {
    	ll u = readInt(), v = readInt(), l = readInt();
    	g[u].pb({v, l});
    	g[v].pb({u, l});
    	dist[u][v] = min(dist[u][v], l);
    	dist[v][u] = min(dist[v][u], l);
    }
    dijkstra(1);
    ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += dist[i][p[i]];
	}
	cout << ans;
    return 0;
}