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

vector <int> g[MAXN];
set <int> c[MAXN];
int col[MAXN];
vector <int> Ans[MAXN];
int sz[MAXN];


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


void find_centroid(int v, int par = 0) {
	int m = CalcSZ(v, v);
	int C = centroid(v, v, m);
	Ans[par].pb(C);
	for (int i : c[C]) {
		c[i].erase(C);
		find_centroid(i, C);		
	}
}


void DFS(int v, int depth) {
	col[v] = depth;
	if (depth > 26) {
		cout << "Impossible";
		exit(0);
	}
	for (int i : Ans[v]) {
	   DFS(i, depth + 1);
	}	
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n = readInt();
    for (int i = 1; i < n; i++) {
    	int u = readInt(), v = readInt();
		g[u].pb(v);
		g[v].pb(v);
		c[u].insert(v);
		c[v].insert(u);
    }
    find_centroid(1);
    cerr << 1;
    DFS(0, 0);
	for (int i = 1; i <= n; i++) {
		cout << char(col[i] + 'A' - 1) << ' ';
	}    
    return 0;
}