/**
SXR0aXAkI0JwbXptI3FhI3Z3I293bCNqY2IjUG0jMCNicG0jVHFkcXZvLyNCcG0jQW10bjBhY2phcWFicXZvLyNNYm16dml0MSNWdyNhdGN1am16I2tpdiNhbXF9bSNQcXUjVnd6I0F0bW14MSNQcWEjaXptI2l0dCNicHF2b2EjUXYjYnBtI3BtaWRtdmEjaXZsI3d2I21pemJwMSNFcHcjcWEjYnBtem0ja2l2I3F2Ym16a21sbSNRdiNQcWEjeHptYW12a20jbXtrbXhiI0lhI3BtI3htenVxYmJtYnBHI1BtI3N2d2VtYnAjRXBpYiMraXh4bWl6bWJwI2J3I1BxYSNrem1pYmN6bWEjSWEsI0ptbnd6bSN3eiNJbmJteiN3eiNKbXBxdmwjYnBtdTEjVnd6I2FwaXR0I2JwbXwja3d1eGlhYSNJY29wYiN3biNwcWEjc3Z3ZXRtbG9tI017a214YiNpYSNQbSNlcXR0bWJwMSNQcWEjYnB6d3ZtI2x3YnAjbXtibXZsI1dkbXojYnBtI3BtaWRtdmEjSXZsI3d2I21pemJwLyNpdmwjUG0jbm1tdG1icCNWdyNuaWJxb2NtI3F2I29jaXpscXZvI0l2bCN4em1hbXpkcXZvI2JwbXUvI053eiNQbSNxYSNicG0jVXdhYiNQcW9wMSNCcG0jQWN4em11bSMrcXYjb3R3enwsMQ==
*/
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

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

const int MXLOG = 17;

int up[MAXN][MXLOG];

vector <int> g[MAXN];

int deg[MAXN];

void dfs(int v, int par = 0, int d = 0) {
	deg[v] = d;		
	for (int i = 1; i < MXLOG; i++) {
		up[v][i] = up[up[v][i - 1]][i - 1];	
	}
	for (int i : g[v]) {
		if (i != par) {
			dfs(i, v, d+  1);
		}	
	}
}


int lca(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
    if (deg[a] > deg[b]) swap(a, b);
    for (int i = MXLOG - 1; i >= 0; i--) {
        if (deg[up[b][i]] >= deg[a]) {
            b = up[b][i];
        }
    }
    if (a == b) return a;
    for (int i = MXLOG - 1; i >= 0; i--) {
        if (up[b][i] != up[a][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int p[MAXN];

int sparse[MXLOG][MAXN];

int n, q;
                           	
int numlog[MAXN];

void build_sparse() {
	numlog[1] = 0;
	for (int i = 2; i <= n; i++) {
		numlog[i] = numlog[i / 2] + 1;
	}
	for (int i = 0; i <= numlog[n]; i++) {
		int curlen = (1 << i);
		for(int j = 1; j <= n; j++) {
			if (i == 0) {
				sparse[i][j] = j;
			} else {
				sparse[i][j] = lca(sparse[i - 1][j], sparse[i - 1][j + curlen / 2]);	
			}
		}
	}
}

int getlca(int l, int r) {
	if (l > r) return 0;
	int curlog = numlog[r - l + 1];
    return lca(sparse[curlog][l], sparse[curlog][r - (1 << curlog) + 1]); 
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    n = readInt(), q = readInt();
    for (int i = 2; i <= n; i++) {
    	p[i] = readInt();
    	//g[i].pb(p[i]);
    	up[i][0]=p[i];
    	g[p[i]].pb(i);
    }
    up[1][0] = 1;
    dfs(1);
	build_sparse();
	while(q--) {
		int l = readInt(), r = readInt();
		int L = l, R = r;
		//deb(l);deb(r);
		int LCA = getlca(l, r);
		//cout << LCA << endl;
		if(r - l + 1 <= 3) {
			int a = l , b = deg[getlca(l+1, r)];
			for(int i = l + 1; i <= r; i++) {
				int now = deg[lca(getlca(l, i - 1), getlca(i + 1, r))];
				if(now > b)
					a = i , b = now;
			}
			cout << a << " " << b << endl;
		} else {
			int ans = l;
			int to_add = 0;
			while (1) {
				if (L == R) {
					ans = L;
					break;
				}
				int mid = (L + R) / 2;
				int L_ans = lca(to_add, getlca(L, mid)) , R_ans = lca(to_add, getlca(mid + 1, R));
				if (deg[L_ans] > deg[LCA] && deg[R_ans] > deg[LCA])
					break;
				else if(L_ans == LCA)
					to_add = R_ans, R = mid;
				else if(R_ans == LCA)
					to_add = L_ans, L = mid + 1;
			}
			cout << ans << " " << deg[lca(getlca(l, ans-1),getlca(ans+1, r))] << endl;
		}
	}
    return 0;
}