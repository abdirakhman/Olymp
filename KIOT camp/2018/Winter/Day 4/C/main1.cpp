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
#define pii pair<int,int>
/*
#ifdef IZI_KATKA
#define int __int64_t
#else
#define int __int64
#endif
*/

const long long MOD = 1e9 + 7;
const long long MAXN = 333;
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

int dp[MAXN][228];
int used[MAXN];
vector <pair <int, int> > g[MAXN];

void dfs(int v) {
    for (int i = 1; i <= 200; i++) {
		dp[v][i] = i;
	}
	used[v] = 1;
	//vector <pii> vec;
	for (auto i : g[v]) {
		if (used[i.F]) continue;
		dfs(i.F);
		if (i.S == 1) {
			for (int curx = 1; curx <= 200; curx++) {
				int mn = MOD;
				for (int j = 1; j <= 200; j ++) {
					if (__gcd(curx, j) > 1)
						mn = min(mn, dp[i.F][j]);
				}
			    if (mn == MOD) {
				   	dp[v][curx] = MOD;
					continue;
				}
				dp[v][curx] += mn;
			}
		} else {
		    for (int curx = 1; curx <= 200; curx++) {
				int mn = MOD;
				for (int j = 1; j <= 200; j ++) {
				    if (__gcd(curx, j) == 1)
						mn = min(mn, dp[i.F][j]);
				}
				if (mn == MOD) {
				   	dp[v][curx] = MOD;
					continue;
				}
				dp[v][curx] += mn;
			}
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
    dfs(1);
    int mn = MOD;
    for (int i = 1; i <= 200; i++) {
    	mn = min(mn, dp[1][i]);
    }
    cout << mn;
    return 0;
}