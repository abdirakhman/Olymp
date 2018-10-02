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
int used[MAXN];
int sz[MAXN];
int cnt[MAXN];
int k;
int ans = 0;  


int centroid(int v, int par, int m) {
	for (int i : g[v]) {
		if (!used[i] && i != par && sz[i] > (m/2)) {
			return centroid(i, v, m);
		}		
	}
	return v;
}

int CalcSZ(int v, int par) {
	sz[v] = 1;
	for (int i : g[v]) {
		if (i != par && !used[i]) {
			sz[v] += CalcSZ(i, v);
		}
	}
	return sz[v];
}


void Find(int v, int par, int dist) {
	if (k >= dist) {
		ans += cnt[k - dist];
	}		
	for (int i : g[v]) {
		if (!used[i] && i != par) {
			Find(i, v,  dist + 1);
		}
	}
}

void Fill(int v, int par, int dist) {
	cnt[dist]++;
	for (int i : g[v]) {
		if (!used[i] && i != par) {
			Fill(i, v,  dist + 1);
		}
	}
}

void Tazart(int v, int par, int dist) {
	cnt[dist] = 0;
	for (int i : g[v]) {
		if (!used[i] && i != par) {
			Tazart(i, v,  dist + 1);
		}
	}
}


void find_centroid(int v, int par = 0) {
	int m = CalcSZ(v, v);
	int C = centroid(v, v, m);
	used[C] = 1;
	cnt[0] ++;
	for (int i : g[C]) {
		if (!used[i]) {
			Find(i, C, 1);
			Fill(i, C, 1);
		}
	}
	for (int i : g[C]) {
		if (!used[i]) {
			Tazart(i, C, 1);
		}
	}
	for (int i : g[C]) {
		if (!used[i]) {
			find_centroid(i, C);
		}
	}
}




int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n = readInt();k = readInt();
    for (int i = 1; i < n; i++) {
    	int u = readInt(), v = readInt();
		g[u].pb(v);
		g[v].pb(u);
    }
    find_centroid(1);
	cout << ans;
    return 0;
}