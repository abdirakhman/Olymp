/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

#define F first
#define S second
#define endl '\n'
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

map <pair <int, int>, bool> krat;
map <pair <int, int>, bool> U;

int C = 0;

int used[MAXN];

int cnt = 0;

void dfs(int v, int par) {
	used[v] = 1;
	cnt++;
	for (int i : g[v]) {
		if (i == par) continue;
		if (used[i] == 1) {
			if (krat[{v, i}]) {
				cout << ">1";
				exit(0);
			}
			C++;
		} 
		if (!used[i]) {
			dfs(i, v);
		}
	}
	used[v] = 2;
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt(), m = readInt();
    for (int i = 1; i <= m; i++) {
    	int v = readInt(), u = readInt();
    	if (U[{v, u}]) {
    		krat[{v, u}] = 1;
    	}
    	g[u].pb(v);
    	g[v].pb(u);
    	U[{u, v}] = 1;
    	U[{v, u}] = 1;
    }
    bool cyc = 0;
    int res = 0;
    for (int i = 1; i <= n; i ++) {
    	if (!used[i]) {
			cnt = 0;
			C = 0;
			dfs(i, 0);
			if (C > 1) {
				cout << ">1";
				return 0;
			}
			if (C) {
				cyc |= C;				
			} else{
				res = max(res, cnt);
			}		    		
    	}
    }
    if (cyc) {
    	cout << "1/1";
    	return 0;
    }
    int G = __gcd(res, res - 1);
    cout << (res-1) / G << "/" << (res)/G << endl;
    return 0;
}       