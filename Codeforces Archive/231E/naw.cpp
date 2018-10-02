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


#ifdef IZI_KATKA
#define int __int64_t
#else
#define int __int64
#endif


const long long MOD = 1e9 + 7;
const long long MAXN = 1e6 + 1;   
const int MXLOG = 18;
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


int N,M;
pair <int, int> edge[MAXN];
vector <int> g[MAXN];
vector <int> G[MAXN];
int used[MAXN];
int marked[MAXN];
int up[MAXN][MXLOG];
int dp[MAXN];
int lvl[MAXN];

void dfs(int v,int p) {
	used[v] = v;
	for (int i = 0; i < g[v].size(); i++){
		int a = g[v][i];
		if (a == p) continue;
		if (used[a] != 0){
			used[v] = used[a];
			continue;
		}
		dfs (a,v);
		if (used[a] != a)
			used[v] = used[a];
	}
}

void build_LCA(){
	for (int j = 1; j <= 17; j++)
		for (int i = 1; i <= N; i++)
			if (i == used[i])
				up[i][j] = up[up[i][j-1]][j-1];
}

void DFS(int v,int p){
	dp[v] = dp[p] + marked[v];
	lvl[v] = lvl[p] + 1;
	up[v][0] = p;
	for(int i = 0; i < G[v].size(); i++){
		int a = G[v][i];
		if (a == p) continue;
		DFS (a, v);
	}
}

int LCA_part(int v,int k){
	for(int i = 0; i <= 17; i++){
		if(k & 1) v = up[v][i];
		k >>= 1;
	}
	return v;
}

int LCA(int a,int b){
	if(lvl[a] > lvl[b]) a = LCA_part(a, lvl[a] - lvl[b]);
	else b = LCA_part(b, lvl[b] - lvl[a]);
	if(a==b) return a;
	for(int i = 17; i >= 0; i--){
		if(up[a][i] != up[b][i]){
			a = up[a][i];
			b = up[b][i];
		}
	}
	return up[a][0];
}


int Pow(int a, int b){
	int ans = 1, t = a;
	while(b){
		if(b & 1){
			ans *= t;
			ans %= MOD;
		}
		t *= t;
		t %= MOD;
		b >>= 1;
	}
	return ans;
}


main(){
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
	N = readInt(), M = readInt();
	for(int i = 0; i < M; i++){
		int x = readInt(), y = readInt();
		g[x].push_back(y);
		g[y].push_back(x);
		edge[i] = make_pair(x,y);
	}
	dfs(1,1);
	for(int i = 1;i <= N; i++) {
		if(used[i] != i) {
			marked[used[i]] = true;
		}
	}
	for(int i = 0;i < M; i++){
		int x = used[edge[i].first];
		int y = used[edge[i].second];
		if(x != y){
			G[x].push_back(y);
			G[y].push_back(x);
		}
	}
	DFS(1,1);
	build_LCA();
	int t = readInt();
	while(t--) {
		int a = readInt(), b = readInt();
		int A = used[a];
		int B = used[b];
		int L = LCA(A,B);
		int ans = dp[A] + dp[B] - 2 * dp[L] + marked[L];
		cout << Pow(2, ans) << endl;;
	}
}