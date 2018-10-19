/*
Instead of increasing radius of visitor increase radius of trees.
Now we can find max radius that cannot block for each side.
By binary search or MST.
*/
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
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, m, w, h;
int x[2005], y[2005], r[2005];
int g[2005][2005];
int D[2005][2005], ans[4][4];

vector<int> G[2005];

struct edg{int s, e, x;};
vector<edg> v;

void dfs(int x, int p, int s, int v){
	D[s][x] = v;
	for(auto &i : G[x]){
		if(i == p) continue;
		dfs(i, x, s, max(v, g[x][i]));
	}
}

struct disj{
	int pa[2055];
	void init(int n){
		for(int i=0; i<=n; i++) pa[i] = i;
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p), q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

int main(){
	cin >> n >> m >> w >> h;
	for (int i = 0; i < n; i++){
		cin >> x[i] >> y[i] >> r[i];
	}
	for (int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(i == j) continue;
			double dist = hypot(x[j] - x[i], y[j] - y[i]) - r[i] - r[j];
			g[i][j] = g[j][i] = (int)floor(dist / 2 + 1e-10);
		}
	}
	for (int i = 0; i<n; i++){
		g[i][n] = g[n][i] = (y[i] - r[i]) / 2;
		g[i][n+1] = g[n+1][i] = (x[i] - r[i]) / 2;
		g[i][n+2] = g[n+2][i] = (w - r[i] - x[i]) / 2;
		g[i][n+3] = g[n+3][i] = (h - r[i] - y[i]) / 2;
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(i != j) g[n+i][n+j] = 1e9;
		}
	}
	for(int i=0; i<n+4; i++){
		for(int j=0; j<i; j++){
			v.push_back({i, j, g[i][j]});
		}
	}
	sort(v.begin(), v.end(), [&](const edg &a, const edg &b){
		return a.x < b.x;
	});
	disj.init(n+4);
	for(auto &i : v){
		if(disj.uni(i.s, i.e)){
			G[i.s].push_back(i.e);
			G[i.e].push_back(i.s);
		}
	}
	for(int i=n; i<n+4; i++){
		dfs(i, -1, i, 0);
	}
	ans[0][0] = ans[1][1] = ans[2][2] = ans[3][3] = 1e9;
	ans[0][1] = ans[1][0] = min(D[n][n+1], min(D[n][n+2], D[n][n+3]));
	ans[0][2] = ans[2][0] = min(min(D[n][n+1], D[n][n+3]), min(D[n+2][n+1], D[n+2][n+3]));
	ans[0][3] = ans[3][0] = min(D[n+1][n], min(D[n+1][n+2], D[n+1][n+3]));
	ans[1][2] = ans[2][1] = min(D[n+2][n], min(D[n+2][n+1], D[n+2][n+3]));
	ans[1][3] = ans[3][1] = min(min(D[n][n+2], D[n][n+3]), min(D[n+1][n+2], D[n+1][n+3]));
	ans[2][3] = ans[3][2] = min(D[n+3][n], min(D[n+3][n+1], D[n+3][n+2]));
	while(m--){
		int s, d;
		scanf("%d %d",&d, &s);
		for(int i=0; i<4; i++){
			if(ans[s-1][i] >= d){
				putchar(i + '1');
			}
		}
		puts("");
	}
}