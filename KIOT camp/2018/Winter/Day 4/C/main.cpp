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
const long long MAXN = 222;
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

int  used[MAXN];

vector <pair <int, int> > g[MAXN];
vector <int > G[MAXN];

int sz[MAXN];
int col[MAXN];

int cvet = 0;
void comp(int v) {
	sz[cvet]++;
	col[v] = cvet;
	used[v] = 1;
	for (auto i : g[v]) {
		if (!used[i.F] && i.S == 1) {
			comp(i.F);
		}
	}
} 



void kraska(int v) {
	used[v] = 1;                     
	for (auto i : g[v]) {
	    if (used[i.F]) continue;
		if (i.S == 1) {
			kraska(i.F);
		} else {
			G[col[v]].pb(col[i.F]);
			G[col[i.F]].pb(col[v]);
			kraska(i.F);
		} 
	}			
}             


const int N = 1e5+ 444;

int cnt[2][N];
int ans;

void get_ans(int v, int tmr, int deg) {
	if (sz[v] == 1) { 
		ans++;
	} else {
		cnt[deg % 2][tmr] += sz[v];
	}
	used[v] = 1;
	for (auto i : G[v]) {
		if (used[i]) continue;
		if (sz[i] == 1) {
			get_ans(i, tmr + 1, deg + 1);					
		} else {
			get_ans(i, tmr, deg + 1);
		}
	}
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    int n = readInt();
    for (int i = 1; i < n; i++) {
		int u = readInt(), v = readInt(), c=  readInt();
	    g[u].pb({v, c});
	    g[v].pb({u, c});    	
    }
    for (int i = 1; i <= n; i++) {
    	if (!used[i]) {
    		cvet++;
    		comp(i);
    	}
    }
//    for (int i = 1; i <= n; i++) {
//    	cout << col[i] << ' ';
//    }
    //cout << endl;
    memset(used, 0, sizeof(used));
    kraska(1);
    memset(used, 0, sizeof(used));
    //cerr << 1;
	get_ans(col[1], 1, 1);
	for (int i = 1; i < N; i++) {
		ans += min(2 * cnt[0][i] + 3 * cnt[1][i], 3 * cnt[0][i] + 2 * cnt[1][i]);
	}
	cout << ans << endl;
//	for (int i = 1; i <= cvet; i++) {
//		for (int j : G[i]) {
//			cout << i << ' ' << j << endl;
//		}		
//	}
	return 0;
}