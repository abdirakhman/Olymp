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

int p[MAXN];
int rnk[MAXN];
int up[MAXN][18];
int mn[MAXN][18];
vector <pair <int, int> > g[MAXN];

int lvl[MAXN];
bool used[MAXN];
int d[MAXN];
int tin[MAXN];
int tout[MAXN];

int get(int v){
	if(p[v] == v) return v;
	return p[v] = get(p[v]);
}

bool Merge(int a,int b){
    a = get(a);
    b = get(b);
    if(a == b) return 0;
    if(rnk[a] > rnk[b]) swap(a,b);
    rnk[b] += rnk[a];
    p[a] = b;
    return 1;
}

int timer = 0;

void dfs(int v, int par) {
	tin[v] = ++timer;
	lvl[v] = lvl[par] + 1;
	for (auto i : g[v]) {
		if (i.first != par) {
			up[i.first][0] = v;
			mn[i.first][0] = i.second;
			dfs(i.first, v);
		}
	}
	tout[v] = timer;	
}      

bool in(int u,int v){
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u,int v){
	if(in(u,v)) return u;
	if(in(v,u)) return v;
	for(int i = 17; i >= 0; i--){
		if(up[v][i] != -1 && !in(up[v][i], u)) v = up[v][i];
	}
	return up[v][0];
}

int get(int v,int u){
    if(v == u) return 1e9;
    int res = 1e9;
    for(int i = 17; i >= 0; i--){
    	if(up[v][i] != -1 && !in(up[v][i], u)){
    		res = min(res, mn[v][i]);
    		v = up[v][i];
    	}
    }
    return min(res, mn[v][0]);
}

int get_min(int u,int v){
	int l = lca(u,v);
	return min(get(u,l), get(v,l));
}


int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt(), m = readInt();
    vector <pair <int, pair <int, int> > > vec;
    for (int i = 1; i <= m; i++) {
    	int u = readInt(), v = readInt(), w = readInt();
    	g[u].pb({v, w});
    	g[v].pb({u, w});
    	vec.pb({w, {u, v}});
    }
    int k = readInt();
	for (int i = 1; i <= n; i++) {
		d[i] = 1e9;
	}    
    set < pair<int,int> > q;
    for (int i = 1; i <= k; i++) {
    	int x = readInt();
    	d[x] = 0;
		q.insert({0, x});
    }
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase (q.begin());
		if (used[v]) continue;
		used[v] = 1; 
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
	for (int i = 1; i <= n; i++) {
		g[i].clear();
		p[i] = i;
		rnk[i] = 1;
	}
	for(int i = 0; i < m; i++)	{
		vec[i].first = min(d[vec[i].second.first], d[vec[i].second.second]); 
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < m; i++) {
		if (Merge(vec[i].second.first, vec[i].second.second)) {
			g[vec[i].second.first].pb({vec[i].second.second, vec[i].first});
			g[vec[i].second.second].pb({vec[i].second.first, vec[i].first});
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 17; j++) {
			mn[i][j] = 1e9;
			up[i][j] = -1;
		}
	}
	dfs(1, 0);
	for(int j = 1; j <= 17; j++){
	    for(int i = 1; i <= n; i++) if(up[i][j - 1] != -1){
	        up[i][j] = up[up[i][j - 1]][j - 1];
	        mn[i][j] = min(mn[i][j - 1], mn[up[i][j - 1]][j - 1]);
	    }
	}        
	int Q = readInt();
	while(Q--) {
		int v = readInt(), u = readInt();
		cout << get_min(u, v) << endl;
	}
	return 0;
}