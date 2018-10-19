/*
ID: IsmailAbdrakhman
LANG: C++11
PROB: grass
*/
/*
Compress cycles. 
Choose two vertexes calc(1, v) + calc(u, 1) by dp
:)
*/

/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>
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
const long long INF = 1e9 + 7;
const long long MAXN = 1e5 + 1;
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


vector <int> g[2][MAXN];
stack <int> S;
int n, m;
int P[MAXN];
bool used[MAXN];
int color[MAXN];
int cnt = 0;

void dfs(int v, int type) {
	if (type) {
		P[cnt]++;
		color[v] = cnt;		
	}
	used[v] = 1;
	for (int i : g[type][v]) {
		if (!used[i]) {
			dfs(i, type);
		}		
	}
	if (!type) {
		S.push(v);
	}
}

void SCC() {
	for (int i = 1; i <= n; i++) {
		if (!used[i])
			dfs(i, 0);
	}
	memset(used, 0, sizeof(used));
	while(!S.empty()) {
		int v = S.top();
		S.pop();
		if (!used[v]) {
			cnt++;
			dfs(v, 1);
		}
	}	
}

set <int> new_g[2][MAXN];
int dist[2][MAXN];

void Dfs(int v) {	
	used[v] = 1;
    for (int i : g[0][v]) {
    	if (color[i] != color[v]) {
			new_g[0][color[v]].insert(color[i]);
			new_g[1][color[i]].insert(color[v]);			  		
    	}
    	if (!used[i]) {
    		Dfs(i);
    	}
    }
}

void create_new() {
	/// GOOD
	memset(used, 0, sizeof(used));
	for (int i = 1; i <= n; i++) {
		if (!used[i])
			Dfs(i);	
	}
}

bool G(int at) {
    if (dist[0][at] == -INF) return false;
    if (dist[0][at] != -2) return true;
    if (at == color[1]) {
        dist[0][at] = 0;
        return true;
    }
    int ret = -INF;
    for (int i: new_g[0][at]) if (G(i)) {
        ret = max(ret, dist[0][i]);
    }
    if (ret == -1) {
        dist[0][at] = -1;
        return false;
    }
    dist[0][at] = ret + P[at];
    return true;
}

bool F(int at) {
    if (dist[1][at] == -INF) return false;
    if (dist[1][at] != -2) return true;
    if (at == color[1]) {
        dist[1][at] = P[at];
        return true;
    }
    int ret = -INF;
    for (int i: new_g[1][at]) if (F(i)) {
        ret = max(ret, dist[1][i]);
    }
    if (ret == -1) {
        dist[1][at] = -1;
        return false;
    }
    dist[1][at] = ret + P[at];
    return true;
}


int main() {
	ofstream fout("grass.out");
    ifstream fin("grass.in");

    
	fin >> n >> m;
    for (int i = 1; i <= m; i++){
    	int u, v;
    	fin >> u >> v;
    	g[0][u].pb(v);
    	g[1][v].pb(u);
    }
    SCC();
	//print_path();
	create_new();		
	/*for (int i = 1; i <= cnt; i++) {
		for (int j : new_g[0][i]) {
			cout << i << ' ' << j << ' ';		
			cout << endl;
		}
	}*/
	for (int i = 1; i <= n; i++) {
		dist[0][i] = dist[1][i] = -2;
	}
	for (int i = 1; i <= cnt; i++) {
		G(i);
		F(i);	
	}
	int ans = P[color[1]];
	for (int i = 1; i <= cnt; i++) {
		for (int j : new_g[0][i]) {
			ans = max(ans, dist[1][j] + dist[0][i]);			
		}
	}
	fout << ans;
    return 0;
}

///16:24 45      20min     48-10
/**
1 X
3 1
X 5
3 X
3 5
3 6
6 5

*/