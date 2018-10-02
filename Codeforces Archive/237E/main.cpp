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


struct edge {
  int from, to, flow, cap, cost;
};

string s[MAXN];
int a[MAXN];

int d[MAXN];
int p[MAXN];

int cnt[MAXN][27];

int C[MAXN][27];

vector<edge> e;
vector<int> g[MAXN];
int S, T;
string t;



void addEdge(int u, int v, int cap, int cost) {
  	g[u].pb(e.size());
  	e.pb({u, v, 0, cap, cost});
  	g[v].pb(e.size());
  	e.pb({v, u, 0, 0, -cost});
}


bool fordBellman() {
	for (int i = S; i <= T; i++) {
		d[i] = MOD;
	}
	d[S] = 0;
	queue <int> Q;
	Q.push(S);
	while(!Q.empty()) {
		int v = Q.front();
		Q.pop();
		for (auto i : g[v]) {
      		if (e[i].flow < e[i].cap && d[e[i].to] > d[v] + e[i].cost) {
        		d[e[i].to] = d[v] + e[i].cost;
        		p[e[i].to] = i;
        		Q.push(e[i].to);
      		}
    	}
	}   	
	return d[T] != MOD;
}

long long minCostMaxFlow() {
	int maxFlow = 0;
	long long minCost = 0;
	while (true) {
		if (!fordBellman()) break;
		vector<int> path;
		for (int i = T; i != S; i = e[p[i]].from)
			path.pb(p[i]);
    	int push = MOD;
    	for (auto it : path)
      		push = min(push, e[it].cap - e[it].flow);
    	maxFlow += push;
    	for (auto &it : path) {
      		minCost += 1ll * push * e[it].cost;
      		e[it].flow += push;
      		e[it ^ 1].flow -= push;
    	}
  	}
  	if (maxFlow != t.size()) {
		return -1;
	} else {
    	return minCost;
  	}
}


int main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
    cin >> t;
    for (int i : t) {
    	cnt[0][i - 'a']++;
    }
    int n = readInt();
    S = 0;
    for (int i = 0; i < 26; i++) {
    	addEdge(S, i + 1, cnt[0][i], 0);
    }
    T = n + 27;
    for (int i = 1; i <= n; i++) {
		cin >> s[i];
		a[i] = readInt();
    	for (int j : s[i]) {
    		cnt[i][j - 'a']++;
    	}
    	for (int j = 0; j < 26; j++)
      		addEdge(j + 1, i + 26, cnt[i][j], i);
	    addEdge(i + 26, T, a[i], 0);
    }
	cout << minCostMaxFlow();
    return 0;
}