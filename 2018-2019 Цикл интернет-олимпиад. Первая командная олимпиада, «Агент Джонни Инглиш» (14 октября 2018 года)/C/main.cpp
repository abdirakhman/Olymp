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

const long long MOD = 1e15;
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
map <string, int> maps;


int timer = 0;

int getid(string s) {
	if (!maps.count(s)) {
		timer ++;
		return maps[s] = timer;		
	}
	return maps[s];
}


const int N = 111;

int used[N];
vector <int> g[N];



int cost[N];
int a[N];

void dfs(int v) {
	used[v] = 1;
	int sum = 0;
	if (g[v].size() == 0) {
		return;	
	}
	for (int i : g[v]) {
		if (used[i]) {
			sum += cost[i];			
		} else {
			dfs(i);
			sum += cost[i];
		}
	}
	if (sum < cost[v]) {
		cost[v] = sum;	
	}
}

 main() {
	#ifdef IZI_KATKA
	assert(freopen("input", "r", stdin));
    assert(freopen("output", "w", stdout));
    #endif
	int n = readInt();
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		a[i] = getid(s);
	}
	for (int i = 1; i <= 101; i++) {
		cost[i] = MOD;
	}
	int m = readInt();
	for (int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		cost[getid(s)] = readInt();
	}                   
	int k = readInt();
	for (int i = 1; i <= k; i++) {
		int sz = readInt();
		string s;
		cin >> s;	
		for (int j = 1; j <= sz; j++) {
			string tmp;
			cin >> tmp;
			g[getid(s)].pb(getid(tmp));
		}                     
	}
	for (int i = 1; i <= 101; i++) {
		if (!used[i])
			dfs(i);	
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += cost[a[i]];
	}
	cout << (sum >= MOD ? -1 : sum);
    return 0;
}