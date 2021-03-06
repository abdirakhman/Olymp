/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

#define F first
#define S second
#define endl '\n'
#define pb push_back

const long long MOD = 1e9 + 7;
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

const int MAXN = 2e5 + 777;
vector<pair <int, int> > g[MAXN];
bool used[MAXN];
bool BRID[MAXN];
int n, m;
int timer = 0, tin[MAXN], fup[MAXN];
             
void dfs (int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;

	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i].first;
		if (to == p)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v]) {
				BRID[g[v][i].second] = 1;
			}
		}
	}
}
 
void find_bridges() {
	timer = 0;
	for (int i=1; i<=n; ++i)
		used[i] = false;
	for (int i=1; i<=n; ++i)
		if (!used[i])
			dfs (i);
}

int ans[MAXN];

int c[MAXN];

	
vector <int> G[MAXN];

int cc = 1;

void DFS(int v, int color) {
    c[v] = color;
    ans[color]++;
    for (auto to : g[v]) {
        if (c[to.first] != -1) continue;
        if (BRID[to.second]) {
            cc++;
           	G[color].push_back(cc - 1);
            G[cc - 1].push_back(color);
            DFS(to.first, cc - 1);
        } else {
            DFS(to.first, color);
        }
    }
}


void find_ans() {
	memset(c, -1, sizeof(c));
    cc = 1;
    DFS(1, 0);

    int mn = 0;
    int tot = 1;
    for (int i = 0; i < cc; i++) {
        if ((int)G[i].size() <= 1) {
            mn++; 
            tot = 1LL * tot * ans[i] % MOD;
        }
    }
    cout << mn << " " << tot << endl;


}

main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt(), m = readInt();
    for (int i = 1; i <= m; i++) {
    	int u = readInt(), v = readInt();
    	g[u].pb({v, i});
    	g[v].pb({u, i});
    }
    find_bridges();
    
    find_ans();
    return 0;
}