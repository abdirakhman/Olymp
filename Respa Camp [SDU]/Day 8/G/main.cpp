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
   
int timer = 0;

ll mod[4*MAXN];
int tin[MAXN];
int tout[MAXN];
int col[MAXN];
int pos[MAXN];

void dfs(int v, int par = 0) {
	tin[v] = ++timer;
	pos[timer] = v;
	for (int i : g[v]) {
		if (i != par) {
			dfs(i, v);
		}
	}
	tout[v] = timer;
}

ll t[MAXN * 4];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = (1LL<<col[pos[tl]]);
		return;
	} 
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = (t[v * 2] | t[v * 2 + 1]);
}
void push(int v, int tl, int tr) {
    if (mod[v] != 0) { 
        if (tl != tr) {
            mod[v * 2] = mod[v * 2 + 1] = mod[v];
        	int tm = (tl + tr) / 2;
	        t[v * 2] = mod[v * 2];
        	t[v * 2 + 1] = mod[v * 2 + 1];
    	}
    	mod[v] = 0;   
    }
}


ll get_sum(int v, int tl, int tr, int l, int r) {
    if (l <= tl && tr <= r) {
        return t[v];
    }
    if (tr < l || r < tl) {
        return 0;
    }
    int tm = (tl + tr) / 2;
    push(v, tl, tr);  
    return (get_sum(v * 2, tl, tm, l, r) | get_sum(v * 2 + 1, tm + 1, tr, l, r));
}
 
void upd(int l, int r, int val, int v, int tl, int tr) {
    if (l <= tl && tr <= r) {
        t[v] = (1LL << val);
        mod[v] = (1LL << val);   
        return;
    }
    if (tr < l || r < tl) {
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    upd(l, r, val, v * 2,     tl,     tm);
    upd(l, r, val, v * 2 + 1, tm + 1, tr);
    t[v] = (t[v * 2] | t[v * 2 + 1]);
}



int main() {
    int n = readInt(), m = readInt();
    for (int i = 1; i <= n; i ++) {
    	col[i] = readInt();
    }   
    for (int i = 1; i < n; i++) {
    	int u = readInt(), v = readInt();
    	g[u].pb(v);
    	g[v].pb(u);
    }
    dfs(1);
    build(1, 1, n);
	while(m--) {
    	int type = readInt();
    	if (type & 1) {
    		int v = readInt(), c = readInt();
    		upd(tin[v], tout[v], c, 1, 1, n);
    	} else {
			int v = readInt();
			cout << __builtin_popcountll(get_sum(1, 1, n, tin[v], tout[v])) << endl;     		 
    	}
    }
    return 0;
}