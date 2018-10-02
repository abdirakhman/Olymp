/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back

const long long MOD = 1e9 + 7;
const long long MAXN = 1e6 + 1;
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


inline void writeInt(long long x, char END) {
	if (x < 0)
		putchar('-'), x = -x;
	char s[65];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		putchar(s[n]);
	if (END)
		putchar(END);
}

int up[MAXN][23];

int timer = 0;

int depth[MAXN];

int tin[MAXN];
int tout[MAXN];


vector <int> g[MAXN];

int centroid_of[MAXN];

set <int> c[MAXN];
int sz[MAXN];


void dfs (int v, int par = 1) {
    tin[v] = ++timer;
    up[v][0] = par;
    depth[v] = depth[par] + 1;

    for(int h = 1; h <= 21; h++)
        up[v][h] = up[up[v][h - 1]][h - 1];

    for(const int &u : g[v])
        if(u != par)
            dfs(u, v);
    tout[v] = timer;
}

inline bool parent (const int &x, const int &y) {return tin[x] <= tin[y] && tout[x] >= tout[y];}


inline int lca (int v, const int &x) {
    if(parent(v, x)) return v;
    if(parent(x, v)) return x;
    for(int h = 21; h >= 0; h--)
        if(!parent(up[v][h], x))
            v = up[v][h];
    return up[v][0];
}

inline int dist (const int &v, const int &u) {return depth[v] + depth[u] - (depth[lca(u, v)] * 2);}

int centroid(int v, int par, int m) {
	for (int i : c[v]) {
		if (i != par && sz[i] > (m/2)) {
			return centroid(i, v, m);
		}		
	}
	return v;
}

int CalcSZ(int v, int par) {
	sz[v] = 1;
	for (int i : c[v]) {
		if (i != par) {
			sz[v] += CalcSZ(i, v);
		}
	}
	return sz[v];
}

void find_centroid(int v, int par) {
	int m = CalcSZ(v, v);
	int C = centroid(v, v, m);
	centroid_of[C] = par;
	for (int i : c[C]) {
		c[i].erase(C);
		find_centroid(i, C);		
	}
}


int d[MAXN];
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n = readInt(), m = readInt();
    for (int i = 1; i < n; i ++) {                 
    	int u = readInt(), v = readInt();
    	g[u].pb(v);
    	g[v].pb(u);
    	c[v].insert(u);                      	
    	c[u].insert(v);
    }
    dfs(1);
    find_centroid(1, -1);

    for (int i = 1; i <= n; i++) {
    	d[i] = depth[i] - 1;
    }
    for (int i = 1; i <= m; i++) {
    	int type = readInt(), x = readInt();
		if (type == 1) {
		    d[x] = 0;
		    for (int i = x; i != -1; i = centroid_of[i]) {
		    	d[i] = min(d[i], dist(i, x));
		    } 
		} else {
			int ans = 1e9;
			for (int i = x; i != -1; i = centroid_of[i]) {
				ans = min(ans, dist(i, x) + d[i]);							
			}
			cout << ans << endl;			
		}                                       
    }
    return 0;
}