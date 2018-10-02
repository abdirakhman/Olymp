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
vector<int> g[MAXN];
bool used[MAXN];
int h;
int n, m;
vector <int> G[MAXN];
vector <int> GR[MAXN];

vector <int> vec[MAXN];
            

int ans[MAXN];

vector<int> order, component;


void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<G[v].size(); ++i)
		if (!used[ G[v][i] ])
			dfs1 (G[v][i]);
	order.push_back (v);
}
 
void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<GR[v].size(); ++i)
		if (!used[ GR[v][i] ])
			dfs2 (GR[v][i]);
}
 


void find_ans() {     
	memset(used, 0, sizeof(used));
	for (int i=1; i<=n; ++i)
		if (!used[i])
			dfs1 (i);
	memset(used, 0, sizeof(used));
	int mn = 1e9;
	vector <int> ans;
	for (int i=1; i<=n; ++i) {
		int v = order[n-i];
		if (!used[v]) {
			dfs2 (v);
			if (mn > component.size() && component.size() > 1) {
				mn = component.size();
				ans = component;
			}
			component.clear();
		}
	}

    cout << ans.size() << endl;
    for (int i : ans) {
    	cout << i << ' ';
    }


}

int a[MAXN];


main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt(), m = readInt(), h = readInt();
    for (int i = 1; i <= n; i++) {
    	a[i] = readInt();
    }
    for (int i = 1; i <= m; i++) {
    	int u = readInt(), v = readInt();
    	g[u].pb(v);
    	g[v].pb(u);
    	if ((a[u]+1) % h == a[v]) {
    		G[u].pb(v);
    		GR[v].pb(u);
    	} 
    	if ((a[v] + 1) % h == a[u]) {
    		G[v].pb(u);
    		GR[u].pb(v);
    	}
    }
    for (int i = 1; i <= n; i++) {
    	bool ok = 1;
    	for (auto j : g[i]) {
    		if (a[j] == (a[i]+1) % h) {
    			ok = 0;
    			break;
    		}
    	}
    	if (ok) {
    		cout << 1 << endl;
    		cout << i;
    		return 0;
    	}      
    }
    
    find_ans();
    return 0;
}