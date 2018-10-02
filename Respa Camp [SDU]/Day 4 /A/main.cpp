/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back

const long long MOD = 1e9 + 7;
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


vector <int> vec[MAXN];

int up[MAXN][23];
int timer = 0;
vector <int> g[MAXN];
vector <int> ans[MAXN][23];
int lvl[MAXN];


vector <int> Merge(vector <int> & a, vector <int> & b) {
	vector <int> res;
	int i = 0, j = 0;
	while(i < a.size() && j < b.size()) {
		if (a[i] < b[j]) {
			if (res.size() == 0) {
				res.pb(a[i]);
			} else if (res.size() < 10 && res[res.size() - 1] != a[i])
			res.pb(a[i]);                         
			i++;
		} else {
			if (res.size() == 0) {
				res.pb(b[j]);
			} else if (res.size() < 10  && res[res.size() - 1] != b[j])
			res.pb(b[j]);
			j++;
		}
	}
	while(i < a.size()) {
	    if (res.size() == 0) {
			res.pb(a[i]);
		}
		else if (res.size() < 10 && res[res.size() - 1] != a[i])
			res.pb(a[i]);
		i++;		
	}
	while(j < b.size()) {
		if (res.size() == 0) {
			res.pb(b[j]);
		} else if (res.size() < 10 && res[res.size() - 1] != b[j])
		res.pb(b[j]);
		j++;	
	}
	return res;
}
void dfs (int v, int par = 0) {
    up[v][0] = par;                                       
    lvl[v] = lvl[par] + 1;
	ans[v][0] = Merge(vec[v], vec[par]);	
    for(int h = 1; h <= 21; h++) {
        up[v][h] = up[up[v][h - 1]][h - 1];
		ans[v][h] = Merge(ans[v][h-1], ans[up[v][h-1]][h-1]);
	}		
    for(const int &u : g[v])
        if(u != par)
            dfs(u, v);
}



vector <int> lca(int a, int b) {
    vector <int> tmp = Merge(vec[a], vec[b]); 
    if (lvl[a] > lvl[b]) swap(a, b);
    for (int i = 21; i >= 0; i--) {
        if (lvl[up[b][i]] >= lvl[a]) {
            tmp = Merge(tmp, ans[b][i]);
            b = up[b][i];
        }
    }  
    if (a == b) return tmp;
    for (int i = 21; i >= 0; i--) {
        if (up[b][i] != up[a][i]) {
            tmp = Merge(tmp, ans[b][i]);
            tmp = Merge(tmp, ans[a][i]);
            a = up[a][i];
            b = up[b][i];
        }
    }
    return Merge(tmp, vec[up[b][0]]);
}



int main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif
    int n = readInt(), m = readInt(), q = readInt();
	for (int i = 1; i  < n; i++) {
		int u = readInt(), v = readInt();
		g[u].pb(v);
		g[v].pb(u);
	}
	for (int i = 1; i <= m; i++) {
		int x = readInt();
		if (vec[x].size() < 10)
		vec[x].pb(i);
	}
	dfs(1);
	while(q--) {
		int v = readInt(), u = readInt(), a = readInt();
		vector <int> L = lca(v, u);
		cout << min((int)L.size(), a) << ' ';
		for (int i = 0; i < min((int)L.size(), a); i++) {
			cout << L[i] << ' '; 
		}				
		cout << endl;
	}
    return 0;
}