/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <bits/stdc++.h>

#define F first
#define S second
#define endl '\n'
#define pb push_back

const long long MOD = 1e9 + 7;
const int MAXN = 5e5 + 777;
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

int n, m;
int a[MAXN];
bool used[MAXN];
int cnt[MAXN];
int d[MAXN];
bool is_cycle[MAXN];
vector <int> g[MAXN];
int Ans1, Ans2;
int Ans;
void find_cycles() {
	queue <int> q;
	for (int i = 1; i <= n; i++) {
		cnt[i] = g[i].size();		
		is_cycle[i] = !(cnt[i] <= 1);
		if (!is_cycle[i]) {
			q.push(i);		
		}
	}
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i : g[v]) {
			if (!is_cycle[i]) {
            	continue;
            }
            if (--cnt[i] == 1) {
                is_cycle[i] = 0;
            	q.push(i);
            } 
		}
	}
}

void dfs(int v, int par = 0) {
	int mx1 = 0, mx1_id = 0;
	for (int i : g[v]) {
		if (par == i || is_cycle[i]) continue;
		dfs(i, v);
		if (d[i] > mx1) {
			mx1 = d[i];
			mx1_id = i;
		}
	}
	d[v] = mx1 + a[v];
	for (int i : g[v]) {
		if (i == par || is_cycle[i] || mx1_id == i) {
			continue;
		}
		Ans = max(Ans, d[i]);
	}
}

void Relax(int &x, int &y, int z) {
	if (z > x) {
		y = x;
		x = z;
	} else if (z > y) {
		y = z;
	}
}

void find_ans() {
	for (int i = 1; i <= n; i++) {
		if (!used[i] && is_cycle[i]) {
			used[i] = 1;
			for (int j : g[i]) {
				if (is_cycle[j]) continue;
				Ans = 0;
				dfs(j);
				Relax(Ans1, Ans2, d[j]);
				Relax(Ans1, Ans2, Ans);			
			}
		}
	}
}

void jfs(int v, int par = 0) {
    int mx1 = 0, mx2 = 0;
    for (int to : g[v]) {
        if (to == par) {
            continue;
        }
        jfs(to, v);
        Relax(mx1, mx2, d[to]);
    }
 
    d[v] = mx1 + a[v];
    Ans = max(Ans, d[v] + mx2);
}
 


main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt(), m = readInt();     
    for (int i = 1; i <= n; i++) {
    	a[i]  = readInt();
    }
    for (int i = 1; i <= m; i++) {
    	int u = readInt(), v = readInt();
    	g[u].pb(v);
    	g[v].pb(u);
    }
    if (n - 1 == m) {
		jfs(1);
		cout << Ans;
		return  0;   	
    }
    find_cycles();
    find_ans();
    for (int i = 1; i <= n; i++) {
    	if (is_cycle[i]) Ans1 += a[i];
    }
    cout << Ans1 + Ans2;
    return 0;
}