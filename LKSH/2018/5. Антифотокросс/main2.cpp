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

const int N = 255;
const int K = 255;

int dp[N][N][2];

vector <int> g[N];

void dfs(int v, int par, int X) {
	
	for (int i : g[v]) {
		if (par == i) continue;
		dfs(i, v, X);
	}
	
	for(int to : g[v]){
		dp[v][1][1] += dp[to][1][1];
		dp[v][1][0] += dp[to][1][1]; 
	}

	dp[v][1][1] ++;

	for(int i = 2; i <= n; i++){
		for(int to : g[v]){
			dp[v][i][1] += dp[to][i - 1][0];
		}
		for(int to : g[v]){
			int mx = 0;
			for(int j = max(i, X - i - 2); j <= n; j++){
				mx = max(mx, dp[to][j][0]);
			} 
			dp[v][i][0] += mx;
		}
	}
}


int n, k;


void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j] = 0;
		}
	}
}

int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
	n = readInt(), k = readInt();
	for (int i = 1; i < n; i++) {
		int u = readInt(), v = readInt();
		g[u].pb(v);
		g[v].pb(u);
	}                
	int l = 1, r = n-1;
	while(r - l > 1) {
		int m = (l + r) / 2;
		init();
		dfs(1, 0, m);
		deb(m);
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			ans = max(ans, max(dp[1][i][0], dp[1][i][1]));		
		}	    
	    if (ans >= k) {
			l = m;
		} else {
			r = m;		
		}
	}
	cout << l << ' ' << r;	
    return 0;
}