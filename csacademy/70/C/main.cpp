/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

#define F first
#define S second
#define endl '\n'
#define pb push_back

const long long MOD = 1e9 + 7;
const long long MAXN = 40000;
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

int n;

vector<int> d (MAXN);

bool U[MAXN];

vector <pair <int, int> > g[MAXN];

void dijkstra(int s) {
	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
	}
	d[s] = 0;
	set < pair<int,int> > q;
	q.insert (make_pair (d[s], s));
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase (q.begin());
 
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				q.erase (make_pair (d[to], to));
				d[to] = d[v] + len;
				q.insert (make_pair (d[to], to));
			}
		}
	}
}

int u[MAXN], v[MAXN], w[MAXN];

bool USED[MAXN];

vector <int> comp[MAXN];

void dfs(int v, int color)  {
	comp[color].pb(v);
	USED[v] = 1;
	for (auto i : g[v]) {
		if (!USED[i.first]) {
			dfs(i.first, color);
		}
	}
}
                        
int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
	n = readInt(); int m = readInt();
	for (int i = 1; i <= m; i++) {
		u[i] = readInt(), v[i] = readInt(), w[i] = readInt();
	    
		g[u[i]].pb({v[i], w[i]});
		g[v[i]].pb({u[i], w[i]});
		U[u[i]] = 1;
		U[v[i]] = 1;	
	}
	for (int i = 1; i <= n; i ++) {
		dijkstra(i);
		for (auto j : g[i]) {
			if (d[j.first] != j.second) {
				cout << "-1";
				return 0;				
			}		
		}
	}
	vector <pair <int, pair <int, int> > > ans;
	for (int i = 1; i <= m; i++) {
		ans.pb({u[i], {v[i], w[i]}});
	}
	int tmr = 0;
	for (int i = 1; i <= n; i++) {
		if (!USED[i]) {
			tmr ++;
			dfs(i, tmr);
		}
	}
	for (int i = 1; i < tmr; i++) {
		ans.pb({comp[i][0], {comp[i+1][0], 1}});
	}                
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
	}
    return 0;
}