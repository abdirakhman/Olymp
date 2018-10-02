/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

#define F first
#define S second
#define endl '\n'
#define pb push_back

const long long MOD = 1e9 + 7;
const long long SZ = 18;
const long long MAXN = 1e6 + 1;
const int MXN = 2e5 +777;
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

int a[MAXN];

set <int> L[MXN]; 

set <int> cnt[MXN];

int lvl[MAXN];
vector <int> g[MAXN];
int up[MAXN][SZ];
int d[MAXN];

int dfs(int v, int par) {
    lvl[v] = lvl[par] + 1;
    up[v][0] = par;
    for (int i = 1; i < SZ; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    d[v] = 1;
    for (auto i : g[v]) {
        if (i == par) continue;
        dfs(i, v);
        d[v] += d[i];
    }
}
int lca(int a, int b) {
    if (lvl[a] > lvl[b]) swap(a, b);
    for (int i = SZ - 1; i >= 0; i--) {
        if (lvl[up[b][i]] >= lvl[a]) {
            b = up[b][i];
        }
    }
    if (a == b) return a;
    for (int i = SZ - 1; i >= 0; i--) {
        if (up[b][i] != up[a][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt(), m = readInt(), q = readInt();
    for (int i = 1; i < n; i ++) {
    	int u = readInt(), v = readInt();
    	g[u].pb(v);
    	g[v].pb(u);
    }
    dfs(1, 0);
	for (int i = 1; i <= m; i++) {
		a[i] =  readInt();
		cnt[a[i]].insert(i);

		if (i != 1) {
			L[lca(a[i], a[i - 1])].insert(i-1);				
		}
	}
    while(q--) {
    	int type = readInt();
    	if (type == 1) {
			int pos = readInt(), v = readInt();
			cnt[a[pos]].erase(pos);
			if (pos != 1) {
				L[lca(a[pos - 1], a[pos])].erase(pos - 1);
			}
			if (pos != n) {
				L[lca(a[pos], a[pos + 1])].erase(pos);
			}
			a[pos] = v;
			cnt[v].insert(pos);
			if (pos != 1) {
			    L[lca(a[pos - 1], a[pos])].insert(pos - 1);
			} 
			if (pos != n) {
				L[lca(a[pos], a[pos + 1])].insert(pos);
			}
    	} else {
    		int l = readInt(), r = readInt(), v = readInt(); 	
        	if (!cnt[v].empty()) {
				auto i = cnt[v].lower_bound(l);
				if (i != cnt[v].end()) {
					int ans = *i;
					if (ans <= r) {
						cout << ans << ' ' << ans << endl;
						continue;				
					}
				}
			}
			if (!L[v].empty()) {
				auto i = L[v].lower_bound(l);
				if (i != L[v].end()) {
					int ans = *i;
					if (ans +1<= r) {
						cout << ans << ' ' << ans+1 << endl;					
				    	continue;
					}
				}
			} 
			cout << "-1 -1\n";
    	}
    }
    return 0;
}